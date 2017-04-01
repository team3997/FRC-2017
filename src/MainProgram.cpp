#include "WPILib.h"
#include "RobotModel.h"
#include "RemoteControl.h"
#include "ControlBoard.h"
#include "DashboardLogger.h"
#include "LightsController.h"
#include "ClimberController.h"
#include "DriveController.h"
#include "VisionController.h"
#include "GearController.h"
#include <string.h>
#include "Auto/Auto.h"

class MainProgram : public frc::IterativeRobot {

    //Creates a robot from class RobotModel
    RobotModel *robot;

    //Creates a human control from RemoteControl, which includes ControlBoard
    RemoteControl *humanControl;
    VisionController *visionController;

    //Creates a controller for drivetrain and superstructure
    DriveController *driveController;

    //Creates an object of Dashboardlogger
    DashboardLogger *dashboardLogger;

    ClimberController *climberController;
    LightsController* lights;

    GearController *gearController;
    Auto* auton;
    CameraServer *camera;


    //LightsController *lights;

    //Creates a time-keeper	`
    double currTimeSec;
    double lastTimeSec;
    double deltaTimeSec;

 public:
    MainProgram(void) {
        robot = new RobotModel();
        humanControl = new ControlBoard();
        lights = new LightsController(humanControl);
        visionController = new VisionController();
        driveController = new DriveController(robot, humanControl, visionController);
        dashboardLogger = new DashboardLogger(robot, humanControl);
        climberController = new ClimberController(robot, humanControl);
        gearController = new GearController(robot, humanControl);
        auton = new Auto(visionController, driveController, robot, gearController, lights);
        //lights            = new LightsController(humanControl);
        //Initializes timekeeper variables
        currTimeSec = 0.0;
        lastTimeSec = 0.0;
        deltaTimeSec = 0.0;
    }
 private:
    void RobotInit() {
        RefreshAllIni();
        robot->ResetTimer();
        robot->Reset();
        auton->ListOptions();
        visionController->Disable();
        camera = CameraServer::GetInstance();

        camera->StartAutomaticCapture();
    }

    void AutonomousInit() {
        auton->Stop();
        RefreshAllIni();
        robot->ResetTimer();
        robot->ResetEncoders();

        driveController->Reset();

        //Resets timer variables
        currTimeSec = 0.0;
        lastTimeSec = 0.0;
        deltaTimeSec = 0.0;

        visionController->Enable();
        auton->Start();

    }

    void AutonomousPeriodic() {
        //Autonoumous is running in a thread called by "auton->Start();"
        dashboardLogger->UpdateData();  //JOystick data does NOT update during autonomous
        visionController->Update();
        //lights->Update(true);
    }

    void TeleopInit() {
        lights->SetEnabledRoutine();
        auton->Stop();
        RefreshAllIni();
        robot->ResetTimer();
        robot->ResetEncoders();

        driveController->Reset();
        climberController->Reset();

        //Resets timer variables
        currTimeSec = 0.0;
        lastTimeSec = 0.0;
        deltaTimeSec = 0.0;

        visionController->Enable();
    }

    void TeleopPeriodic() {
        dashboardLogger->UpdateData();

        //Updates timer
        lastTimeSec = currTimeSec;
        currTimeSec = robot->GetTime();
        deltaTimeSec = currTimeSec - lastTimeSec;


        //Reads controls and updates controllers accordingly
        //RefreshAllIni();
        humanControl->ReadControls();
        driveController->Update(currTimeSec, deltaTimeSec);
        climberController->Update();
        visionController->Update();
        gearController->Update();

        if (humanControl->GetJoystickValue(RemoteControl::kOperatorJoy, RemoteControl::kRY) > 0.2) {
        lights->Climbing();
        } else if (humanControl->GetShoutRoutineDesired()) {
        lights->SetShoutRoutine();
        } else if (humanControl->GetGearTitlerIntakeDesired()) {
        lights->GearIntake();

        } else if (humanControl->GetGearTitlerOuttakeDesired()) {
        lights->GearOuttake();

        } else if (humanControl->GetSlowDriveTier1Desired()
                && humanControl->GetSlowDriveTier2Desired()) {
        lights->Brake2();

        } else if (humanControl->GetSlowDriveTier1Desired()) {
        lights->Brake1();

        } else {
        lights->SetEnabledRoutine();
        }
    }

    void DisabledInit() {
        auton->Stop();

        RefreshAllIni();

        robot->ResetEncoders();
        driveController->Reset();
        climberController->Reset();
        visionController->Disable();
        lights->SetDisabledRoutine();
    }

    void DisabledPeriodic() {

        dashboardLogger->UpdateData();
        //robot->UpdateCurrent();
        //auton->Stop();
        //Reads controls and updates controllers accordingly

        //lights->Update(false);
        visionController->Update();
        humanControl->ReadControls();
        gearController->Update();
        RefreshAllIni();
    }
    void RefreshAllIni() {
        robot->RefreshIni();
    }
};

START_ROBOT_CLASS(MainProgram);

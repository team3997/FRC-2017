/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011-2017. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <memory>
#include <string>
#include "WPILib.h"
#include "SmartDashboard/SendableChooserBase.h"
#include "llvm/StringMap.h"
#include "llvm/StringRef.h"
#include "tables/ITable.h"

namespace frc {

/**
 * The {@link AutoWidget} class is a useful tool for presenting a selection
 * of options to the {@link SmartDashboard}.
 *
 * <p>For instance, you may wish to be able to select between multiple
 * autonomous modes. You can do this by putting every possible {@link Command}
 * you want to run as an autonomous into a {@link AutoWidget} and then put
 * it into the {@link SmartDashboard} to have a list of options appear on the
 * laptop.  Once autonomous starts, simply ask the {@link AutoWidget} what
 * the selected value is.</p>
 *
 * @tparam T The type of values to be stored
 * @see SmartDashboard
 */
class AutoWidget: public SendableChooserBase {
public:
  virtual ~AutoWidget() = default;

  void AddObject(llvm::StringRef name, int routine);
  void AddDefault(llvm::StringRef name, int defaultRoutine);
  int GetSelected();

  void InitTable(std::shared_ptr<ITable> subtable) override;

private:
  llvm::StringMap<int> m_choices;
};
}  // namespace frc


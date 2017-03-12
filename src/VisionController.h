/*
 * VisionController.h
 *
 *  Created on: Mar 8, 2017
 *      Author: michael
 */

#ifndef SRC_VISIONCONTROLLER_H_
#define SRC_VISIONCONTROLLER_H_

class VisionController {
public:
	VisionController();
	virtual ~VisionController();
	void Enable();
	void Disable();
	bool isEnabled();
	void Update();
	void Reset();

	double GetLeftContour();
	double GetRightContour();

private:
	bool is_enabled;
	int left_contour, right_contour;
};

#endif /* SRC_VISIONCONTROLLER_H_ */

#include <iostream>
#include "calibration.h"
#include "camera.h"


int main(int argc, char **argv)
{
    Camera* cam = new Camera();
    Calibration* calib = new Calibration();
    calib->setCamera(cam);
    calib->calibrate();

//    std::cout << cam->K_ << std::endl;
//    std::cout << cam->D_ << std::endl;

    delete calib;
    delete cam;

	return 0;
}

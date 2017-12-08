#include <iostream>
#include "calibration.h"
#include "camera.h"


int main(int argc, char **argv)
{
    std::cout << "**** Starting Calibration ****" << std::endl;

    Camera* cam = new Camera();
    Calibration* calib = new Calibration();

    delete calib;
    delete cam;

	return 0;
}

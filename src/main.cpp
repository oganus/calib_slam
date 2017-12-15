#include <iostream>
#include "oslam.h"


using namespace std;


int main(int argc, char **argv)
{
    if(argc != 3)
    {
        cerr << endl << "Usage: " << argv[0] << " path_to_vocabulary path_to_settings path_to_sequence" << endl;
        return 1;
    }

    OSLAM* slam = new OSLAM(argv);
    slam->run();

    return 0;
}


// #include <iostream>
// #include "calibration.h"
// #include "camera.h"

// int main(int argc, char **argv)
// {
//     Camera* cam = new Camera();
//     Calibration* calib = new Calibration();
//     calib->setCamera(cam);
//     calib->calibrate();

// //    std::cout << cam->K_ << std::endl;
// //    std::cout << cam->D_ << std::endl;

//     calib->save("VX800.yaml");

//     delete calib;
//     delete cam;

// 	return 0;
// }

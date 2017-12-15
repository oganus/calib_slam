#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>

#include <opencv2/core/core.hpp>

#include <System.h>

using namespace std;

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        cerr << endl << "Usage: " << argv[0] << " path_to_vocabulary path_to_settings path_to_sequence" << endl;
        return 1;
    }

    const string strVocFile = argv[1];
    const string strSettingsFile = argv[2];

    // Create SLAM system. It initializes all system threads and gets ready to process frames.
    ORB_SLAM2::System SLAM(strVocFile,strSettingsFile,ORB_SLAM2::System::MONOCULAR,true);

    // create a video stream of the webcam
    cv::VideoCapture stream(1);
    if (!stream.isOpened()) { //check if video device has been initialised
    std::cout << "cannot open camera" << std::endl;
    }

    // Main loop
    cv::Mat im;
    while (true) {
        stream.read(im);
        double tframe = cv::getTickCount()/10000.0;

        // Pass the image to the SLAM system
        SLAM.TrackMonocular(im,tframe);
    }

    // Stop all threads
    SLAM.Shutdown();

    // Save camera trajectory
    SLAM.SaveKeyFrameTrajectoryTUM("KeyFrameTrajectory.txt");

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

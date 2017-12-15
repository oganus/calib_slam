#include "oslam.h"

#include <algorithm>
#include <fstream>
#include <chrono>

#include <opencv2/core/core.hpp>

#include <System.h>

using namespace std;

void OSLAM::run() {
    const string strVocFile = _argv[1];
    const string strSettingsFile = _argv[2];

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
}
// #include <iostream>
// #include <algorithm>
// #include <fstream>
// #include <chrono>

// #include <opencv2/core/core.hpp>

// #include <System.h>

// using namespace std;

// void LoadImages(const string &strFile, vector<string> &vstrImageFilenames,
//                 vector<double> &vTimestamps);

// int main(int argc, char **argv)
// {
//     if(argc != 4)
//     {
//         cerr << endl << "Usage: ./mono_tum path_to_vocabulary path_to_settings path_to_sequence" << endl;
//         return 1;
//     }

//     // Retrieve paths to images
//     vector<string> vstrImageFilenames;
//     vector<double> vTimestamps;
//     string strFile = string(argv[3])+"/rgb.txt";
//     LoadImages(strFile, vstrImageFilenames, vTimestamps);

//     int nImages = vstrImageFilenames.size();

//     // Create SLAM system. It initializes all system threads and gets ready to process frames.
//     ORB_SLAM2::System SLAM(argv[1],argv[2],ORB_SLAM2::System::MONOCULAR,true);

//     // Vector for tracking time statistics
//     vector<float> vTimesTrack;
//     vTimesTrack.resize(nImages);

//     cout << endl << "-------" << endl;
//     cout << "Start processing sequence ..." << endl;
//     cout << "Images in the sequence: " << nImages << endl << endl;

//     // create a video stream of the webcam
//     cv::VideoCapture stream(1);
//     if (!stream.isOpened()) { //check if video device has been initialised
//     std::cout << "cannot open camera" << std::endl;
//     }

//     // Main loop
//     cv::Mat im;
// //    int ni = 0; // image number
//     while (true) {
//         stream.read(im);
//         cv::imshow("cam", im);
//         cv::waitKey(30);
//         double tframe = cv::getTickCount()/10000.0;

// //        std::cout << "time = " << tframe << std::endl;

// //#ifdef COMPILEDWITHC11
// //        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
// //#else
// //        std::chrono::monotonic_clock::time_point t1 = std::chrono::monotonic_clock::now();
// //#endif

//         // Pass the image to the SLAM system
//         SLAM.TrackMonocular(im,tframe);

// //#ifdef COMPILEDWITHC11
// //        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
// //#else
// //        std::chrono::monotonic_clock::time_point t2 = std::chrono::monotonic_clock::now();
// //#endif
//     }

//     // Stop all threads
//     SLAM.Shutdown();

//     // Tracking time statistics
// //    sort(vTimesTrack.begin(),vTimesTrack.end());
// //    float totaltime = 0;
// //    for(int ni=0; ni<nImages; ni++)
// //    {
// //        totaltime+=vTimesTrack[ni];
// //    }
// //    cout << "-------" << endl << endl;
// //    cout << "median tracking time: " << vTimesTrack[nImages/2] << endl;
// //    cout << "mean tracking time: " << totaltime/nImages << endl;

//     // Save camera trajectory
//     SLAM.SaveKeyFrameTrajectoryTUM("KeyFrameTrajectory.txt");

//     return 0;
// }

// void LoadImages(const string &strFile, vector<string> &vstrImageFilenames, vector<double> &vTimestamps)
// {
//     ifstream f;
//     f.open(strFile.c_str());

//     // skip first three lines
//     string s0;
//     getline(f,s0);
//     getline(f,s0);
//     getline(f,s0);

//     while(!f.eof())
//     {
//         string s;
//         getline(f,s);
//         if(!s.empty())
//         {
//             stringstream ss;
//             ss << s;
//             double t;
//             string sRGB;
//             ss >> t;
//             vTimestamps.push_back(t);
//             ss >> sRGB;
//             vstrImageFilenames.push_back(sRGB);
//         }
//     }
// }


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

    calib->save("VX800.yaml");

    delete calib;
    delete cam;

	return 0;
}

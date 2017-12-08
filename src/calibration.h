#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

/**
 * \brief	Checkerboard Calibration
 * \author	Oleksandra Ganus
 **/

class Calibration
{
public:
    Calibration();
//    void setup_calibration(int board_width, int board_height, int num_imgs,
//                           float square_size, char* imgs_directory, char* imgs_filename,
//                           char* extension);

//    double computeReprojectionErrors(const vector< vector< Point3f > >& objectPoints,
//                                     const vector< vector< Point2f > >& imagePoints,
//                                     const vector< Mat >& rvecs, const vector< Mat >& tvecs,
//                                     const Mat& cameraMatrix , const Mat& distCoeffs);

    int calibrate();

    int board_n_;
    cv::Size board_size_;
    int board_width_;
    int board_height_;
    int num_imgs_;
    float square_size_;
    char* imgs_directory_;
    char* imgs_filename_;
    char* extension_;
    cv::Mat img_;
    cv::Mat gray_;
    cv::Size img_size_;
    std::vector< std::vector< cv::Point3f > > object_points_;
    std::vector< std::vector< cv::Point2f > > image_points_;
    std::vector< cv::Point2f > corners_;
};

#endif

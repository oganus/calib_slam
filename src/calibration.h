#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "camera.h"

/**
 * \brief	Checkerboard Calibration
 * \author	Oleksandra Ganus
 **/

class Calibration
{
public:
    Calibration();
    void setCamera(Camera* cam) { cam_ = cam; }
    void setup_calibration();
    double computeReprojectionErrors();
    void calibrate();
    void save(const std::string&);

private:
        Camera* cam_;
        std::vector< cv::Mat > img_vec_;
        int board_n_;
        cv::Size board_size_;
        int board_width_;
        int board_height_;
        int num_imgs_;
        float square_size_;
        cv::Mat img_;
        cv::Mat gray_; // not needed as field
        cv::Size img_size_;
        std::vector< std::vector< cv::Point3f > > object_points_;
        std::vector< std::vector< cv::Point2f > > image_points_;
        std::vector< cv::Point2f > corners_;
        cv::Mat K_;
        cv::Mat D_;
        std::vector< cv::Mat > rvecs_, tvecs_;
};

#endif

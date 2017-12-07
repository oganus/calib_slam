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

    std::vector< std::vector< cv::Point3f > > object_points;
    std::vector< std::vector< cv::Point2f > > image_points;
    std::vector< cv::Point2f > corners;
};

#endif

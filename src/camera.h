#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/highgui/highgui.hpp>

/**
 * \brief	Camera settings
 * \author	Oleksandra Ganus
 **/

class Camera
{
public:
    Camera();

    std::vector<cv::Mat> img_vec_;
};

#endif

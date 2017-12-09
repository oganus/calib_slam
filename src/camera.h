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

    std::vector<cv::Mat> getImg() { return img_vec_; }
    void setIntrinsics(cv::Mat K, cv::Mat D) { K_ = K; D_ = D; }

private:
    std::vector<cv::Mat> img_vec_;
    cv::Mat K_;
    cv::Mat D_;
};

#endif

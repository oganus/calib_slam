#include <iostream>
#include "camera.h"

Camera::Camera()
{
    cv::VideoCapture stream(1);

    if (!stream.isOpened()) { //check if video device has been initialised
    std::cout << "cannot open camera" << std::endl;
    }

    int count = 0;
    //unconditional loop
    while (true) {
        cv::Mat cameraFrame;
        stream.read(cameraFrame);
        cv::imshow("cam", cameraFrame);
        cv::waitKey(30);

        if (count % 10 == 0)
        {
            img_vec_.push_back(cameraFrame);
            std::cout << "Number of saved images = " << img_vec_.size() << std::endl;
        }

        if (img_vec_.size() == 50)
                break;

        count++;
    }
}

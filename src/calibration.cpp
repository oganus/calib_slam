#include "calibration.h"

Calibration::Calibration() {}

void Calibration::setup_calibration()
{
    board_width_ = 9;
    board_height_ = 6;
    square_size_ = 35; // 35 mm

    board_size_ = cv::Size(board_width_, board_height_);
    board_n_ = board_width_ * board_height_;

    img_vec_ = cam_->getImg();
    num_imgs_ = img_vec_.size();

    for (int k = 0; k < num_imgs_; k++) {
        img_ = img_vec_[k];
        cv::cvtColor(img_, gray_, CV_BGR2GRAY);

        bool found = false;
        found = cv::findChessboardCorners(img_, board_size_, corners_,
                                          CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);
        if (found)
        {
          cornerSubPix(gray_, corners_, cv::Size(5, 5), cv::Size(-1, -1),
                       cv::TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
          drawChessboardCorners(gray_, board_size_, corners_, found);
        }

        std::vector< cv::Point3f > obj;
        for (int i = 0; i < board_height_; i++)
          for (int j = 0; j < board_width_; j++)
            obj.push_back(cv::Point3f((float)j * square_size_, (float)i * square_size_, 0));

        if (found) {
          std::cout << k << ". Found corners!" << std::endl;
          image_points_.push_back(corners_);
          object_points_.push_back(obj);
        }
    }
}


double Calibration::computeReprojectionErrors()
{
  std::vector< cv::Point2f > imagePoints2;
  int i, totalPoints = 0;
  double totalErr = 0, err;
  std::vector< float > perViewErrors;
  perViewErrors.resize(object_points_.size());

  for (i = 0; i < (int)object_points_.size(); ++i) {
    projectPoints(cv::Mat(object_points_[i]), rvecs_[i], tvecs_[i], K_,
                  D_, imagePoints2);
    err = norm(cv::Mat(image_points_[i]), cv::Mat(imagePoints2), CV_L2);
    int n = (int)object_points_[i].size();
    perViewErrors[i] = (float) std::sqrt(err*err/n);
    totalErr += err*err;
    totalPoints += n;
  }
  return std::sqrt(totalErr/totalPoints);
}


void Calibration::calibrate()
{
    setup_calibration();

    printf("Starting Calibration\n");

    int flag = 0;
    //flag |= CV_CALIB_FIX_K4;
    //flag |= CV_CALIB_FIX_K5;
    cv::calibrateCamera(object_points_, image_points_, img_vec_[0].size(), K_, D_, rvecs_, tvecs_, flag);

    std::cout << "image size = " << img_vec_[0].size() << std::endl;
    std::cout <<"K = " << K_ << std::endl;
    std::cout <<"D = " << D_ << std::endl;

    std::cout << "Calibration error: "
              << computeReprojectionErrors()
              << std::endl;

    cam_->setIntrinsics(K_,D_);

    printf("Done Calibration\n");
}

#include "calibration.h"

Calibration::Calibration()
{

}

//void Calibration::setup_calibration(int board_width, int board_height, int num_imgs,
//                       float square_size, char* imgs_directory, char* imgs_filename,
//                       char* extension) {
//        board_size_ = cv::Size(board_width_, board_height_);
//        board_n_ = board_width_ * board_height_;

//        for (int k = 1; k <= num_imgs_; k++) {
//        char img_file[100];
//        sprintf(img_file, "%s%s%d.%s", imgs_directory, imgs_filename, k, extension);
//        img_ = imread(img_file, CV_LOAD_IMAGE_COLOR);
//        cv::cvtColor(img_, gray_, CV_BGR2GRAY);

//        bool found = false;
//        found = cv::findChessboardCorners(img_, board_size_, corners,
//                                          CV_CALIB_CB_ADAPTIVE_THRESH | CV_CALIB_CB_FILTER_QUADS);
//        if (found)
//        {
//          cornerSubPix(gray_, corners, cv::Size(5, 5), cv::Size(-1, -1),
//                       cv::TermCriteria(CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 30, 0.1));
//          drawChessboardCorners(gray_, board_size_, corners, found);
//        }

//        std::vector< cv::Point3f > obj;
//        for (int i = 0; i < board_height_; i++)
//          for (int j = 0; j < board_width_; j++)
//            obj.push_back(cv::Point3f((float)j * square_size_, (float)i * square_size_, 0));

//        if (found) {
//          std::cout << k << ". Found corners!" << std::endl;
//          image_points_.push_back(corners);
//          object_points_.push_back(obj);
//        }
//        }
//}


//double Calibration::computeReprojectionErrors(const vector< vector< Point3f > >& objectPoints,
//                                 const vector< vector< Point2f > >& imagePoints,
//                                 const vector< Mat >& rvecs, const vector< Mat >& tvecs,
//                                 const Mat& cameraMatrix , const Mat& distCoeffs) {
//  vector< Point2f > imagePoints2;
//  int i, totalPoints = 0;
//  double totalErr = 0, err;
//  vector< float > perViewErrors;
//  perViewErrors.resize(objectPoints.size());

//  for (i = 0; i < (int)objectPoints.size(); ++i) {
//    projectPoints(Mat(objectPoints[i]), rvecs[i], tvecs[i], cameraMatrix,
//                  distCoeffs, imagePoints2);
//    err = norm(Mat(imagePoints[i]), Mat(imagePoints2), CV_L2);
//    int n = (int)objectPoints[i].size();
//    perViewErrors[i] = (float) std::sqrt(err*err/n);
//    totalErr += err*err;
//    totalPoints += n;
//  }
//  return std::sqrt(totalErr/totalPoints);
//}


//int Calibration::calibrate()
//{
//  int board_width, board_height, num_imgs;
//  float square_size;
//  char* imgs_directory;
//  char* imgs_filename;
//  char* out_file;
//  char* extension;

//  static struct poptOption options[] = {
//    { "board_width",'w',POPT_ARG_INT,&board_width,0,"Checkerboard width","NUM" },
//    { "board_height",'h',POPT_ARG_INT,&board_height,0,"Checkerboard height","NUM" },
//    { "num_imgs",'n',POPT_ARG_INT,&num_imgs,0,"Number of checkerboard images","NUM" },
//    { "square_size",'s',POPT_ARG_FLOAT,&square_size,0,"Size of checkerboard square","NUM" },
//    { "imgs_directory",'d',POPT_ARG_STRING,&imgs_directory,0,"Directory containing images","STR" },
//    { "imgs_filename",'i',POPT_ARG_STRING,&imgs_filename,0,"Image filename","STR" },
//    { "extension",'e',POPT_ARG_STRING,&extension,0,"Image extension","STR" },
//    { "out_file",'o',POPT_ARG_STRING,&out_file,0,"Output calibration filename (YML)","STR" },
//    POPT_AUTOHELP
//    { NULL, 0, 0, NULL, 0, NULL, NULL }
//  };

//  POpt popt(NULL, argc, argv, options, 0);
//  int c;
//  while((c = popt.getNextOpt()) >= 0) {}

//  setup_calibration(board_width, board_height, num_imgs, square_size,
//                   imgs_directory, imgs_filename, extension);

//  printf("Starting Calibration\n");
//  Mat K;
//  Mat D;
//  vector< Mat > rvecs, tvecs;
//  int flag = 0;
//  flag |= CV_CALIB_FIX_K4;
//  flag |= CV_CALIB_FIX_K5;
//  calibrateCamera(object_points, image_points, img.size(), K, D, rvecs, tvecs, flag);

//  cout << "Calibration error: " << computeReprojectionErrors(object_points, image_points, rvecs, tvecs, K, D) << endl;

//  FileStorage fs(out_file, FileStorage::WRITE);
//  fs << "K" << K;
//  fs << "D" << D;
//  fs << "board_width" << board_width;
//  fs << "board_height" << board_height;
//  fs << "square_size" << square_size;
//  printf("Done Calibration\n");
//}

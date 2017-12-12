cmake_minimum_required(VERSION 2.6)

project(calib_slam)

file(GLOB_RECURSE includes src/*.h)
file(GLOB_RECURSE sources src/*.cpp)

set(CMAKE_BUILD_TYPE Release)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Set path for opencv
set(OpenCV_INCLUDE /usr/include/opencv)
set(OpenCV_LIBS /usr/lib/x86_64-linux-gnu/)

include_directories(${OpenCV_INCLUDE})
link_directories(${OpenCV_LIBS})
link_libraries(opencv_calib3d opencv_contrib opencv_core opencv_features2d opencv_flann opencv_highgui opencv_imgproc opencv_objdetect opencv_ocl opencv_photo opencv_stitching opencv_superres opencv_video)
# Set some default flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(${PROJECT_NAME} ${sources})

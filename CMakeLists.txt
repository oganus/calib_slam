CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(RecordData)

FILE(GLOB_RECURSE includes src/*.h)
FILE(GLOB_RECURSE sources src/*.cpp)

SET(CMAKE_BUILD_TYPE Release)
MESSAGE(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Set path for opencv
SET(OpenCV_INCLUDE /usr/include/opencv)
SET(OpenCV_LIBS /usr/lib/x86_64-linux-gnu/)

include_directories(${OpenCV_INCLUDE} ${INCLUDES_DIRECTORY})
link_directories(${OpenCV_LIBS})
link_libraries(opencv_calib3d opencv_contrib opencv_core opencv_features2d opencv_flann opencv_highgui opencv_imgproc opencv_objdetect opencv_ocl opencv_photo opencv_stitching opencv_superres opencv_video)
# Set some default flags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(${PROJECT_NAME} ${sources})
# Include Directories

target_link_libraries(${PROJECT_NAME})

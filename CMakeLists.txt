cmake_minimum_required(VERSION 2.6)
project(calib_slam)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Set compilation flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall  -O3 -march=native ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall   -O3 -march=native")

# Check C++11 or C++0x support
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
   add_definitions(-DCOMPILEDWITHC11)
   message(STATUS "Using flag -std=c++11.")
elseif(COMPILER_SUPPORTS_CXX0X)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
   add_definitions(-DCOMPILEDWITHC0X)
   message(STATUS "Using flag -std=c++0x.")
else()
   message(FATAL_ERROR "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# Find packages
find_package(OpenCV 3.0 QUIET)
if(NOT OpenCV_FOUND)
   find_package(OpenCV 2.4.3 QUIET)
   if(NOT OpenCV_FOUND)
      message(FATAL_ERROR "OpenCV > 2.4.3 not found.")
   endif()
endif()

find_package(Eigen3 REQUIRED)
find_package(Pangolin REQUIRED)

set(ORB_SLAM2_PATH "" CACHE PATH "ORB_SLAM2 root")
set(ORB_SLAM2_INCLUDE "${ORB_SLAM2_PATH}/include")
set(ORB_SLAM2_LIBS "${ORB_SLAM2_PATH}/lib")

# Build app
file(GLOB_RECURSE includes src/*.h)
file(GLOB_RECURSE sources src/*.cpp)

include_directories(
    ${EIGEN3_INCLUDE_DIR}
    ${ORB_SLAM2_PATH}
    ${OpenCV_INCLUDE}
    ${ORB_SLAM2_INCLUDE})
link_directories(${ORB_SLAM2_LIBS})
link_libraries(
    ${OpenCV_LIBS}
    libORB_SLAM2.so
    ${Pangolin_LIBRARIES})
# Set some default flags
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(${PROJECT_NAME} ${sources})

cmake_minimum_required(VERSION 4.0)
project(opencv_webcam)

if(WIN32)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")
endif()

find_package(OpenCV REQUIRED)

add_executable(webcam webcam/webcam.cc)
target_link_libraries(webcam ${OpenCV_LIBS})
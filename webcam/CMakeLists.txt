cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Network Multimedia MultimediaWidgets)
qt_standard_project_setup()

if (MSVC)
  set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

include_directories(${CMAKE_SOURCE_DIR}/build/opencv/opencv-4.12.0/install/include)
link_directories(${CMAKE_SOURCE_DIR}/build/opencv/opencv-4.12.0/install/x64/vc17/staticlib)

#//////////////////////////
# Qt
# link with libraries
# lib_dep contains a cascade definition of all the libraries needed to link
#//////////////////////////

set(lib_dep ${lib_dep})
set(lib_dep ${lib_dep} Qt6::Widgets)
set(lib_dep ${lib_dep} Qt6::Network)
set(lib_dep ${lib_dep} Qt6::Multimedia)
set(lib_dep ${lib_dep} Qt6::MultimediaWidgets)

#//////////////////////////
# OpenCV
#//////////////////////////

if (MSVC)
  set(lib_dep ${lib_dep} IlmImfd.lib ippiwd.lib libpngd.lib opencv_calib3d4120d.lib opencv_flann4120d.lib opencv_imgproc4120d.lib opencv_stitching4120d.lib)
  set(lib_dep ${lib_dep} aded.lib ittnotifyd.lib libprotobufd.lib opencv_core4120d.lib  opencv_gapi4120d.lib opencv_ml4120d.lib  opencv_video4120d.lib)
  set(lib_dep ${lib_dep} ipphal.lib libjpeg-turbod.lib libtiffd.lib opencv_dnn4120d.lib opencv_highgui4120d.lib opencv_objdetect4120d.lib  opencv_videoio4120d.lib)
  set(lib_dep ${lib_dep} ippicvmt.lib libopenjp2d.lib libwebpd.lib opencv_features2d4120d.lib opencv_imgcodecs4120d.lib opencv_photo4120d.lib zlibd.lib)
endif()

#//////////////////////////
# Sources
#//////////////////////////

set(src ${src})
set(src ${src} main.cc)
set(src ${src} webcam.cc)
set(src ${src} webcam.h)

add_executable(webcam ${src})
target_link_libraries(webcam PRIVATE ${lib_dep})
set_target_properties(webcam PROPERTIES WIN32_EXECUTABLE ON MACOSX_BUNDLE ON)

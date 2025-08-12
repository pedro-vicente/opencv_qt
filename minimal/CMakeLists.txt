cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Network Multimedia MultimediaWidgets)
qt_standard_project_setup()

include_directories(${CMAKE_SOURCE_DIR}/build/opencv/opencv-4.12.0/install/include)

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

set(src ${src})
set(src ${src} main.cc)
set(src ${src} window.cc)
set(src ${src} window.h)

add_executable(minimal ${src})
target_link_libraries(minimal PRIVATE ${lib_dep})
set_target_properties(minimal PROPERTIES WIN32_EXECUTABLE ON MACOSX_BUNDLE ON)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT minimal)
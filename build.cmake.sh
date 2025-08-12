#!/bin/bash
mkdir -p build/opencv/opencv-4.12.0
pushd build
pushd opencv
pushd opencv-4.12.0

# opencv-4.12.0

cmake ../../../opencv/opencv-4.12.0 -DCMAKE_BUILD_TYPE=Debug \
    -DBUILD_SHARED_LIBS=OFF \
    -DBUILD_STATIC_LIBS=ON \
    -DBUILD_EXAMPLES=OFF \
    -DBUILD_TESTS=OFF \
    -DBUILD_PERF_TESTS=OFF 
echo "Press any key to continue..."
read -n 1 -s
cmake --build . --config Debug --target INSTALL
popd
popd
popd
pwd

# Qt

pushd build
cmake .. --fresh
cmake --build .
popd

pwd
#!/bin/bash

target_triplet=""
toolchain_path=$(pwd)"/vcpkg/scripts/buildsystems/vcpkg.cmake"

git clone https://github.com/Microsoft/vcpkg.git

./vcpkg/bootstrap-vcpkg.sh

if [ "$1" = "linux-x64" ]; then
    export VCPKG_TARGET_TRIPLET=x64-linux
    ./vcpkg/vcpkg integrate --triplet=x64-linux
    target_triplet="x64-linux"
fi

if [ "$1" = "linux-x86" ]; then
    export VCPKG_TARGET_TRIPLET=x86-linux
    ./vcpkg/vcpkg integrate --triplet=x86-linux
    target_triplet="x86-linux"
fi

if [ "$1" = "linux-arm" ]; then
    export VCPKG_TARGET_TRIPLET=arm-linux
    ./vcpkg/vcpkg integrate --triplet=arm-linux
    target_triplet="arm-linux"
fi

if [ "$1" = "windows-x64" ]; then
    export VCPKG_TARGET_TRIPLET=x64-windows
    ./vcpkg/vcpkg integrate --triplet=x64-windows
    target_triplet="x64-windows"
fi

if [ "$1" = "windows-x86" ]; then
    export VCPKG_TARGET_TRIPLET=x86-windows
    ./vcpkg/vcpkg integrate --triplet=x86-windows
    target_triplet="x86-windows"
fi

if [ "$1" = "windows-arm" ]; then
    export VCPKG_TARGET_TRIPLET=arm64-windows
    ./vcpkg/vcpkg integrate --triplet=arm64-windows
    target_triplet="arm64-windows"
fi

if [ "$1" = "macos-x64" ]; then
    export VCPKG_TARGET_TRIPLET=x64-osx
    ./vcpkg/vcpkg integrate --triplet=x64-osx
    target_triplet="x64-osx"
fi

if [ "$1" = "macos-arm" ]; then
    export VCPKG_TARGET_TRIPLET=arm64-osx-release
    ./vcpkg/vcpkg integrate --triplet=arm64-osx-release
    target_triplet="arm64-osx-release"
fi

./vcpkg/vcpkg install sfml:$target_triplet
./vcpkg/vcpkg integrate install
cmake -B build -S ./output/src/Client -DCMAKE_TOOLCHAIN_FILE=$toolchain_path -DVCPKG_TARGET_TRIPLET=$target_triplet
cmake --build build --config Release

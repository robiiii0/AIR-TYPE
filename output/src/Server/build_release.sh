#!/bin/bash

CURRENT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

mkdir "$CURRENT_DIR/release"

cmake -B "$CURRENT_DIR/release" -S "$CURRENT_DIR" "-DCMAKE_TOOLCHAIN_FILE=$CURRENT_DIR/../../../vcpkg/scripts/buildsystems/vcpkg.cmake" -DCMAKE_BUILD_TYPE=Release

cmake --build "$CURRENT_DIR/release"

ls -la

built=0

if [ ! -e "$CURRENT_DIR/release/Debug/r-type_server" ]; then
  echo "Linux/Mac Server binary is missing"
else
  echo "Linux/Mac Server binary is present"
  built=built+1
  mv "$CURRENT_DIR/release/Debug/r-type_server" "$CURRENT_DIR../../release/r-type_server"
fi

if [ ! -e "$CURRENT_DIR/release/Debug/r-type_server.exe" ]; then
  echo "Windows Server binary is missing"
else
  echo "Windows Server binary is present"
  built=built+1
  mv "$CURRENT_DIR/release/Debug/r-type_server.exe" "$CURRENT_DIR../../release/r-type_server.exe"
fi

if [ $built -eq 0 ]; then
  echo "Server Compilation failed"
  exit 1
fi

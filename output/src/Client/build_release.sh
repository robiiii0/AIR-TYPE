#!/bin/bash

CURRENT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

mkdir "$CURRENT_DIR/release"

cmake -B "$CURRENT_DIR/release" -S "$CURRENT_DIR" "-DCMAKE_TOOLCHAIN_FILE=$CURRENT_DIR/../../../vcpkg/scripts/buildsystems/vcpkg.cmake" -DCMAKE_BUILD_TYPE=Release

cmake --build "$CURRENT_DIR/release"

if [ ! -e "$CURRENT_DIR/release/r-type_client" ] && [ ! -e "$CURRENT_DIR/release/r-type_client.exe" ]; then
  echo "Client binary is missing"
  exit 1
else
  echo "Client binary is present"
  mv "$CURRENT_DIR/release/r-type_client" "$CURRENT_DIR../../release/r-type_client"
fi

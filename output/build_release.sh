#!/bin/bash

CURRENT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo "Current directory: $CURRENT_DIR"

mkdir "$CURRENT_DIR/release"

bash "$CURRENT_DIR/src/Client/build_release.sh"

bash "$CURRENT_DIR/src/Server/build_release.sh"

# # cmake -DCMAKE_BUILD_TYPE=Release "$CURRENT_DIR/CMakeLists.txt"   -DCMAKE_TOOLCHAIN_FILE=$CURRENT_DIR/../vcpkg/scripts/buildsystems/vcpkg.cmake
# # echo "building cmake $CURRENT_DIR/CMakeLists"

# # cmake -B "$CURRENT_DIR/release" -S "$CURRENT_DIR" "-DCMAKE_TOOLCHAIN_FILE=$CURRENT_DIR/../vcpkg/scripts/buildsystems/vcpkg.cmake"
# cmake "-DCMAKE_TOOLCHAIN_FILE=$CURRENT_DIR/../vcpkg/scripts/buildsystems/vcpkg.cmake" "$CURRENT_DIR/CMakeLists.txt"
# # cd "$CURRENT_DIR/release"
# # cmake "$CURRENT_DIR/.." "-DCMAKE_TOOLCHAIN_FILE=$CURRENT_DIR/../../vcpkg/scripts/buildsystems/vcpkg.cmake" -DCMAKE_BUILD_TYPE=Release
# # cmake --build "$CURRENT_DIR/release"

# make

# not_compiled=0

# if [ ! -e "$CURRENT_DIR/r-type_client" ]; then
#   echo "Client binary is missing"
#   not_compiled=1
# else
#   echo "Client binary is present"
#   mv "$CURRENT_DIR/r-type_client" "$CURRENT_DIR/release/r-type_client"
# fi

# if [ ! -e "$CURRENT_DIR/r-type_server" ]; then
#   echo "Server binary is missing"
#   not_compiled=1
# else
#   echo "Server binary is present"
#   mv "$CURRENT_DIR/r-type_server" "$CURRENT_DIR/release/r-type_server"
# fi

# if [ $not_compiled -eq 1 ]; then
#   echo "One or more compilation(s) failed"
#   exit 1
# fi

# mv "$CURRENT_DIR/r-type_client" "$CURRENT_DIR/release/r-type_client"
# mv "$CURRENT_DIR/r-type_server" "$CURRENT_DIR/release/r-type_server"

# echo "Compilation succeeded"

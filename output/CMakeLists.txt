cmake_minimum_required(VERSION 3.10)

project(Networking)

set(CMAKE_CXX_STANDARD 20)

set(LIBS -lpthread)

# Set the source directories
set(CLIENT_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/Client)
set(SERVER_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/Server)

# Include the CMakeLists.txt files in the Client and Server directories
add_subdirectory(${CLIENT_SRC_DIR} client_build)
add_subdirectory(${SERVER_SRC_DIR} server_build)

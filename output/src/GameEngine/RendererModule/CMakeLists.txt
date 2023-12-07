cmake_minimum_required(VERSION 3.10)

project(Networking)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_library(WindowModule
    WindowManager/Window.cpp)

target_link_libraries(WindowModule sfml-graphics sfml-window sfml-system)
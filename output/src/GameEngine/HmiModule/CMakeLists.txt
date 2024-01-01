cmake_minimum_required(VERSION 3.10)

project(HmiModule)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_library(engine_hmi
    HmiModule.cpp
    HmiModule.hpp
)

target_link_libraries(engine_hmi sfml-graphics sfml-window sfml-system)

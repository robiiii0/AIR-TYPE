cmake_minimum_required(VERSION 3.10)

project(Networking)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_library(WindowModule
    WindowManager/Window.cpp
        Components/AnimationComponent/AnimationComponent.cpp)

target_link_libraries(WindowModule PRIVATE sfml-system sfml-network sfml-graphics sfml-window)
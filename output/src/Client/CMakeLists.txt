cmake_minimum_required(VERSION 3.10)

project(Game)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(Game
        main.cpp
        src/Game/Game.cpp
        ../GameEngine/RendererModule/RendererModule.cpp)

target_link_libraries(Game sfml-graphics sfml-window sfml-system)
cmake_minimum_required(VERSION 3.26)
project(r_type)

set(CMAKE_CXX_STANDARD 14)

include_directories(output/src/Client/src/Game)
include_directories(output/src/Client/src/GameState)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(r_type
        output/src/Client/src/Game/Game.cpp
        output/src/Client/src/Game/Game.hpp
        output/src/Client/src/GameState/GameState.cpp
        output/src/GameEngine/RenderingModule/RenderingModule.cpp
        #        output/src/Client/src/Sfml/Sfml.cpp
#        output/src/Client/src/Networking/Networking.cpp
)

target_link_libraries(r_type sfml-graphics sfml-window sfml-system)
cmake_minimum_required(VERSION 3.10)

project(Game)

set(CMAKE_CXX_STANDARD 20)

include_directories(../GameEngine/)
add_subdirectory(../GameEngine/ ../GameEngine/build)
#add_subdirectory(../GameEngine/RendererModule/)
add_subdirectory(../GameEngine/EntityManager/ ../GameEngine/EntityManager/build)


find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(Game
        main.cpp
        src/Game/Game.cpp
        ../GameEngine/GameEngine.cpp
        ../GameEngine/RendererModule/RendererModule.cpp
        ../GameEngine/EntityManager/EntityManager.cpp
#        ../GameEngine/HmiModule/HmiModule.cpp
#        ../GameEngine/LocalStorageModule/LocalStorageModule.cpp
#        ../GameEngine/NetworkingModule/NetworkingModule.cpp
#        ../GameEngine/PhysicModule/PhysicModule.cpp
)

target_link_libraries(Game sfml-graphics sfml-window sfml-system)
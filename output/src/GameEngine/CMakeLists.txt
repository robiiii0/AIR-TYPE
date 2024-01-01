cmake_minimum_required(VERSION 3.10)

project(ECS)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(EntityManager)
add_subdirectory(MobModule)
add_subdirectory(HmiModule)

add_library(GameEngine STATIC
        GameEngine.cpp
        )

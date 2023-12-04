cmake_minimum_required(VERSION 3.10)

project(ECS)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(EntityManager)
add_subdirectory(MobModule)

add_executable(ECS main.cpp)

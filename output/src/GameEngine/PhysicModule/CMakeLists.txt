cmake_minimum_required(VERSION 3.10)

project(physics)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

add_library(physicModule
   Components/MovementComponent/MovementComponent.cpp
   Components/BoundingBoxComponent/BoundingBoxComponent.cpp
   Components/MassComponent/MassComponent.cpp
   Components/TransformComponent/TransformComponent.cpp

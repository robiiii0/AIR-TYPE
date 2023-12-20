cmake_minimum_required(VERSION 3.10)

project(physics)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

add_library(physicModule
   Components/AccelerationComponent/AccelerationComponent.cpp
   Components/BoundingBoxComponent/BoundingBoxComponent.cpp
   Components/MassComponent/MassComponent.cpp
   Components/PositionComponent/PositionComponent.cpp
   Components/VelocityComponent/VelocityComponent.cpp)

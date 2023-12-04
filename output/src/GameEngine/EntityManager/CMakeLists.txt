cmake_minimum_required(VERSION 3.10)

project(EntityManager)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

add_executable(entity_manager
    ../main.cpp
    EntityManager.cpp
    ComponentManager/ComponentManager.cpp
    ComponentManager/GenericComponents/ULongComponent/ULongComponent.cpp
    ComponentManager/GenericComponents/DoubleComponent/DoubleComponent.cpp
    ComponentManager/GenericComponents/StringComponent/StringComponent.cpp
)

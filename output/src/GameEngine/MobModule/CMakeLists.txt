cmake_minimum_required(VERSION 3.10)

project(MobModule)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

add_library(engin_mobs
    Components/AttackComponent/AttackComponent.cpp
    Components/DefenseComponent/DefenseComponent.cpp
    Components/HealthComponent/HealthComponent.cpp
    Components/IAComponent/IAComponent.cpp
    Components/MobTypeComponent/MobTypeComponent.cpp
    Components/StateComponent/StateComponent.cpp
    Components/VisionComponent/VisionComponent.cpp
)

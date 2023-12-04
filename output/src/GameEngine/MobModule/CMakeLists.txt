cmake_minimum_required(VERSION 3.10)

project(MobModule)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

add_library(mob_module
    MobModule/Components/HealthComponent.cpp
    MobModule/Components/AttackComponent.cpp
    MobModule/Components/DefenseComponent.cpp
    MobModule/Components/SpeedComponent.cpp
    MobModule/Components/ManaComponent.cpp
    MobModule/Components/StaminaComponent.cpp)

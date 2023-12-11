cmake_minimum_required(VERSION 3.10)

project(MobModule)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

add_library(mob_module STATIC
    Components/HealthComponent/HealthComponent.cpp
    Components/AttackComponent/AttackComponent.cpp
    Components/DefenseComponent/DefenseComponent.cpp
#    Components/SpeedComponent.cpp
#    Components/ManaComponent.cpp
#    Components/StaminaComponent.cpp
)

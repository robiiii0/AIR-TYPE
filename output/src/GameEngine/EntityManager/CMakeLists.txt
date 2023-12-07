cmake_minimum_required(VERSION 3.10)

project(EntityManager)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(entity_manager
    ../main.cpp
    EntityManager.cpp
    ComponentManager/ComponentManager.cpp
    ComponentManager/GenericComponents/ULongComponent/ULongComponent.cpp
    ComponentManager/GenericComponents/DoubleComponent/DoubleComponent.cpp
    ComponentManager/GenericComponents/StringComponent/StringComponent.cpp
    ComponentManager/AComponent/AComponent.cpp

    ../RendererModule/RendererModule.cpp
)

target_link_libraries(WindowModule sfml-graphics sfml-window sfml-system)

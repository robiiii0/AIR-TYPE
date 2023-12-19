cmake_minimum_required(VERSION 3.10)

project(Game)

set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/../
        ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/
        ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/build/
        ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/RendererModule/
        ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/RendererModule/build/
        ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/
        ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/build/
)

# Add subdirectories
add_subdirectory(../GameEngine/RendererModule/ ${CMAKE_CURRENT_BINARY_DIR}/RendererModule)
add_subdirectory(../GameEngine/EntityManager/ ${CMAKE_CURRENT_BINARY_DIR}/EntityManager)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(Game
        src/main.cpp
        ../GameEngine/GameEngine.cpp
        ../GameEngine/RendererModule/RendererModule.cpp
        ../GameEngine/RendererModule/WindowManager/Window.cpp
        ../GameEngine/RendererModule/Components/AnimationComponent/AnimationComponent.cpp
        ../GameEngine/RendererModule/Components/SpriteComponent/SpriteComponent.cpp
        ../GameEngine/RendererModule/Components/TextComponent/TextComponent.cpp
        ../GameEngine/EntityManager/EntityManager.cpp
        ../GameEngine/EntityManager/ComponentManager/ComponentManager.cpp
        ../GameEngine/EntityManager/ComponentManager/AComponent/AComponent.cpp
        ../GameEngine/EntityManager/ComponentManager/GenericComponents/DoubleComponent/DoubleComponent.cpp
        ../GameEngine/EntityManager/ComponentManager/GenericComponents/ULongComponent/ULongComponent.cpp
        ../GameEngine/EntityManager/ComponentManager/GenericComponents/StringComponent/StringComponent.cpp
        src/Game/Game.cpp
        # ../GameEngine/HmiModule/HmiModule.cpp
        # ../GameEngine/LocalStorageModule/LocalStorageModule.cpp
        # ../GameEngine/NetworkingModule/NetworkingModule.cpp
        # ../GameEngine/PhysicModule/PhysicModule.cpp
        )

# Link SFML libraries
target_link_libraries(Game PRIVATE sfml-graphics sfml-window sfml-system)

# Link the libraries from RendererModule and EntityManager
target_link_libraries(Game PRIVATE RendererModule EntityManager)

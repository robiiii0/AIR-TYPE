cmake_minimum_required(VERSION 3.10)

project(Game)

set(CMAKE_CXX_STANDARD 20)

include_directories(../)
include_directories(../GameEngine/ ./GameEngine/build)
add_subdirectory(../GameEngine/RendererModule/ ./GameEngine/RendererModule/build)
add_subdirectory(../GameEngine/EntityManager/ ./GameEngine/EntityManager/build)


find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(Game
        main.cpp
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
#        ../GameEngine/HmiModule/HmiModule.cpp
#        ../GameEngine/LocalStorageModule/LocalStorageModule.cpp
#        ../GameEngine/NetworkingModule/NetworkingModule.cpp
#        ../GameEngine/PhysicModule/PhysicModule.cpp
)

target_link_libraries(Game sfml-graphics sfml-window sfml-system)

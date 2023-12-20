cmake_minimum_required(VERSION 3.10)

project(r-type_client)

set(CMAKE_CXX_STANDARD 20)


# find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

add_executable(r-type_client
        src/main.cpp
        ../GameEngine/GameEngine.cpp
        ../GameEngine/RendererModule/RendererModule.cpp
        ../GameEngine/RendererModule/WindowManager/Window.cpp
        ../GameEngine/RendererModule/Components/AnimationComponent/AnimationComponent.cpp
        ../GameEngine/RendererModule/Components/SpriteComponent/SpriteComponent.cpp
        ../GameEngine/RendererModule/Components/ClickableComponent/ClickableComponent.cpp
        ../GameEngine/RendererModule/Components/TextComponent/TextComponent.cpp
        ../GameEngine/EntityManager/EntityManager.cpp
        ../GameEngine/EntityManager/ComponentManager/ComponentManager.cpp
        ../GameEngine/EntityManager/ComponentManager/AComponent/AComponent.cpp
        ../GameEngine/EntityManager/ComponentManager/GenericComponents/DoubleComponent/DoubleComponent.cpp
        ../GameEngine/EntityManager/ComponentManager/GenericComponents/ULongComponent/ULongComponent.cpp
        ../GameEngine/EntityManager/ComponentManager/GenericComponents/StringComponent/StringComponent.cpp
        src/Game/Game.cpp
        # ../GameEngine/LocalStorageModule/LocalStorageModule.cpp
        # ../GameEngine/NetworkingModule/NetworkingModule.cpp
        # ../GameEngine/PhysicModule/PhysicModule.cpp
        )


# Link the libraries from RendererModule and EntityManager
target_link_libraries(r-type_client PRIVATE sfml-graphics sfml-window sfml-system ${LIBS})

add_custom_command(TARGET r-type_client POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:r-type_client>
        ${CMAKE_SOURCE_DIR}
        COMMENT "Moving r-type_client executable to ${CMAKE_SOURCE_DIR}"
        )

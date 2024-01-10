cmake_minimum_required(VERSION 3.10)

project(game-advanced_track)

set(CMAKE_CXX_STANDARD 20)


find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(game-advanced_track
        src/main.cpp
        ../GameEngine/GameEngine.cpp
        ../GameEngine/RendererModule/RendererModule.cpp
        ../GameEngine/RendererModule/WindowManager/Window.cpp
        ../GameEngine/RendererModule/Components/AnimationComponent/AnimationComponent.cpp
        ../GameEngine/RendererModule/Components/SpriteComponent/SpriteComponent.cpp
        ../GameEngine/RendererModule/Components/EnemyComponent/EnemyComponent.cpp
        ../GameEngine/RendererModule/Components/BossComponent/BossComponent.cpp
        ../GameEngine/RendererModule/Components/ClickableComponent/ClickableComponent.cpp
        ../GameEngine/RendererModule/Components/ClickableComponent/RoundedClickableComponent.cpp
        ../GameEngine/RendererModule/Animations/Parallax/Parallax.cpp
        ../GameEngine/RendererModule/Components/TextComponent/TextComponent.cpp
        ../GameEngine/EntityManager/EntityManager.cpp
        ../GameEngine/EntityManager/ComponentManager/ComponentManager.cpp
        ../GameEngine/EntityManager/ComponentManager/AComponent/AComponent.cpp
        ../GameEngine/EntityManager/ComponentManager/GenericComponents/DoubleComponent/DoubleComponent.cpp
        ../GameEngine/EntityManager/ComponentManager/GenericComponents/ULongComponent/ULongComponent.cpp
        ../GameEngine/EntityManager/ComponentManager/GenericComponents/StringComponent/StringComponent.cpp
        ../GameEngine/EntityManager/ComponentManager/GenericComponents/Vector2fComponent/Vector2fComponent.cpp
        ../GameEngine/EntityManager/exceptions/ComponentAlreadyExists/ComponentAlreadyExists.cpp
        ../GameEngine/EntityManager/exceptions/CouldNotAddComponent/CouldNotAddComponent.cpp
        ../GameEngine/EntityManager/exceptions/CouldNotAddEntity/CouldNotAddEntity.cpp
        ../GameEngine/EntityManager/exceptions/CouldNotCreateEntity/CouldNotCreateEntity.cpp
        ../GameEngine/EntityManager/exceptions/CouldNotFindComponent/CouldNotFindComponent.cpp
        ../GameEngine/EntityManager/exceptions/CouldNotFindEntity/CouldNotFindEntity.cpp
        ../GameEngine/EntityManager/exceptions/CouldNotRemoveComponent/CouldNotRemoveComponent.cpp
        ../GameEngine/EntityManager/exceptions/NoComponent/NoComponent.cpp
        ../GameEngine/PhysicModule/PhysicModule.cpp
        ../GameEngine/PhysicModule/Components/BoundingBoxComponent/BoundingBoxComponent.cpp
        ../GameEngine/PhysicModule/Components/MovementComponent/MovementComponent.cpp
        ../GameEngine/PhysicModule/Components/TransformComponent/TransformComponent.cpp
        ../GameEngine/RendererModule/Components/SoundComponent/SoundComponent.cpp
        ../GameEngine/RendererModule/Components/InputComponent/InputComponent.cpp
        ../GameEngine/HmiModule/HmiModule.cpp
        ../GameEngine/HmiModule/HmiModule.hpp

        src/Game/Game.cpp
        src/Game/Utils/Utils.cpp
)

# Link the libraries from RendererModule and EntityManager
target_link_libraries(game-advanced_track PRIVATE sfml-graphics sfml-window sfml-system sfml-audio ${LIBS})

add_custom_command(TARGET game-advanced_track POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:game-advanced_track>
        ${CMAKE_SOURCE_DIR}
        COMMENT "Moving game-advanced_track executable to ${CMAKE_SOURCE_DIR}"
)

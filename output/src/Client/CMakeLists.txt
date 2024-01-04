cmake_minimum_required(VERSION 3.10)

project(r-type_client)

set(CMAKE_CXX_STANDARD 20)


find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(r-type_client
        src/main.cpp
        ../GameEngine/GameEngine.cpp
        ../GameEngine/RendererModule/RendererModule.cpp
        ../GameEngine/RendererModule/WindowManager/Window.cpp
        ../GameEngine/RendererModule/Components/AnimationComponent/AnimationComponent.cpp
        ../GameEngine/RendererModule/Components/SpriteComponent/SpriteComponent.cpp
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
        src/Game/Client.cpp
        src/Game/ClientSettingManagement/ClientSettingManagement.cpp
        src/Game/ClientEntityManagement/ClientEntityManagement.cpp
        src/Game/ClientSpritesManagement/ClientSpriteManagement.cpp
        src/Game/ClientMenuManagement/ClientMenuManagement.cpp
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
        ../GameEngine/NetworkingModule/NetworkingModule.cpp
        ../GameEngine/NetworkingModule/Client/Client.cpp
        ../GameEngine/NetworkingModule/Buffer/Buffer.cpp
        ../GameEngine/NetworkingModule/Messaging/Messager.cpp
        ../GameEngine/NetworkingModule/exceptions/ClientDisconnectedException/ClientDisconnectedException.cpp
        ../GameEngine/NetworkingModule/exceptions/ClientIdOutOfRangeException/ClientIdOutOfRangeException.cpp
        ../GameEngine/NetworkingModule/exceptions/CouldNotAcceptClientException/CouldNotAcceptClientException.cpp
        ../GameEngine/NetworkingModule/exceptions/CouldNotBindAddressException/CouldNotBindAddressException.cpp
        ../GameEngine/NetworkingModule/exceptions/CouldNotReceiveException/CouldNotReceiveException.cpp
        ../GameEngine/NetworkingModule/exceptions/CouldNotSendException/CouldNotSendException.cpp
        ../GameEngine/NetworkingModule/exceptions/SocketNotCreatedException/SocketNotCreatedException.cpp
        ../GameEngine/HmiModule/HmiModule.cpp
        ../GameEngine/HmiModule/HmiModule.hpp
        src/Game/ClientMenuManagement/ClientSetDisplay.cpp


        # ../GameEngine/LocalStorageModule/LocalStorageModule.cpp
        # ../GameEngine/NetworkingModule/NetworkingModule.cpp
        # ../GameEngine/PhysicModule/PhysicModule.cpp
)

link_directories(${CMAKE_SOURCE_DIR}/GameEngine/NetworkingModule)

# Link the libraries from RendererModule and EntityManager
target_link_libraries(r-type_client PRIVATE engine_networking sfml-graphics sfml-window sfml-system sfml-audio ${LIBS})

add_custom_command(TARGET r-type_client POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:r-type_client>
        ${CMAKE_SOURCE_DIR}
        COMMENT "Moving r-type_client executable to ${CMAKE_SOURCE_DIR}"
)

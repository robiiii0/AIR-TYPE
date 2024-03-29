cmake_minimum_required(VERSION 3.10)

project(r-type_server)

set(CMAKE_CXX_STANDARD 20)

set(LIBS -lpthread)

find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)

# Specify the source file
set(SERVER_SRC  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/src/Server/Server.cpp
                # ${CMAKE_CURRENT_SOURCE_DIR}/src/Serializer/Serializer.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/GameEngine.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/NetworkingModule/NetworkingModule.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/NetworkingModule/Client/Client.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/NetworkingModule/Buffer/Buffer.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/NetworkingModule/Messaging/Messager.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/NetworkingModule/exceptions/ClientDisconnectedException/ClientDisconnectedException.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/NetworkingModule/exceptions/ClientIdOutOfRangeException/ClientIdOutOfRangeException.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/NetworkingModule/exceptions/CouldNotAcceptClientException/CouldNotAcceptClientException.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/NetworkingModule/exceptions/CouldNotBindAddressException/CouldNotBindAddressException.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/NetworkingModule/exceptions/CouldNotReceiveException/CouldNotReceiveException.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/NetworkingModule/exceptions/CouldNotSendException/CouldNotSendException.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/NetworkingModule/exceptions/SocketNotCreatedException/SocketNotCreatedException.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/NetworkingModule/Serializer/Serializer.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/EntityManager.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/ComponentManager/ComponentManager.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/ComponentManager/AComponent/AComponent.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/ComponentManager/GenericComponents/DoubleComponent/DoubleComponent.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/ComponentManager/GenericComponents/ULongComponent/ULongComponent.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/ComponentManager/GenericComponents/StringComponent/StringComponent.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/ComponentManager/GenericComponents/Vector2fComponent/Vector2fComponent.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/exceptions/ComponentAlreadyExists/ComponentAlreadyExists.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/exceptions/CouldNotAddComponent/CouldNotAddComponent.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/exceptions/CouldNotAddEntity/CouldNotAddEntity.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/exceptions/CouldNotCreateEntity/CouldNotCreateEntity.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/exceptions/CouldNotFindComponent/CouldNotFindComponent.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/exceptions/CouldNotFindEntity/CouldNotFindEntity.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/exceptions/CouldNotRemoveComponent/CouldNotRemoveComponent.cpp
                ${CMAKE_CURRENT_SOURCE_DIR}/../GameEngine/EntityManager/exceptions/NoComponent/NoComponent.cpp
                ../GameEngine/RendererModule/RendererModule.cpp
                ../GameEngine/RendererModule/WindowManager/Window.cpp
                ../GameEngine/RendererModule/Components/AnimationComponent/AnimationComponent.cpp
                ../GameEngine/RendererModule/Components/SpriteComponent/SpriteComponent.cpp
                ../GameEngine/RendererModule/Components/BossComponent/BossComponent.cpp
                ../GameEngine/RendererModule/Components/ClickableComponent/ClickableComponent.cpp
                ../GameEngine/RendererModule/Components/ClickableComponent/RoundedClickableComponent.cpp
                ../GameEngine/RendererModule/Animations/Parallax/Parallax.cpp
                ../GameEngine/RendererModule/Components/TextComponent/TextComponent.cpp
                ../GameEngine/RendererModule/Components/SoundComponent/SoundComponent.cpp
                ../GameEngine/RendererModule/Components/InputComponent/InputComponent.cpp
                ../GameEngine/RendererModule/Components/EnemyComponent/EnemyComponent.cpp
                )

# Create the executable for the server with only main.cpp
add_executable(r-type_server ${SERVER_SRC})

# Link libraries if needed
if (APPLE)
    find_library(COREAUDIO_LIBRARY CoreAudio)
    find_library(AUDIOTOOLBOX_LIBRARY AudioToolbox)
    find_library(AUDIOUNIT_LIBRARY AudioUnit)

    target_link_libraries(r-type_server PRIVATE ${COREAUDIO_LIBRARY} ${AUDIOTOOLBOX_LIBRARY} ${AUDIOUNIT_LIBRARY})
endif()

target_link_libraries(r-type_server PRIVATE ${LIBS}  sfml-system sfml-network sfml-graphics sfml-window sfml-audio)

add_custom_command(TARGET r-type_server POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:r-type_server>
        ${CMAKE_SOURCE_DIR}
        COMMENT "Moving r-type_server executable to ${CMAKE_SOURCE_DIR}"
        )

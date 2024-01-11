cmake_minimum_required(VERSION 3.10)

project(Networking)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS system CONFIG REQUIRED)

include_directories(./)

add_library(engine_networking
    NetworkingModule.cpp
    Buffer/Buffer.cpp
    Client/Client.cpp
    exceptions/ClientDisconnectedException/ClientDisconnectedException.cpp
    exceptions/ClientIdOutOfRangeException/ClientIdOutOfRangeException.cpp
    exceptions/CouldNotAcceptClientException/CouldNotAcceptClientException.cpp
    exceptions/CouldNotBindAddressException/CouldNotBindAddressException.cpp
    exceptions/CouldNotReceiveException/CouldNotReceiveException.cpp
    exceptions/CouldNotSendException/CouldNotSendException.cpp
    exceptions/SocketNotCreatedException/SocketNotCreatedException.cpp
    Messaging/Messager.cpp
    Serializer/Serializer.cpp
    )

target_link_libraries(engine_networking PRIVATE sfml-system sfml-network)

add_custom_command(TARGET engine_networking POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:engine_networking>
        ${CMAKE_SOURCE_DIR}
        COMMENT "Moving libengine_networking.a library to ${CMAKE_SOURCE_DIR}"
        )

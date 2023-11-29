cmake_minimum_required(VERSION 3.10)

project(Networking)

set(CMAKE_CXX_STANDARD 20)

include_directories(./)

add_executable(networking
    main.cpp
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
    Messaging/Messager.cpp)

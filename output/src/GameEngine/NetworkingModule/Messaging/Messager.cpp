// /*
// ** EPITECH PROJECT, 2023
// ** output
// ** File description:
// ** Messager
// */

// #include "Messager.hpp"

// Engine::Network::Messager::Messager(Engine::Network::NetworkingTypeEnum type)
// {
//     if (type == Engine::Network::NetworkingTypeEnum::TCP)
//         _mode = true;
//     else
//         _mode = false;
// }

// Engine::Network::Messager::~Messager() {}

// #include <iostream>

// void Engine::Network::Messager::sendMessage(const std::string       &message,
//                                             Engine::Network::Client &client,
//                                             int socket_fd) {
//     std::unique_lock lock(_mutex);
//     const char      *msg = message.c_str();
//     std::size_t      bytesSent = 0;

//     if (_mode) {
//         bytesSent = send(client.getSocketFd(), msg, message.size(), 0);
//     } else {
//         struct sockaddr_in client_address = client.getAddress();
//         bytesSent = sendto(socket_fd, msg, message.size(), 0,
//                            (struct sockaddr *)&client_address,
//                            sizeof(client.getAddress()));
//     }
//     if (bytesSent < 0) throw CouldNotSendException(client);
//     lock.unlock();
// }

// void Engine::Network::Messager::startReceiving(
//     Engine::Network::Client &client) {
//     std::thread receiveThread([this, &client] { receiveLoop(client); });
//     receiveThread.detach();
// }

// void Engine::Network::Messager::receiveLoop(Engine::Network::Client &client)
// {
//     char        buffer[1024];
//     std::size_t bytesReceived = 0;
//     int         socket_fd = client.getSocketFd();

//     while (true) {
//         if (_mode) {
//             bytesReceived = recv(socket_fd, buffer, 5000, 0);
//         } else {
//             bytesReceived = recvfrom(socket_fd, buffer, 5000, 0, NULL, NULL);
//         }
//         if (bytesReceived < 0) {
//             throw CouldNotReceiveException();
//         } else if (bytesReceived == 0) {
//             client.setConnected(false);
//             break;
//         } else if (bytesReceived <= 1024) {
//             client.getBuffer()->write(buffer, bytesReceived);
//         }
//     }
//     // close(socket_fd);
// }

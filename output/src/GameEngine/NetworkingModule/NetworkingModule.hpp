/*
** EPITECH PROJECT, 2023
** output
** File description:
** NetworkingModule
*/

#ifndef NETWORKINGMODULE_HPP_
#define NETWORKINGMODULE_HPP_

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#include <cstdint>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "Client/Client.hpp"
#include "Messaging/Messager.hpp"
#include "enums/NetworkingTypeEnum.hpp"
#include "exceptions/ClientDisconnectedException/ClientDisconnectedException.hpp"
#include "exceptions/ClientIdOutOfRangeException/ClientIdOutOfRangeException.hpp"
#include "exceptions/CouldNotAcceptClientException/CouldNotAcceptClientException.hpp"
#include "exceptions/CouldNotBindAddressException/CouldNotBindAddressException.hpp"
#include "exceptions/CouldNotSendException/CouldNotSendException.hpp"
#include "exceptions/SocketNotCreatedException/SocketNotCreatedException.hpp"

namespace Engine {
    namespace Network {
        class NetworkingModule {
            public:
                /*
                 * @brief Constructor of the networking module in server mode
                 * @param port The port to listen to
                 * @param type The type of the networking module
                 * @param max_clients The maximum number of clients that can
                 * connect to the server
                 * @throws SocketNotCreatedException If the socket could not be
                 * created
                 * @throws CouldNotBindAddressException If the address could not
                 * be bound to the socket
                 */
                NetworkingModule(int port, NetworkingTypeEnum type,
                                 int max_clients = 4);
                /*
                 * @brief Constructor of the networking module in client mode
                 * @param port The port to listen to
                 * @param type The type of the networking module
                 * @param ip_address The ip address to listen to
                 * @param server_port The port of the server to connect to
                 * @param max_clients The maximum number of clients that can
                 * connect to the server
                 * @throws SocketNotCreatedException If the socket could not be
                 * created
                 * @throws CouldNotBindAddressException If the address could not
                 * be bound to the socket
                 */
                NetworkingModule(int port, NetworkingTypeEnum type,
                                 const std::string &server_address,
                                 int server_port, int max_clients = 4);
                ~NetworkingModule();

                /*
                 * @brief Send a message to a specific client
                 * @param message The message to send
                 * @param client_id The id of the client to send the message to
                 * @throws ClientIdOutOfRangeException If the client id is
                 * greater than the number of clients connected to the server
                 * @throws ClientDisconnectedException If the client the message
                 * is sent to is disconnected
                 * @throws CouldNotSendException If the message could not be
                 * sent
                 */
                void sendMessage(const std::string &message,
                                 const std::size_t &client_id);
                /*
                 * @brief Send a message to all the clients connected to the
                 * server
                 * @param message The message to send
                 * @throws CouldNotSendException If the message could not be
                 * sent
                 */
                void broadcastMessage(const std::string &message);
                /*
                 * @brief Get the list of clients connected to the server
                 * @return The list of clients connected to the server
                 * @exceptsafe Shall not throw exceptions
                 * @relatesalso Engine::Network::Client
                 */
                std::vector<Client> &getClients() noexcept;

            protected:
                /*
                 * @brief Run the networking module to make it listen to
                 * incoming messages
                 * @throws CouldNotAcceptClientException If the server could not
                 * accept a client in TCP mode
                 * @throws CouldNotSendReceiveException If the server could not
                 * receive a message in UDP mode
                 */
                void run();
                void addClient(const struct sockaddr_in &client_address);
                void runTCP(Engine::Network::Messager &messager);
                void runUDP(Engine::Network::Messager &messager);
                bool isNewClient(const struct sockaddr_in &client_address);
                void addMessageToClientBuffer(
                    const char *buffer, std::size_t &bytesReceived,
                    const struct sockaddr_in &client_address);

            private:
                NetworkingTypeEnum                   _type;
                int                                  _socket_fd;
                struct sockaddr_in                   _server_address;
                std::vector<Engine::Network::Client> _clients;
                int                                  _max_clients;
                const uint8_t                        _protocol_prefix = 0xAA;
                const uint8_t                        _protocol_suffix = 0xBB;
                std::thread                          _running_thread;
        };
    };  // namespace Network
};      // namespace Engine

#endif /* !NETWORKINGMODULE_HPP_ */

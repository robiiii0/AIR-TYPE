/*
** EPITECH PROJECT, 2023
** output
** File description:
** Client
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

// #include <arpa/inet.h>
// #include <netinet/in.h>
// #include <unistd.h>

#include <SFML/Network.hpp>
#include <memory>
#include <string>

#include "../Buffer/Buffer.hpp"

namespace Engine {
    namespace Network {
        class Client {
            public:
                Client(sf::IpAddress ip_address, unsigned short port);
                ~Client();

                /*
                 * @brief Get the address of the client
                 * @return The address of the client
                 */
                sf::IpAddress getAddress() const;
                /*
                 * @brief Get the port of the client
                 * @return The port of the client
                 */
                unsigned short getPort() const;
                /*
                 * @brief Get the id of the client
                 * @return The id of the client
                 */
                std::size_t getId() const;
                /*
                 * @brief Get the buffer of the client
                 * @return The buffer of the client
                 */
                std::shared_ptr<Engine::Network::Buffer> getBuffer();
                /*
                 * @brief Get if the client is threaded
                 * @return True if the client is threaded, false otherwise
                 */
                bool isThreaded() const;
                /*
                 * @brief Get if the client is connected
                 * @return True if the client is connected, false otherwise
                 */
                bool isConnected() const;

                /*
                 * @brief Set if the client is connected
                 * @param connected True if the client is connected, false
                 * otherwise
                 */
                void setConnected(bool connected);
                /*
                 * @brief Set if the client is threaded
                 * @param threaded True if the client is threaded, false
                 * otherwise
                 */
                void setThreaded(bool threaded);

            protected:
            private:
                std::size_t    getClientId() noexcept;
                static int     __max_client_id;
                std::size_t    _id;
                sf::IpAddress  _ip_address;
                unsigned short _port;
                // struct sockaddr_in                       _address;
                std::shared_ptr<Engine::Network::Buffer> _buffer;
                // int                                      _socket_fd;
                bool _is_threaded;
                bool _is_connected;
        };
    };  // namespace Network
};      // namespace Engine

#endif /* !CLIENT_HPP_ */

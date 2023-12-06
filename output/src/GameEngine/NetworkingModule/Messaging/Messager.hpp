/*
** EPITECH PROJECT, 2023
** output
** File description:
** Messager
*/

#ifndef MESSAGER_HPP_
#define MESSAGER_HPP_

#include <condition_variable>
#include <mutex>
#include <thread>

#include "../Client/Client.hpp"
#include "../enums/NetworkingTypeEnum.hpp"
#include "../exceptions/CouldNotReceiveException/CouldNotReceiveException.hpp"
#include "../exceptions/CouldNotSendException/CouldNotSendException.hpp"

namespace Engine {
    namespace Network {
        class Messager {
            public:
                Messager(NetworkingTypeEnum type);
                ~Messager();

                void sendMessage(const std::string       &message,
                                 Engine::Network::Client &client,
                                 int                      socket_fd);
                void startReceiving(Engine::Network::Client &client);

            protected:
            private:
                void       receiveLoop(Engine::Network::Client &client);
                std::mutex mutex;
                std::condition_variable cv;
                bool                    _mode;
        };
    };  // namespace Network
};      // namespace Engine

#endif /* !MESSAGER_HPP_ */

/*
** EPITECH PROJECT, 2023
** output
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <cstdint>
#include <map>
#include <queue>

#include "../../../GameEngine/NetworkingModule/NetworkingModule.hpp"

class Server {
    public:
        Server();
        ~Server();

        int run();

    protected:
        void init();
        void loop();
        void stop();

    private:
        void                                               networkLoop();
        bool                                               _running;
        std::uint32_t                                      _nb_clients;
        std::shared_ptr<Engine::Network::NetworkingModule> _networkingModule;
        std::queue<std::string>                            _globalMessages;
        std::map<std::uint32_t, std::queue<std::string>>   _clientMessages;
};

#endif /* !SERVER_HPP_ */

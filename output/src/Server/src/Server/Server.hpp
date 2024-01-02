/*
** EPITECH PROJECT, 2023
** output
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <cstdint>
#include <ctime>
#include <map>
#include <queue>

#include "../../../GameEngine/NetworkingModule/NetworkingModule.hpp"

#define SERVER_TICKRATE 64

class Server {
    public:
        Server();
        ~Server();

        int run();

    protected:
        void init();
        void loop();
        void stop();
        void applyTickrate();

    private:
        void                                                networkLoop();
        bool                                                _running;
        std::uint32_t                                       _nb_clients;
        std::shared_ptr<Engine::Network::NetworkingModule>  _networkingModule;
        std::queue<std::string>                             _globalMessages;
        std::map<std::uint32_t, std::queue<std::string>>    _clientMessages;
        std::chrono::_V2::high_resolution_clock::time_point _clock;
};

#endif /* !SERVER_HPP_ */

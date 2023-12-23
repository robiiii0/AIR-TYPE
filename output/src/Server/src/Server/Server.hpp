/*
** EPITECH PROJECT, 2023
** output
** File description:
** Server
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

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
        bool _running;
        std::shared_ptr<Engine::Network::NetworkingModule> _networkingModule;
};

#endif /* !SERVER_HPP_ */

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

#include "../../../GameEngine/GameEngine.hpp"
#include "../../../GameEngine/NetworkingModule/NetworkingModule.hpp"

#define SERVER_TICKRATE 256

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
        void sendToAllExcept(std::uint32_t id, std::string message);
        void sendGameStatus(std::uint32_t id);
        void createPlayer(std::uint32_t id);
        void createMissile(std::uint32_t id);
        void updatePlayer();
        void updateMissile();
        void updateEnnemies();
        void update();
        void movePlayer(int, std::uint32_t);
        void createEnemy(std::uint32_t id);

    private:
        void                                               networkLoop();
        bool                                               _running;
        std::uint32_t                                      _nb_clients;
        std::unique_ptr<Engine::Network::NetworkingModule> _networkingModule;
        std::unique_ptr<Engine::GameEngine>                _gameEngine;
        std::queue<std::string>                            _globalMessages;
        std::map<std::uint32_t, std::queue<std::string>>   _clientMessages;
        std::chrono::high_resolution_clock::time_point     _clock;

        std::map<std::uint32_t, std::uint32_t> _playerEntities;
        std::map<std::uint32_t, std::uint32_t> _missileEntities;
        std::map<std::uint32_t, std::uint32_t> _ennemyEntities;
        std::uint32_t                          _missileID;
};

#endif /* !SERVER_HPP_ */

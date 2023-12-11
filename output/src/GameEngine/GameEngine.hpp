/*
** EPITECH PROJECT, 2023
** output
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

#include "EntityManager/EntityManager.hpp"
#include "HmiModule/HmiModule.hpp"
#include "LocalStorageModule/LocalStorageModule.hpp"
#include "NetworkingModule/NetworkingModule.hpp"
#include "PhysicModule/PhysicModule.hpp"
#include "RendererModule/RendererModule.hpp"

namespace Engine {
    class GameEngine {
        public:
            GameEngine(bool client = true);
            ~GameEngine();

            void run();

        private:
            Entity::EntityManager            *_entityManager;
            Hmi::HmiModule                   *_hmiModule;
            LocalStorage::LocalStorageModule *_localStorageModule;
            Network::NetworkingModule        *_networkingModule;
            RendererModule::RendererModule   *_rendererModule;
    };
}  // namespace Engine

#endif /* !GAMEENGINE_HPP_ */

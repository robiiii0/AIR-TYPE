/*
** EPITECH PROJECT, 2023
** output
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

#include "RendererModule/RendererModule.hpp"
#include "EntityManager/EntityManager.hpp"
//#include "HmiModule/HmiModule.hpp"
//#include "LocalStorageModule/LocalStorageModule.hpp"
//#include "NetworkingModule/NetworkingModule.hpp"
//#include "PhysicModule/PhysicModule.hpp"

namespace Engine {
    class GameEngine {
        public:
            GameEngine(bool client = true);
            ~GameEngine();

            void run();

            Entity::EntityManager            *getEntityManager() const;
            RendererModule::RendererModule   *getRendererModule() const;
//            Hmi::HmiModule                   *getHmiModule() const;
//            LocalStorage::LocalStorageModule *getLocalStorageModule() const;
//            Network::NetworkingModule        *getNetworkingModule() const;

        private:
            Entity::EntityManager            *_entityManager;
            RendererModule::RendererModule   *_rendererModule;

//            Hmi::HmiModule                   *_hmiModule;
//            LocalStorage::LocalStorageModule *_localStorageModule;
//            Network::NetworkingModule        *_networkingModule;
    };
}  // namespace Engine

#endif /* !GAMEENGINE_HPP_ */

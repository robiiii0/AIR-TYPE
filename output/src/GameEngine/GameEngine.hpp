/*
** EPITECH PROJECT, 2023
** output
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

#include "RendererModule/RendererModule.hpp"
// #include "../EntityManager/EntityManager.hpp"
#include <chrono>
#include <thread>

#include "./EntityManager/EntityManager.hpp"
#include "./PhysicModule/PhysicModule.hpp"

// #include "LocalStorageModule/LocalStorageModule.hpp"
// #include "NetworkingModule/NetworkingModule.hpp"
// #include "PhysicModule/PhysicModule.hpp"

namespace Engine {
    class GameEngine {
        public:
            GameEngine(bool client = true);
            ~GameEngine();

            void run();

            Engine::Entity::EntityManager  *getEntityManager() const;
            RendererModule::RendererModule *getRendererModule() const;
            Engine::Physic::PhysicModule   *getPhysicModule() const;
            //            const; LocalStorage::LocalStorageModule
            //            *getLocalStorageModule() const;
            //            Network::NetworkingModule *getNetworkingModule()
            //            const;

        private:
            Engine::Entity::EntityManager  *_entityManager;
            RendererModule::RendererModule *_rendererModule;
            Engine::Physic::PhysicModule   *_physicModule;

            //            LocalStorage::LocalStorageModule *_localStorageModule;
            //            Network::NetworkingModule        *_networkingModule;
    };
}  // namespace Engine

#endif /* !GAMEENGINE_HPP_ */

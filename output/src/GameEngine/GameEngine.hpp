/*
** EPITECH PROJECT, 2023
** output
** File description:
** GameEngine
*/

#ifndef GAMEENGINE_HPP_
#define GAMEENGINE_HPP_

#include <chrono>
#include <thread>

#include "./EntityManager/EntityManager.hpp"
#include "./PhysicModule/PhysicModule.hpp"
#include "RendererModule/RendererModule.hpp"

namespace Engine {
    class GameEngine {
        public:
            GameEngine(bool client = true);
            ~GameEngine();

            void run();

            std::shared_ptr<Engine::Entity::EntityManager> getEntityManager()
                const;
            std::shared_ptr<Engine::RendererModule::RendererModule>
                getRendererModule() const;
            std::shared_ptr<Engine::Physic::PhysicModule> getPhysicModule()
                const;

        private:
            std::shared_ptr<Engine::Entity::EntityManager> _entityManager;
            std::shared_ptr<Engine::RendererModule::RendererModule>
                                                          _rendererModule;
            std::shared_ptr<Engine::Physic::PhysicModule> _physicModule;
    };
}  // namespace Engine

#endif /* !GAMEENGINE_HPP_ */

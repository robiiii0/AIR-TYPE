/*
** EPITECH PROJECT, 2023
** output
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

Engine::GameEngine::GameEngine(bool client) {
    _rendererModule =
        (client) ? std::make_shared<RendererModule::RendererModule>() : nullptr;
    _entityManager = std::make_shared<Entity::EntityManager>();
}

Engine::GameEngine::~GameEngine() {}

void Engine::GameEngine::run() {
    const float targetFrameTime = 1.0f / 60.0f;
    auto        lastTime = std::chrono::high_resolution_clock::now();

    while (1) {
        auto  currentTime = std::chrono::high_resolution_clock::now();
        float dt = std::chrono::duration<float, std::chrono::seconds::period>(
                       currentTime - lastTime)
                       .count();

        while (dt < targetFrameTime) {
            std::this_thread::sleep_for(std::chrono::milliseconds(
                static_cast<int>((targetFrameTime - dt) * 1000)));
            currentTime = std::chrono::high_resolution_clock::now();
            dt = std::chrono::duration<float, std::chrono::seconds::period>(
                     currentTime - lastTime)
                     .count();
        }
        lastTime = currentTime;
    }
}

std::shared_ptr<Engine::Entity::EntityManager>
    Engine::GameEngine::getEntityManager() const {
    return _entityManager;
}

std::shared_ptr<Engine::RendererModule::RendererModule>
    Engine::GameEngine::getRendererModule() const {
    return _rendererModule;
}

std::shared_ptr<Engine::Physic::PhysicModule>
    Engine::GameEngine::getPhysicModule() const {
    return _physicModule;
}

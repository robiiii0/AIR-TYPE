/*
** EPITECH PROJECT, 2023
** output
** File description:
** GameEngine
*/

#include "GameEngine.hpp"

Engine::GameEngine::GameEngine(bool client) {
    _rendererModule = new RendererModule::RendererModule();
    _entityManager = new Entity::EntityManager();
    //    _localStorageModule = new LocalStorage::LocalStorageModule();
    //    if (client)
    //        _networkingModule = new Network::NetworkingModule(
    //            4243, Network::NetworkingTypeEnum::UDP, "127.0.0.1", 4242);
    //    else
    //        _networkingModule = new Network::NetworkingModule(
    //            4242, Network::NetworkingTypeEnum::UDP);
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
        
        _rendererModule->update();
        // _rendererModule->render(*_entityManager, 0);
    }
}

Engine::Entity::EntityManager *Engine::GameEngine::getEntityManager() const {
    return _entityManager;
}

//
// Engine::LocalStorage::LocalStorageModule *
//    Engine::GameEngine::getLocalStorageModule() const {
//    return _localStorageModule;
//}
//
// Engine::Network::NetworkingModule *Engine::GameEngine::getNetworkingModule()
//    const {
//    return _networkingModule;
//}

Engine::RendererModule::RendererModule *Engine::GameEngine::getRendererModule()
    const {
    return _rendererModule;
}

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
    //    _hmiModule = new Hmi::HmiModule(_rendererModule->getWindow());
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
    //    _networkingModule->run();
    while (1) {
        //        _hmiModule->update();
        _rendererModule->update();
        _rendererModule->render(*_entityManager, 0);
    }
}

Engine::Entity::EntityManager *Engine::GameEngine::getEntityManager() const {
    return _entityManager;
}

//
// Engine::Hmi::HmiModule *Engine::GameEngine::getHmiModule() const {
//    return _hmiModule;
// }
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

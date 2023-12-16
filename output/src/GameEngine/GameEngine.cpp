/*
** EPITECH PROJECT, 2023
** output
** File description:
** GameEngine
*/

#include "GameEngine.hpp"
template<typename T>
Engine::GameEngine<T>::GameEngine(bool client) {
    _rendererModule = new RendererModule::RendererModule();
//    _entityManager = new Entity::EntityManager();
//    _hmiModule = new Hmi::HmiModule(_rendererModule->getWindow());
//    _localStorageModule = new LocalStorage::LocalStorageModule();
//    if (client)
//        _networkingModule = new Network::NetworkingModule(
//            4243, Network::NetworkingTypeEnum::UDP, "127.0.0.1", 4242);
//    else
//        _networkingModule = new Network::NetworkingModule(
//            4242, Network::NetworkingTypeEnum::UDP);
}

template<typename T>
Engine::GameEngine<T>::~GameEngine() {}

template<typename T>
void Engine::GameEngine<T>::run() {
//    _networkingModule->run();
    while (1) {
//        _hmiModule->update();
        _rendererModule->update();
        _rendererModule->render();
    }
}

template<typename T>
Engine::Entity::EntityManager<T> *Engine::GameEngine<T>::getEntityManager() const {
    return _entityManager;
}
//
//Engine::Hmi::HmiModule *Engine::GameEngine::getHmiModule() const {
//    return _hmiModule;
//}
//
//Engine::LocalStorage::LocalStorageModule *
//    Engine::GameEngine::getLocalStorageModule() const {
//    return _localStorageModule;
//}
//
//Engine::Network::NetworkingModule *Engine::GameEngine::getNetworkingModule()
//    const {
//    return _networkingModule;
//}

template<typename T>
Engine::RendererModule::RendererModule *Engine::GameEngine<T>::getRendererModule()
    const {
    return _rendererModule;
}

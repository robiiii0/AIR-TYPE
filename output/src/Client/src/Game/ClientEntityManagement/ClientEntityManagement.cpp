#include "../Client.hpp"

void Client::addEntity(std::uint32_t entity) { _entities.push_back(entity); }

void Client::removeEntity(std::uint32_t entity) {
    _entities.erase(std::remove(_entities.begin(), _entities.end(), entity),
                    _entities.end());
}


std::vector<std::uint32_t> &Client::getEntities() { return _entities; }
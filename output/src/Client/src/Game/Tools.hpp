#include "Client.hpp"

void Client::playerInit()
{
    Engine::Network::Serializer::entity_t entityTemp = {-1,{static_cast<bool>(false)}, {static_cast<float>(0.0)}, {static_cast<float>(0.0)}};
    for (int i = 0; i < 4; i++) {
        _player.push_back(entityTemp);
    }
}
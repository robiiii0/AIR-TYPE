#include "EntityManager/EntityManager.hpp"
#include <array>

int main()
{
    std::array<std::uint32_t, 100> entities;
    EntityManager manager;
    for (int i = 0; i < 100; i++) {
        entities[i] = manager.createEntity();
    }

    while(1)
    {
        for (auto entity : entities) {
        }
    }
    // manager.setSignature(entities[0], );
    // std::cout << manager.getSignature(entities[0]) << std::endl;
    
    // manager.setSignature(entities[0], (10));
    // std::cout << manager.getSignature(entities[0]) << std::endl;
    
    // manager.setSignature(entities[0], (23));

    // std::cout << manager.getSignature(entities[0]) << std::endl;

    for (int i = 0; i < 100; i++) manager.destroyEntity(entities[i]);
    // entities.clear();
    // manager.destroyEntity(entity);
    // manager.setSignature(entity, std::bitset<MAX_COMPONENTS>());
    // std::bitset<MAX_COMPONENTS> signature = manager.getSignature(entity);

    return 0;
}

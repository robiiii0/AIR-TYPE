#include <array>

#include "EntityManager/ComponentManager/ComponentManager.hpp"
#include "EntityManager/ComponentManager/GenericComponents/ULongComponent/ULongComponent.hpp"
#include "EntityManager/EntityManager.hpp"

int main() {
    std::array<std::uint32_t, 100> entities;
    // Engine::EntityManager::ComponentManager<int> componentManager;
    Engine::Entity::EntityManager manager;
    Engine::Entity::Component::GenericComponents::ULongComponent component(
        0, "ULongComponent", (std::uint64_t)10);
    for (int i = 0; i < 100; i++) {
        entities[i] = manager.createEntity();
        manager.addComponent(manager.getEntity(i), component);
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

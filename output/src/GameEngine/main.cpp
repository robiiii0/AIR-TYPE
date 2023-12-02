#include <array>

#include "EntityManager/ComponentManager/ComponentManager.hpp"
#include "EntityManager/ComponentManager/GenericComponents/ULongComponent/ULongComponent.hpp"
#include "EntityManager/ComponentManager/GenericComponents/StringComponent/StringComponent.hpp"
#include "EntityManager/ComponentManager/GenericComponents/DoubleComponent/DoubleComponent.hpp"
#include "EntityManager/EntityManager.hpp"

int main() {
    std::array<std::uint32_t, 100> entities;
    // Engine::EntityManager::ComponentManager<int> componentManager;
    Engine::Entity::EntityManager manager;
    Engine::Entity::Component::GenericComponents::ULongComponent component(
        0, "ULongComponent", (std::uint64_t)10);
    Engine::Entity::Component::GenericComponents::StringComponent component2(
        0, "StringComponent", "Hello World");
    Engine::Entity::Component::GenericComponents::DoubleComponent component3(
        0, "DoubleComponent", (double)10.5);
    for (int i = 0; i < 1; i++) {
        entities[i] = manager.createEntity();
        manager.addComponent(manager.getEntity(i), component);
        manager.addComponent(manager.getEntity(i), component2);
        manager.addComponent(manager.getEntity(i), component3);
    }

    if (manager.hasComponent(manager.getEntity(0), "ULongComponent")) {
        std::cout << "Has ULongComponent" << std::endl;
    }

    manager.removeComponent(manager.getEntity(0), "all");

    // manager.setSignature(entities[0], );
    // std::cout << manager.getSignature(entities[0]) << std::endl;

    // manager.setSignature(entities[0], (10));
    // std::cout << manager.getSignature(entities[0]) << std::endl;

    // manager.setSignature(entities[0], (23));

    // std::cout << manager.getSignature(entities[0]) << std::endl;

    for (int i = 0; i < 1; i++) manager.destroyEntity(entities[i]); // TODO faire la gestion d'erreur pour check si la chose que je veux suppre existe bien
    // entities.clear();
    // manager.destroyEntity(entity);
    // manager.setSignature(entity, std::bitset<MAX_COMPONENTS>());
    // std::bitset<MAX_COMPONENTS> signature = manager.getSignature(entity);

    return 0;
}

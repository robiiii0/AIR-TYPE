/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

    #include <cstdint>
    #include <array>
    #include <queue>
    #include <bitset>

const std::uint32_t MAX_ENTITIES = 1000;
const std::uint8_t MAX_COMPONENTS = 32;

class EntityManager {
    public:
        EntityManager();
        std::uint32_t createEntity();
        void destroyEntity(std::uint32_t entity);
        void setSignature(std::uint32_t entity, std::bitset<MAX_COMPONENTS> signature);
        std::bitset<MAX_COMPONENTS> getSignature(std::uint32_t entity);
    private:
        std::queue<std::uint32_t> availableEntities;
        std::array<std::bitset<MAX_COMPONENTS>, MAX_ENTITIES> signatures;
        uint32_t livingEntityCount;
};

#endif /* !ENTITYMANAGER_HPP_ */

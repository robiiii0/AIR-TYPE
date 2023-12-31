/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <cstdint>
#include <string>

namespace Engine {
    namespace Entity {
        namespace Component {
            class IComponent {
                public:
                    virtual ~IComponent(){};
                    virtual void          execute() = 0;
                    virtual std::uint32_t getId() const = 0;
                    virtual void          setId(std::uint32_t id) = 0;
            };
        };  // namespace Component
    };      // namespace Entity
};          // namespace Engine

#endif /* !ICOMPONENT_HPP_ */

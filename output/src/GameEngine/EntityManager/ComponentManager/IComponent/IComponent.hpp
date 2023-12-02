/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <any>

namespace Engine {
    namespace Entity {
        namespace Component {
            class IComponent {
                public:  // TODO mettre un setName??
                    virtual ~IComponent(){};
                    // virtual std::any& get() = 0;
                    // virtual void      update() = 0;
                    virtual void          execute() = 0; // TODO: check if it
                    // is needed virtual std::uint32_t getId() const = 0;
                    // virtual void          setId(std::uint32_t id) = 0;
                    virtual std::string getName() const = 0;
            };
        };  // namespace Component
    };      // namespace Entity
};          // namespace Engine

#endif /* !ICOMPONENT_HPP_ */

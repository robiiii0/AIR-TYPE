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
                public:
                    virtual std::any get();
                    virtual void     execute();
            };
        };  // namespace Component
    };      // namespace Entity
};          // namespace Engine

#endif /* !ICOMPONENT_HPP_ */

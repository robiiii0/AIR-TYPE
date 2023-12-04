/*
** EPITECH PROJECT, 2023
** output
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "../IComponent/IComponent.hpp"
#include <cstdint>


namespace Engine {
    namespace Entity {
        namespace Component {
            class AComponent : public IComponent {
            public:
                virtual ~AComponent() {};
                std::uint32_t getId() const override;
                void setId(std::uint32_t id) override;
            private:
                std::uint32_t _id;
            };
        };
    };
};

#endif /* !ACOMPONENT_HPP_ */

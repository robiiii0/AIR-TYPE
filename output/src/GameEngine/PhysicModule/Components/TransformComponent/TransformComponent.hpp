/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** PositionComponent
*/

#ifndef POSITIONCOMPONENT_HPP_
#define POSITIONCOMPONENT_HPP_

#include <utility>

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"
#include "../../Vector2f/Vector2f.hpp"

namespace Engine {
    namespace Physic {
        namespace Components {
            struct TransformData {
                    Vector2f pos;
                    Vector2f scale;
                    float    rotation;
            };

            class TransformComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    TransformComponent(TransformData &data);
                    ~TransformComponent();
                    void           execute() override;
                    void           setTransform(TransformData &data);
                    void           setPos(Vector2f pos);
                    void           setScale(Vector2f scale);
                    void           setRotation(float rotation);
                    TransformData &getTransform();

                protected:
                private:
                    TransformData &_data;
            };
        };  // namespace Components
    };      // namespace Physic
};          // namespace Engine

#endif /* !POSITIONCOMPONENT_HPP_ */

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
                    Engine::Physic::Vector2f pos;
                    Engine::Physic::Vector2f scale;
                    float                    rotation;
            };

            class TransformComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    TransformComponent(TransformData &data);
                    ~TransformComponent();
                    void           execute() override;
                    void           setTransform(TransformData &data);
                    void           setPos(Engine::Physic::Vector2f pos);
                    void           setPos(float x, float y);
                    void           setScale(Engine::Physic::Vector2f scale);
                    void           setRotation(float rotation);
                    TransformData &getTransform();
                    Engine::Physic::Vector2f getPos() const;
                    Engine::Physic::Vector2f getScale() const;
                    float                    getRotation() const;

                protected:
                private:
                    TransformData           &_data;
                    Engine::Physic::Vector2f _pos;
                    Engine::Physic::Vector2f _scale;
                    float                    _rotation;
            };
        };  // namespace Components
    };      // namespace Physic
};          // namespace Engine

#endif /* !POSITIONCOMPONENT_HPP_ */

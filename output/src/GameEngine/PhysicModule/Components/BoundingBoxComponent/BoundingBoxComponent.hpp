/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** BoundingBoxComponent
*/

#ifndef BOUNDINGBOXCOMPONENT_HPP_
#define BOUNDINGBOXCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"
#include "../../Vector2f/Vector2f.hpp"

namespace Engine {
    namespace Physic {
        namespace Components {
            struct HitboxData {
                    Vector2f pos;
                    Vector2f size;
            };

            class BoundingBoxComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    BoundingBoxComponent(HitboxData &data);
                    ~BoundingBoxComponent();
                    void        execute() override;
                    void        setBoundingBox(HitboxData &data);
                    HitboxData &getBoundingBox();

                protected:
                private:
                    HitboxData &_data;
            };
        };  // namespace Components
    };      // namespace Physic
};          // namespace Engine

#endif /* !BOUNDINGBOXCOMPONENT_HPP_ */

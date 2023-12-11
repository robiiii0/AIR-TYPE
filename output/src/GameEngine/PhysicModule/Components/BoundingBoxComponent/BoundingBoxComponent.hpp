/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** BoundingBoxComponent
*/

#ifndef BOUNDINGBOXCOMPONENT_HPP_
#define BOUNDINGBOXCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace Physic {
        namespace Components {
            struct Data {
                    std::pair<float, float> _pos;
                    std::pair<float, float> _size;
            };

            template<typename T>
            class BoundingBoxComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    BoundingBoxComponent(Data data);
                    ~BoundingBoxComponent();
                    void        execute() override;
                    std::string getName() const override;
                    void        setBoundingBox(Data data);

                protected:
                private:
                    T           data;
                    std::string _component_name;
            };
        };  // namespace Components
    };      // namespace Physic
};          // namespace Engine

#endif /* !BOUNDINGBOXCOMPONENT_HPP_ */

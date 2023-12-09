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
            class BoundingBoxComponent : public Engine::Entity::Component::AComponent{
                public:
                    BoundingBoxComponent(std::any value);
                    ~BoundingBoxComponent();

                    void execute() override;
                    std::any& get() override;
                    std::string getName() const override;

                    void setBoundingBox(std::pair<std::pair<float, float>, std::pair<int, int>> pos);
                protected:
                private:
                    std::pair<float, float> _pos;
                    std::pair<float, float> _size;
                    std::string _component_name;
                    std::any _value;
            };
        };
    };
};

#endif /* !BOUNDINGBOXCOMPONENT_HPP_ */

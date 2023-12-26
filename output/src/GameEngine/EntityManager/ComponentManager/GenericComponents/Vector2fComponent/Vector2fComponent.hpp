//
// Created by aymericchaverot on 26/12/23.
//

#ifndef NETWORKING_VECTOR2FCOMPONENT_HPP
#define NETWORKING_VECTOR2FCOMPONENT_HPP

#include "../../AComponent/AComponent.hpp"

namespace Engine {
    namespace Entity {
        namespace Component {
            namespace GenericComponents {
                struct Vector2f {
                        float x;
                        float y;
                };

                class Vector2fComponent : public AComponent {
                    public:
                        Vector2fComponent(Vector2f &data);
                        ~Vector2fComponent();

                        void     setValue(Vector2f &value);
                        Vector2f getValue() const;

                        void execute() override;

                    private:
                        Vector2f _value;
                };

                typedef Vector2fComponent PositionComponent;
            }  // namespace GenericComponents
        }  // namespace Component
    }  // namespace Entity
};     // namespace Engine

#endif  // NETWORKING_VECTOR2FCOMPONENT_HPP

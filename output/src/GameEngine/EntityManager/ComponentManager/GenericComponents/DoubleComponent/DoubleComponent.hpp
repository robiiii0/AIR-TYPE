/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** DoubleComponent
*/

#ifndef DOUBLECOMPONENT_HPP_
#define DOUBLECOMPONENT_HPP_

#include <cstdint>
#include <string>

#include "../../AComponent/AComponent.hpp"

namespace Engine {
    namespace Entity {
        namespace Component {
            namespace GenericComponents {

                class DoubleComponent : public AComponent {
                    public:
                        DoubleComponent(double data);
                        ~DoubleComponent();
                        void execute() override;

                    private:
                        double _value;
                };
            }  // namespace GenericComponents
        }      // namespace Component
    }          // namespace Entity
}  // namespace Engine

#endif /* !DOUBLECOMPONENT_HPP_ */

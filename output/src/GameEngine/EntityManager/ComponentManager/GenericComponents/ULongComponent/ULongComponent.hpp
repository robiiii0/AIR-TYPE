/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** ULongComponent
*/

#ifndef ULONGCOMPONENT_HPP_
#define ULONGCOMPONENT_HPP_

#include <any>
#include <cstdint>
#include <iostream>

#include "../../AComponent/AComponent.hpp"

namespace Engine {
    namespace Entity {
        namespace Component {
            namespace GenericComponents {
                class ULongComponent : public AComponent {
                    public:
                        ULongComponent(unsigned long data);
                        ~ULongComponent();

                        void execute() override;

                    private:
                        unsigned long _value;
                };
            }  // namespace GenericComponents
        }      // namespace Component
    }          // namespace Entity
};             // namespace Engine

#endif /* !ULONGCOMPONENT_HPP_ */

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
                template <typename T>
                class ULongComponent : public AComponent {
                    public:
                        ULongComponent(ulong data);
                        ~ULongComponent();

                        void        execute() override;
                        std::string getName() const override;

                    private:
                        std::string   _component_name;
                        T      _value;
                };
            }  // namespace GenericComponents
        }      // namespace Component
    }          // namespace Entity
};             // namespace Engine

#endif /* !ULONGCOMPONENT_HPP_ */

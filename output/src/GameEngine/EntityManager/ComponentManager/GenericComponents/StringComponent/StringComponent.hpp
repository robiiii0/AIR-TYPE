/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** StringComponent
*/

#ifndef STRINGCOMPONENT_HPP_
#define STRINGCOMPONENT_HPP_

#include <string>

#include "../../AComponent/AComponent.hpp"

namespace Engine {
    namespace Entity {
        namespace Component {
            namespace GenericComponents {
                class StringComponent : public AComponent {
                    public:
                        StringComponent(std::string data);
                        ~StringComponent();

                        void execute() override;

                    private:
                        std::string _value;
                };
            }  // namespace GenericComponents
        }      // namespace Component
    }          // namespace Entity
}  // namespace Engine

#endif /* !STRINGCOMPONENT_HPP_ */

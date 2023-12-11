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
                template <typename T>
                class StringComponent : public AComponent {
                    public:
                        StringComponent(std::string value);
                        ~StringComponent();

                        void        execute() override;
                        std::string getName() const override;

                    private:
                        std::string   _component_name;
                        T _data;
                };
            }  // namespace GenericComponents
        }      // namespace Component
    }          // namespace Entity
}  // namespace Engine

#endif /* !STRINGCOMPONENT_HPP_ */

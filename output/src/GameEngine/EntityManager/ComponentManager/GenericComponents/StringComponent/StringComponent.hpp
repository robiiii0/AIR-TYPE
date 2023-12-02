/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** StringComponent
*/

#ifndef STRINGCOMPONENT_HPP_
#define STRINGCOMPONENT_HPP_

#include <string>

#include "../../IComponent/IComponent.hpp"

namespace Engine {
    namespace Entity {
        namespace Component {
            namespace GenericComponents {
                class StringComponent : public IComponent {
                    public:
                        StringComponent(std::uint32_t id,
                                        std::string   component_name,
                                        std::string   value) :
                            _id(id),
                            _component_name(component_name),
                            _value(value) {}

                        ~StringComponent();
                        void execute() override;
                        // std::string   get();
                        // std::uint32_t getId() const;
                        // void          setId(std::uint32_t id);
                        std::string getName() const override;

                    private:
                        std::uint32_t _id;
                        std::string   _component_name;
                        std::string   _value;
                };
            }  // namespace GenericComponents
        }      // namespace Component
    }          // namespace Entity
}  // namespace Engine

#endif /* !STRINGCOMPONENT_HPP_ */

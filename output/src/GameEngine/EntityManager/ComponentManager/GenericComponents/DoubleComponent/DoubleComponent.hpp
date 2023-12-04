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

#include "../../IComponent/IComponent.hpp"

namespace Engine {
    namespace Entity {
        namespace Component {
            namespace GenericComponents {
                class DoubleComponent : public IComponent {
                    public:
                        DoubleComponent(std::uint32_t id,
                                        std::string   component_name,
                                        double        value) :
                            _id(id),
                            _component_name(component_name),
                            _value(value) {}

                        ~DoubleComponent();
                        void execute() override;
                        std::any&        get();
                        // std::uint32_t getId() const;
                        // void          setId(std::uint32_t id);
                        std::string getName() const override;

                    private:
                        std::uint32_t _id;
                        std::string   _component_name;
                        std::any        _value;
                };
            }  // namespace GenericComponents
        }      // namespace Component
    }          // namespace Entity
}  // namespace Engine

#endif /* !DOUBLECOMPONENT_HPP_ */

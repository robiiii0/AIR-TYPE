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

namespace Engine
{
namespace Entity
{
namespace Component
{
namespace GenericComponents
{
class DoubleComponent : public AComponent {
   public:
    DoubleComponent(std::uint32_t id, std::string component_name, double value)
        : _id(id), _component_name(component_name), _value(value)
    {}

    ~DoubleComponent();
    void execute() override;
    std::any& get();
    std::string getName() const override;

   private:
    std::uint32_t _id;
    std::string _component_name;
    std::any _value;
};
}  // namespace GenericComponents
}  // namespace Component
}  // namespace Entity
}  // namespace Engine

#endif /* !DOUBLECOMPONENT_HPP_ */

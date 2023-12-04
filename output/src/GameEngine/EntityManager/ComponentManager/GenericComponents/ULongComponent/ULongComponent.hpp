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

namespace Engine
{
namespace Entity
{
namespace Component
{
namespace GenericComponents
{
class ULongComponent : public AComponent {
   public:
    ULongComponent(std::uint32_t id, std::string component_name, std::any value)
        : _id(id), _component_name(component_name), _value(value)
    {}

    ~ULongComponent();
    void execute() override;
    std::any& get() override;
    std::string getName() const override;

   private:
    std::uint32_t _id;
    std::string _component_name;
    std::any _value;
};
}  // namespace GenericComponents
}  // namespace Component
}  // namespace Entity
};  // namespace Engine

#endif /* !ULONGCOMPONENT_HPP_ */

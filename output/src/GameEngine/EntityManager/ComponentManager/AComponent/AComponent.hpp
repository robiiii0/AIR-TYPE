/*
** EPITECH PROJECT, 2023
** output
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <cstdint>
#include "../IComponent/IComponent.hpp"

namespace Engine
{
namespace Entity
{
namespace Component
{
class AComponent : public IComponent {
   public:
    virtual ~AComponent(){};
    std::uint32_t getId() const override;
    void setId(std::uint32_t id) override;

   private:
    std::uint32_t _id;
};
};  // namespace Component
};  // namespace Entity
};  // namespace Engine

#endif /* !ACOMPONENT_HPP_ */

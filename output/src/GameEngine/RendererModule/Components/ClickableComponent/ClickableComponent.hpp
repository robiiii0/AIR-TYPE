/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** ClickableComponent
*/

#ifndef CLICKABLECOMPONENT_HPP_
#define CLICKABLECOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct ClickableData {
                    bool isHovered;
                    bool isClicked;
            };

            template<typename T>
            class ClickableComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    ClickableComponent(T value);
                    ~ClickableComponent();
                    void        execute() override;
                    std::string getName() const override;

                    void update();
                    bool isHovered() const;
                    bool isClicked() const;

                protected:
                private:
                    ClickableData _data;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !CLICKABLECOMPONENT_HPP_ */

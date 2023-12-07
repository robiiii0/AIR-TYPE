/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** WindowComponent
*/

#ifndef WINDOWCOMPONENT_HPP_
#define WINDOWCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/IComponent/IComponent.hpp"


namespace Engine {
    namespace RendererModule {
        namespace Components {
            class WindowComponent : public Engine::Entity::Component::IComponent{
                public:
                    WindowComponent();
                    ~WindowComponent();

                    void execute() override;
                    std::any& get() override;
                    std::string getName() const override;

                    void setSize(sf::Vector2u size, sf::window window);
                    void setFramerateLimit(unsigned int limit, sf::window window);
                    void setVerticalSyncEnabled(bool enabled, sf::window window);
                    void setTitle(std::string title, sf::window window);

                    sf::Vector2u getSize(sf::window window) const;
                    bool isFocus(sf::window window) const ;

                protected:
                private:
            };
        };
    };
};

#endif /* !WINDOWCOMPONENT_HPP_ */

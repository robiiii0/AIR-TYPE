#ifndef SPRITECOMPONENT_HPP_
#define SPRITECOMPONENT_HPP_

#include <SFML/Graphics.hpp>

#include "../../../EntityManager/ComponentManager/GenericComponents/Vector2fComponent/Vector2fComponent.hpp"
#include "../../IRendererComponent/IRendererComponent.hpp"

namespace Engine {
    namespace RendererModule {
        namespace Components {
            struct ShotData {
                    sf::Sprite   _sprite;
                    sf::Vector2f pos;
            };

            class ShotComponent :
                public Engine::RendererModule::IRendererComponent {
                public:
                    ShotComponent(
                        ShotData  &value,
                        sf::Texture &texture);
                    ~ShotComponent();

                    void execute() override;

                    void          handleEvent(int key);
                    sf::Drawable &getDrawable() override;

                protected:
                private:
                    sf::Vector2f _pos;
                    sf::Sprite   _sprite;
            };
        };  // namespace Components
    };      // namespace RendererModule
};          // namespace Engine

#endif /* !SPRITECOMPONENT_HPP_ */

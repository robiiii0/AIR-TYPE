/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** AttackComponent
*/

#ifndef ATTACKCOMPONENT_HPP_
#define ATTACKCOMPONENT_HPP_

#include "../../../EntityManager/ComponentManager/AComponent/AComponent.hpp"

namespace Engine {
    namespace MobModule {
        namespace Components {
            struct AttackComponentData {
                    int   Damage;
                    float Range;
                    float AttackSpeed;
                    int   AttackType;
            };

            class AttackComponent :
                public Engine::Entity::Component::AComponent {
                public:
                    AttackComponent(AttackComponentData data);
                    ~AttackComponent();
                    void                 execute() override;
                    AttackComponentData &getValue();
                    void                 setValue(AttackComponentData value);
                    void                 setDamage(int value);
                    void                 setRange(float value);
                    void                 setAttackSpeed(float value);
                    void                 setAttackType(int value);
                    int                  getDamage() const;
                    float                getRange() const;
                    float                getAttackSpeed() const;
                    int                  getAttackType() const;

                protected:
                private:
                    AttackComponentData _value;
            };
        }  // namespace Components
    }      // namespace MobModule
}  // namespace Engine

#endif /* !ATTACKCOMPONENT_HPP_ */

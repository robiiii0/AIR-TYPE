/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** Vector2f
*/

#ifndef VECTOR2F_HPP_
#define VECTOR2F_HPP_

namespace Engine {
    namespace Physic {
        struct Vector2f {
                float x;
                float y;

                Vector2f operator+(const Vector2f &other) const {
                    return {this->x + other.x, this->y + other.y};
                }
        };
    }  // namespace Physic
}  // namespace Engine

#endif /* !VECTOR2F_HPP_ */

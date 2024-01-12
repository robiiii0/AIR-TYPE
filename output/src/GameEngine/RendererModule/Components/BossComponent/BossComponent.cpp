#include "BossComponent.hpp"

Engine::RendererModule::Components::BossComponent::BossComponent(
    BossData &value, sf::Texture &texture) {
    sf::Sprite Sprite;
    _sprite = Sprite;
    _pos = value.pos;
    _scale = value.scale;
    _color = value.color;
    _rotation = value.rotation;
    _rect = value.rect;

    _sprite.setTexture(texture);
    _sprite.setTextureRect(_rect);
    _sprite.setPosition(_pos.x, _pos.y);
    _sprite.setScale(_scale.x, _scale.y);
    _sprite.setColor(_color);
    _sprite.setRotation(_rotation);
}

Engine::RendererModule::Components::BossComponent::~BossComponent() {}

void Engine::RendererModule::Components::BossComponent::execute() {}

sf::Drawable &Engine::RendererModule::Components::BossComponent::getDrawable() {
    return _sprite;
}

void Engine::RendererModule::Components::BossComponent::setRotation(
    float rotation) {
    _sprite.setRotation(rotation);
}

void Engine::RendererModule::Components::BossComponent::setScale(float x,
                                                                 float y) {
    _sprite.setScale(x, y);
}

void Engine::RendererModule::Components::BossComponent::setTextureRect() {
    if (_rect.left < 668) {
        _rect.left += 167;
    } else {
        if (_rect.top < 1926) {
            _rect.top += 214;
            _rect.left = 0;
        } else {
            _rect.top = 0;
        }
    }
    _sprite.setTextureRect(_rect);
}

void Engine::RendererModule::Components::BossComponent::setPosition(float x,
                                                                    float y) {
    _sprite.setPosition(x, y);
}

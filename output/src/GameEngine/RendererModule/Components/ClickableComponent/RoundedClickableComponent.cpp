//
// Created by Robin Chabert on 23/12/2023.
//

#include "RoundedClickableComponent.hpp"


Engine::RendererModule::Components::RoundedClickableComponent::RoundedClickableComponent(RoundedClickableData &value) : _data(value), _isHovered(false), _isClicked(false) {
                
                sf::RectangleShape shape(sf::Vector2f(value._size.first, value._size.second));
                buttonShape = shape;
                // Initialiser les paramètres du bouton avec des bords arrondis et un fond blanc
                buttonShape.setPosition(_data._pos.first, _data._pos.second);
                buttonShape.setSize(sf::Vector2f(_data._size.first, _data._size.second));
                buttonShape.setFillColor(_data._color);  // Fond blanc
                buttonShape.setOutlineColor(sf::Color::Black);  // Couleur de la bordure
                buttonShape.setOutlineThickness(2.0f);  // Épaisseur de la bordure
                std::cout << "ClickableComponent created" << std::endl;
}

Engine::RendererModule::Components::RoundedClickableComponent::~RoundedClickableComponent() {}

void Engine::RendererModule::Components::RoundedClickableComponent::execute() {}

sf::Drawable &Engine::RendererModule::Components::RoundedClickableComponent::getDrawable() {
    return buttonShape;
}

void Engine::RendererModule::Components::RoundedClickableComponent::update() {

}

sf::Vector2f Engine::RendererModule::Components::RoundedClickableComponent::getPos() const {
}

bool Engine::RendererModule::Components::RoundedClickableComponent::isHovered(
    std::pair<float, float> mousePos) {
    sf::FloatRect bounds = buttonShape.getGlobalBounds();

    if (bounds.contains(mousePos.first, mousePos.second)) {
        buttonShape.setFillColor(sf::Color::Red);
        return true;
    } else {
        buttonShape.setFillColor(_data._color);
        return false;
    }
    return _isClicked;
}

bool Engine::RendererModule::Components::RoundedClickableComponent::isClicked(
    std::pair<float, float> mousePos) {
    sf::FloatRect bounds = buttonShape.getGlobalBounds();

    if (bounds.contains(mousePos.first, mousePos.second)) {
        return true;
    } else {
        return false;
    }
    return _isClicked;
}
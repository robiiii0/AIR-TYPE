/*
** EPITECH PROJECT, 2023
** AIR-TYPE
** File description:
** ClickableComponent
*/

#include "ClickableComponent.hpp"

#include <stdexcept>

Engine::RendererModule::Components::ClickableComponent::ClickableComponent(
    ClickableData value) {
    _data.isClicked = value.isClicked;
    _data.isHovered = value.isHovered;
}

Engine::RendererModule::Components::ClickableComponent::~ClickableComponent() {}

void Engine::RendererModule::Components::ClickableComponent::execute() {}

void Engine::RendererModule::Components::ClickableComponent::update() {
    // TODO: MousePosition and Entity position in parameters ?
    // Get MousePosition
    // Get Entity Position

    // Check if MousePosition is in Entity Position
    // Update _data.isHovered

    // Check if Mouse is clicked
    // Update _data.isClicked
}

bool Engine::RendererModule::Components::ClickableComponent::isHovered()
    const {
    return _data.isHovered;
}

bool Engine::RendererModule::Components::ClickableComponent::isClicked()
    const {
    return _data.isClicked;
}

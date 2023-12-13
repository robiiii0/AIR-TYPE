/*
** EPITECH PROJECT, 2023
** AIR-TYPE [Codespaces: studious memory]
** File description:
** WindowComponent
*/

#include "./Window.hpp"

Engine::RendererModule::Window::Window() = default;

Engine::RendererModule::Window::~Window() = default;

void Engine::RendererModule::Window::setSize(sf::Vector2u size,
                                             sf::Window   window) {
    window.setSize(size);
}

void Engine::RendererModule::Window::setFramerateLimit(unsigned int limit,
                                                       sf::Window   window) {
    window.setFramerateLimit(limit);
}

void Engine::RendererModule::Window::setVerticalSyncEnabled(bool       enabled,
                                                            sf::Window window) {
    window.setVerticalSyncEnabled(enabled);
}

void Engine::RendererModule::Window::setTitle(std::string title,
                                              sf::Window  window) {
    window.setTitle(title);
}

sf::Vector2u Engine::RendererModule::Window::getSize(sf::Window window) const {
    return (window.getSize());
}

bool Engine::RendererModule::Window::isFocus(sf::Window window) const {
    return (window.hasFocus());
}

void Engine::RendererModule::Window::setIcon(sf::Image  icon,
                                             sf::Window window) {
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void Engine::RendererModule::Window::setMouseCursorVisible(bool       visible,
                                                           sf::Window window) {
    window.setMouseCursorVisible(visible);
}

void Engine::RendererModule::Window::setMouseCursorGrabbed(bool       grabbed,
                                                           sf::Window window) {
    window.setMouseCursorGrabbed(grabbed);
}

void Engine::RendererModule::Window::setKeyRepeatEnabled(bool       enabled,
                                                         sf::Window window) {
    window.setKeyRepeatEnabled(enabled);
}

void Engine::RendererModule::Window::requestFocus(sf::Window window) {
    window.requestFocus();
}

sf::WindowHandle Engine::RendererModule::Window::getSystemHandle(
    sf::Window window) const {
    return (window.getSystemHandle());
}

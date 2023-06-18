#include "button.h"
#include <SFML/Graphics.hpp>
#include <functional>

void Button::update(sf::RenderWindow& window) {
    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

    if (shape_.getGlobalBounds().contains(mousePosition)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            currentState_ = Pressed;
            shape_.setFillColor(activeColor_);
        } else {
            currentState_ = Hover;
            shape_.setFillColor(hoverColor_);
        }
    } else {
        currentState_ = Idle;
        shape_.setFillColor(idleColor_);
    }
}

void Button::render(sf::RenderWindow& window) {
    window.draw(shape_);
}

void Button::setOnClick(std::function<void()> onClick) {
    onClick_ = onClick;
}
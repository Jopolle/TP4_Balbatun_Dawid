#include <SFML/Graphics.hpp>
#include <functional>

class Button {
public:
    Button(sf::Vector2f position, sf::Vector2f size, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
            : position_(position),
              size_(size),
              idleColor_(idleColor),
              hoverColor_(hoverColor),
              activeColor_(activeColor),
              currentState_(Idle) {
        shape_.setPosition(position_);
        shape_.setSize(size_);
        shape_.setFillColor(idleColor_);
    }

    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void setOnClick(std::function<void()> onClick);

private:
    enum State {
        Idle,
        Hover,
        Pressed
    };
    sf::RectangleShape shape_;
    sf::Vector2f position_;
    sf::Vector2f size_;
    sf::Color idleColor_;
    sf::Color hoverColor_;
    sf::Color activeColor_;
    State currentState_;
    std::function<void()> onClick_;
};

#pragma once
#include <SFML/Graphics.hpp>
const float SCREEN_HEIGHT = 800;
const float SCREEN_WIDTH = 1200;


class arm
{
private:
    sf::Vector2f origin;
    sf::Vector2f end;
    sf::RectangleShape shape;
    float length, theta;
public:
    arm(sf::Vector2f origin, sf::Vector2f end);

    float getLength() const;
    sf::Vector2f getOrigin() const;
    sf::Vector2f getEnd() const;
    void setOrigin(sf::Vector2f newOrigin);
    void setEnd(sf::Vector2f newEnd);
    void draw(sf::RenderWindow& window);
};
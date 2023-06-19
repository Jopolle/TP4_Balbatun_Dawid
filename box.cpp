#include "Box.h"
#include <vector>

Box::Box(sf::Vector2f size, float weight, sf::RenderWindow& window)
        : size(size), weight(weight), window(window)
{
    box.setSize(size);
    box.setFillColor(sf::Color::Red);
}

std::vector<Box> boxes;

bool Box::checkCollision(const sf::RectangleShape& rect1, const sf::RectangleShape& rect2)
{
    sf::FloatRect bounds1 = rect1.getGlobalBounds();
    sf::FloatRect bounds2 = rect2.getGlobalBounds();

    return bounds1.intersects(bounds2);
}

void Box::setPosition(sf::Vector2f position)
{
    box.setPosition(position);
}

void Box::applyGravity(float deltaTime)
{
    velocity.y += gravity * weight * deltaTime;
}

void Box::update(float deltaTime)
{
    applyGravity(deltaTime);
    sf::Vector2f newPosition = box.getPosition() + (velocity * deltaTime);

    if (newPosition.y + size.y > window.getSize().y)
    {
        newPosition.y = window.getSize().y - size.y;
        velocity.y = 0.0f;
    }

//    // Zatrzymaj ruch pudełka po kolizji
//    for ( auto& otherBox : boxes)
//    {
//        if (&otherBox != this)
//        {
//            if (checkCollision(box, otherBox.getShape()))
//            {
//                velocity = sf::Vector2f(0.0f, 0.0f);
//                break;
//            }
//        }
//    }

    box.setPosition(newPosition);
}

void Box::draw()
{
    window.draw(box);
}

sf::RectangleShape& Box::getShape()
{
    return box;
}
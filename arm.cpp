#include "arm.h"


arm::arm(sf::Vector2f origin, sf::Vector2f end)
        : origin(origin), end(end)
{
    // Create the shape for the robot arm
    sf::Vector2f direction = end - origin;
    theta = atan2(direction.y, direction.x) * 180.f / 3.14159f;
    length = ARM_LENGTH;

    shape.setSize(sf::Vector2f(length, 10.f));
    shape.setOrigin(0.f, 2.5f);
    shape.setPosition(origin);
    shape.setRotation(theta);  // Set initial rotation

    shape.setFillColor(sf::Color(120,120,130));  // Set color
}
void arm::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
sf::Vector2f arm::getOrigin() const { return origin; }
sf::Vector2f arm::getEnd() const { return end; }
void arm::setOrigin(sf::Vector2f newOrigin) {
    origin = newOrigin;
    shape.setPosition(origin);
}
void arm::setEnd(sf::Vector2f newEnd) {
    end = newEnd;
    sf::Vector2f direction = end - origin;
    theta = atan2(direction.y, direction.x) * 180.f / 3.14159f;
    shape.setRotation(theta);
}
float arm::getLength() const {return length; }
void arm::setLength(float newLength) {length = newLength;}
float arm::getTheta() const {return theta;}
void arm::setTheta(float newTheta) {theta = newTheta;}
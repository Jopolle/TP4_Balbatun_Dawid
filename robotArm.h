#pragma once
#include "arm.h"

class robotArm {
private:
    sf::Vector2f mid, destination;
    sf::Vector2f const origin;
    float alpha, y1, x1, a, beta;
public:
    arm a1, a2, a3;
    robotArm(sf::Vector2f origin, sf::Vector2f destination);
    void calculatePosition();
    void update();
    void setDestination(sf::Vector2f newDestination);
    void draw(sf::RenderWindow& window);

};



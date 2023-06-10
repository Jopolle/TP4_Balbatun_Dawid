#pragma once
#include <SFML/Graphics.hpp>
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;


class arm
{
private:
    float x1, y1, l, x2, y2;
    sf::RectangleShape
public:
    arm();
    arm(float x1, float y1, float l, float x2, float y2);
    float getX();
    float getY();
    float getAnchorX();
    float getAnchorY();
    float getLength();
};
//
// Created by pablitto on 16.06.23.
//
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
const float SCREEN_HEIGHT = 800;
const float SCREEN_WIDTH = 1200;
const float HEIGHT_CONST = SCREEN_HEIGHT - 10;
const float WIDTH_CONST = SCREEN_WIDTH/5;
const float ARM_LENGTH = 300;
const float SPEED = 6;
#pragma once

class box {
private:
    float gravity, mass, width, height;
    sf::Vector2f position;
    sf::RectangleShape visual;

public:
    box(sf::Vector2f position);
    void setGravity(float newGravity);
    void setMass(float newMass);
    void setPosition(sf::Vector2f newPosition);
    float getGravity();
    float getMass();
    sf::Vector2f getPosition();
    void update();

    
};



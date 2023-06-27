#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
const float SCREEN_HEIGHT = 800;
const float SCREEN_WIDTH = 1200;
const float HEIGHT_CONST = SCREEN_HEIGHT - 10;
const float WIDTH_CONST = SCREEN_WIDTH/5;
const float ARM_LENGTH = 350;
#pragma once

//class box {
//private:
//    float gravity, mass, width, height;
//    sf::Vector2f position;
//    sf::RectangleShape visual;
//
//public:
//    box(sf::Vector2f position);
//    void setGravity(float newGravity);
//    void setMass(float newMass);
//    void setPosition(sf::Vector2f newPosition);
//    float getGravity();
//    float getMass();
//    sf::Vector2f getPosition();
//    void update();
//};

#include <SFML/Graphics.hpp>

class Box
{
public:
    Box(sf::Vector2f size, float weight, sf::RenderWindow& window);
    void setPosition(sf::Vector2f position);
    void applyGravity(float deltaTime);
    void update(float deltaTime);
    void draw();
    sf::Vector2f velocity;
    float gravity = 9.8f;
    sf::RectangleShape& getShape();
    bool checkCollision(const sf::RectangleShape& rect1, const sf::RectangleShape& rect2);
private:
    sf::RectangleShape box;
    sf::Vector2f size;
    float weight;

    sf::RenderWindow& window;
};
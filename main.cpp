#include <iostream>
#include <cmath>
#include "robotArm.h"
/*
 * TODO:
 *  -figure out equations for moving the arms (then build the class again)
 *  -implement limitations for arm movement(theta)
 *  -add ability to be programmed
 */


int main()
{
    float speed = 3, rad = 200;
    sf::Vector2f position, origin = {WIDTH_CONST, HEIGHT_CONST}, initialPos = {WIDTH_CONST, HEIGHT_CONST - 100};
    arm a1(origin, initialPos);
    a1.setLength(rad/2);





    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Mr.Robot feat. Rami Malek");

    sf::CircleShape destination(5.0f);
    destination.setFillColor(sf::Color::Green);
    destination.setPosition(origin);



    sf::CircleShape anchor(5.0f);
    anchor.setFillColor(sf::Color::Red);
    anchor.setPosition(WIDTH_CONST, HEIGHT_CONST);

    const float targetFPS = 60.0f;
    sf::Time targetFrameTime = sf::seconds(1.0f / targetFPS);
    sf::Clock clock;

    while (window.isOpen())
    {
        position = destination.getPosition();
        a1.setEnd(position);
        sf::Time start = clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        float grzegorian = std::pow(position.x - WIDTH_CONST, 2) + std::pow(SCREEN_HEIGHT - position.y, 2), wszolkowian = std::pow(rad, 2);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && grzegorian<wszolkowian)
            destination.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && position.x > WIDTH_CONST)
            destination.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && position.y < HEIGHT_CONST)
            destination.move(0, speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && grzegorian<wszolkowian)
            destination.move(speed, 0);
        

        window.draw(destination);
        window.draw(anchor);
        a1.draw(window);
        window.display();
        sf::Time frameTime = clock.getElapsedTime() - start;
        if (frameTime < targetFrameTime)
        {
            sf::sleep(targetFrameTime - frameTime);
        }
    }





    return 0;
}

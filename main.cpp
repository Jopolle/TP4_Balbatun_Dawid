#include <iostream>
#include "robotArm.h"
/*
 * TODO:
 *  -generate anchor and destination point
 *  -figure out equations for moving the arms (then build the class again)
 *  -limit the anchor point depending on arm a.l
 *  -implement limitations for arm movement(theta)
 *  -add ability to be programmed
 */


int main()
{
    float speed = 3;
    sf::Vector2f position, origin = {SCREEN_WIDTH/4, SCREEN_HEIGHT - 10}, initialPos = {SCREEN_WIDTH/4, SCREEN_HEIGHT - 110};
    arm a1(origin, initialPos);
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Mr.Robot feat. Rami Malek");

    sf::CircleShape destination(5.0f);
    destination.setFillColor(sf::Color::Green);
    destination.setPosition(origin);



    sf::CircleShape anchor(5.0f);
    anchor.setFillColor(sf::Color::Red);
    anchor.setPosition(SCREEN_WIDTH/4, SCREEN_HEIGHT-10);

    const float targetFPS = 60.0f;
    sf::Time targetFrameTime = sf::seconds(1.0f / targetFPS);
    sf::Clock clock;

    while (window.isOpen())
    {
        position = destination.getPosition();
        a1.setEnd(position);
        sf::Time start = clock.getElapsedTime();
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            destination.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            destination.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            destination.move(0, speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
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

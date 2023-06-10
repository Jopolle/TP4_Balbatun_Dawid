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
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SCREEN TEST");


    sf::CircleShape anchor(5.0f);
    anchor.setFillColor(sf::Color::Red);
    anchor.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT-10);

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.draw(anchor);
        window.display();
    }





    return 0;
}

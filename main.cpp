#include <iostream>
#include <cmath>
#include "robotArm.h"
#include "button.h"
/*
 * TODO:
 *  -add ability to be programmed
 *  -clean the fuck up
 *
 */

void drawCircleQuarter(sf::RenderWindow& window, float rad, sf::Vector2f origin);
int main()
{
    float  rad = 2*ARM_LENGTH;
    sf::Vector2f position, origin = {WIDTH_CONST, HEIGHT_CONST}, initialPos = {WIDTH_CONST, HEIGHT_CONST - 100};
    arm a1(origin, initialPos);
    a1.setLength(rad/2);
    robotArm theArm(origin, initialPos);

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Mr.Robot feat. Rami Malek");

    sf::CircleShape destination(5.0f);
    destination.setFillColor(sf::Color::Green);
    destination.setPosition(origin);

    sf::CircleShape anchor(10.0f);
    anchor.setFillColor(sf::Color::Red);
    anchor.setPosition(WIDTH_CONST - 7.0f, HEIGHT_CONST - 5.0f);

    const float targetFPS = 60.0f;
    sf::Time targetFrameTime = sf::seconds(1.0f / targetFPS);
    sf::Clock clock;

    while (window.isOpen())
    {
        position = destination.getPosition();
        theArm.setDestination(position);
        //a1.setEnd(position);
        sf::Time start = clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        Button button(sf::Vector2f(100, 100), sf::Vector2f(200, 50), sf::Color::Red, sf::Color::Green, sf::Color::Blue);

        button.setOnClick([]() {
            std::cout << "Kliknięto przycisk!" << std::endl;
        });

        float grzegorian = std::pow(position.x - WIDTH_CONST, 2) + std::pow(SCREEN_HEIGHT - position.y, 2), wszolkowian = std::pow(rad, 2);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && grzegorian<wszolkowian)
            destination.move(0, -SPEED);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && position.x > WIDTH_CONST)
            destination.move(-SPEED, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && position.y < HEIGHT_CONST)
            destination.move(0, SPEED);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && grzegorian<wszolkowian)
            destination.move(SPEED, 0);
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && position.x > WIDTH_CONST && position.y < HEIGHT_CONST && grzegorian<wszolkowian)
//            destination.move (SPEED, SPEED);
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && position.x > WIDTH_CONST && position.y < HEIGHT_CONST && grzegorian<wszolkowian)
//            destination.move (-SPEED, -SPEED);
        drawCircleQuarter(window, rad, origin);
        window.draw(anchor);
        theArm.update();
        button.update(window);
        button.render(window);
        theArm.draw(window);
        window.display();
        sf::Time frameTime = clock.getElapsedTime() - start;
        if (frameTime < targetFrameTime)
        {
            sf::sleep(targetFrameTime - frameTime);
        }
    }

    return 0;
}
void drawCircleQuarter(sf::RenderWindow& window, float rad, sf::Vector2f origin)
{
    const int pointsCount = 100;

    sf::VertexArray circle(sf::LinesStrip, pointsCount / 4 + 1);

    for (int i = 0; i <= pointsCount / 4; i++)
    {
        //if();
        float angle = i * (2 * 3.14159f / pointsCount);
        float x = cos(angle) * rad;
        float y = sin(angle) * rad;

        circle[i].position = sf::Vector2f(x + origin.x, -y + origin.y);
    }

    window.draw(circle);
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = origin;
    line[1].position = sf::Vector2f(origin.x, origin.y-rad);
    window.draw(line);
}
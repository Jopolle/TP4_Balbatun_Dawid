#include <cmath>
#include "robotArm.h"
/*
 * TODO:
 *  -add ability to be programmed
 *  -add stackable box class
 *  -program box movement and collision functions
 *  -clean the fuck up
 *
*/

void drawCircleQuarter(sf::RenderWindow& window, float rad, sf::Vector2f origin);
int main()
{
    float  rad = 2*ARM_LENGTH, grzegorian, wszolkowian, speed = 3;
    sf::Vector2f position, origin = {WIDTH_CONST, HEIGHT_CONST}, initialPos = {WIDTH_CONST, HEIGHT_CONST - 100};
    robotArm theArm(origin, initialPos);
    const float targetFPS = 100.0f;
    sf::Time targetFrameTime = sf::seconds(1.0f / targetFPS);
    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Mr.Robot feat. Rami Malek");

    sf::CircleShape destination(.0f);
    destination.setPosition(origin);

    while (window.isOpen())
    {
        position = destination.getPosition();
        grzegorian = std::pow(position.x - WIDTH_CONST, 2) + std::pow(SCREEN_HEIGHT - position.y, 2);
        wszolkowian = std::pow(rad, 2);


        theArm.setDestination(position);
        sf::Time start = clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
//            if (event.type == sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
//                std::cout<<"input new movement speed"<<std::endl;
//                std::cin >> speed;
//            }

        }

        window.clear();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
            std::cout<<"input new movement speed"<<std::endl;
            std::cin >> speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && grzegorian<wszolkowian)
            destination.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && position.x > WIDTH_CONST)
            destination.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && position.y < HEIGHT_CONST)
            destination.move(0, speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && grzegorian<wszolkowian)
            destination.move(speed, 0);

        drawCircleQuarter(window, rad, origin);
        theArm.update();
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
        float angle = i * (2 * 3.14159f / pointsCount);
        float x = cosf(angle) * rad;
        float y = sinf(angle) * rad;

        circle[i].position = sf::Vector2f(x + origin.x, -y + origin.y);
    }

    window.draw(circle);
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = origin;
    line[1].position = sf::Vector2f(origin.x, origin.y-rad);
    window.draw(line);
}
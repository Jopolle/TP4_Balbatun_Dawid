#include <cmath>
#include "robotArm.h"
#include <vector>

void drawCircleQuarter(sf::RenderWindow& window, float rad, sf::Vector2f origin);

int main()
{
    float rad = 2 * ARM_LENGTH, grzegorian, wszolkowian;
    sf::Vector2f position, origin = { WIDTH_CONST, HEIGHT_CONST }, initialPos = { WIDTH_CONST, HEIGHT_CONST - 100 };
    robotArm theArm(origin, initialPos);
    const float targetFPS = 500.0f;
    sf::Time targetFrameTime = sf::seconds(1.0f / (10.f * targetFPS));
    sf::Clock clock;
    std::vector<Box> boxes;

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

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                    Box newBox(sf::Vector2f(100.0f, 100.0f), 5.0f, window);
                    newBox.setPosition(mousePosition);
                    boxes.push_back(newBox);
                }
            }
        }

        float deltaTime = clock.restart().asSeconds();

        for (auto& box : boxes)
        {
            box.update(deltaTime);

            // Checking collision between boxes
            for (auto& otherBox : boxes)
            {
                if (&box != &otherBox) // Box don't collide with themselves
                {
                    if (box.checkCollision(box.getShape(), otherBox.getShape()))
                    {
                        // Stop box after collision
                        for (auto& otherBox : boxes)
                        {
                            if (box.checkCollision(box.getShape(), otherBox.getShape()))
                            {
                                box.velocity = sf::Vector2f(0.0f, 0.0f);
                                box.gravity = 0.f;
                                break;
                            }
                        }
                    }
                }
            }
        }

        window.clear();

        for (auto& box : boxes)
        {
            box.draw();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && grzegorian < wszolkowian)
            destination.move(0, -SPEED);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && position.x > WIDTH_CONST)
            destination.move(-SPEED, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && position.y < HEIGHT_CONST)
            destination.move(0, SPEED);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && grzegorian < wszolkowian)
            destination.move(SPEED, 0);

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


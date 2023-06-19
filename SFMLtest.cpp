#include <SFML/Graphics.hpp>
#include "box.h"
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Grawitacja i waga pudełka");

    std::vector<Box> boxes;

    sf::Clock clock;

    while (window.isOpen())
    {
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
                    Box newBox(sf::Vector2f(100.0f, 100.0f), 1.0f, window);
                    newBox.setPosition(mousePosition);
                    boxes.push_back(newBox);
                }
            }
        }

        float deltaTime = clock.restart().asSeconds();

        for (auto& box : boxes)
        {
            box.update(deltaTime);

            // Sprawdzanie kolizji między pudełkami
            for (auto& otherBox : boxes)
            {
                if (&box != &otherBox) // Pomijamy sprawdzanie kolizji ze sobą samym
                {
                    if (box.checkCollision(box.getShape(), otherBox.getShape()))
                    {
                        // Tutaj możesz dodać odpowiednią reakcję na kolizję, np. zmianę koloru pudełek itp.
                    }
                }
            }
        }

        window.clear();

        for (auto& box : boxes)
        {
            box.draw();
        }

        window.display();
    }

    return 0;
}
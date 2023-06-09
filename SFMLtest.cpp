#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::RenderWindow(sf::VideoMode(800, 600), "My window"));

    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Green);

    sf::Vector2f speed(0.1f, 0.1f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        shape.move(speed);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

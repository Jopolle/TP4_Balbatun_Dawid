#include <SFML/Graphics.hpp>

int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Dot Controller");

    // Create a circle shape to represent the dot
    sf::CircleShape dot(5.0f);
    dot.setFillColor(sf::Color::Red);
    dot.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    // Game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Update the position of the dot based on key presses
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            dot.move(0, -0.1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            dot.move(-0.1, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            dot.move(0, 0.1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            dot.move(0.1, 0);

        // Draw the dot
        window.draw(dot);

        // Update the window
        window.display();
    }

    return 0;
}


// #include <SFML/Graphics.hpp>

// int main()
// {
//     // Create the main window
//     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

//     // Create a claw shape (for simplicity, let's assume a claw is a triangle)
//     sf::ConvexShape claw;
//     claw.setPointCount(3);
//     claw.setPoint(0, sf::Vector2f(0, 0));
//     claw.setPoint(1, sf::Vector2f(0, 50));
//     claw.setPoint(2, sf::Vector2f(50, 25));

//     // Set the claw color
//     claw.setFillColor(sf::Color::White);

//     // Start the game loop
//     while (window.isOpen())
//     {
//         // Process events
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             // Close window: exit
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }

//         // Clear screen
//         window.clear();

//         // Draw the claw
//         window.draw(claw);

//         // Update the window
//         window.display();
//     }

//     return EXIT_SUCCESS;
// }

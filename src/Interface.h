#ifndef INTERFACE_H
#define INTERFACE_H

#include <SFML/Graphics.hpp>

class Interface {
private:
    sf::RenderWindow window;

public:
    Interface() : window(sf::VideoMode(800, 600), "Simulación de Cola") {}

    void update() {
        window.clear();
        window.display();
    }

    // Create a window with a title and a size of 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window if the close button is clicked
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Clear the window with a color
        window.clear(sf::Color::Black);

        // Draw stuff here (if needed)
        

        // Display the window
        window.display();
    }
};

#endif  // INTERFACE_H

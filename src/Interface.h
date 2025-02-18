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
};

#endif  // INTERFACE_H

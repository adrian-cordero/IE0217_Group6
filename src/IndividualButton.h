#ifndef Button_H
#define Button_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>
#include <chrono>
#include "VisualVisitor.h"
#include "OnScreenVisitors.h"
#include "QueueManager.h"

// Individual Button class is used to create the object that operates a the individual visitor addition button
class IndividualButton {
    private:
    sf::RectangleShape shape;
    sf::Clock clock;
    sf::Color normalColor = sf::Color::White;
    sf::Color hoverColor = sf::Color::Cyan;
    float clickTime = 0.5f;

public:
    IndividualButton () {
        // Parameters for creating the button
        shape.setSize(sf::Vector2f(100, 50));
        shape.setOutlineColor(sf::Color::Black);
        shape.setFillColor(normalColor);
        shape.setOutlineThickness(5);
        shape.setPosition(250, 250);
    }

    // Set the position of the button
    void setPosition(sf::Vector2f pos) {
        shape.setPosition(pos);
    }

    // Get the position of the button
    sf::Vector2f getPosition() const {
        return shape.getPosition();
    }

    // Draw the buitton on window
    void draw(sf::RenderWindow& window) const {
        window.draw(shape);
    }

    // Actions carried out to update the button, addition of visitors to queue happen here
    void update(const sf::RenderWindow &window, QueueManager& queueManager) {

        if (shape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            shape.setFillColor(hoverColor);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock.getElapsedTime().asSeconds() >= clickTime) {
                shape.setFillColor(sf::Color::Blue);
                queueManager.getRegularQueue().push(Visitor(-1, false, false));
                clock.restart();
            } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && clock.getElapsedTime().asSeconds() >= clickTime) {
                shape.setFillColor(sf::Color::Blue);
                queueManager.getVIPQueue().push(Visitor(-1, false, true));
                clock.restart();
            }

        } else {
            shape.setFillColor(normalColor);
        }
    }
};
0.#endif //Button_H
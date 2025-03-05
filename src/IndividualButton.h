#ifndef Button_H
#define Button_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>
#include <chrono>
#include "VisualVisitor.h"
#include "OnScreenVisitors.h"
#include "QueueManager.h"


class IndividualButton {
    private:
    sf::RectangleShape shape;
    sf::Clock clock;
    sf::Color normalColor = sf::Color::White;
    sf::Color hoverColor = sf::Color::Cyan;
    float clickTime = 3.0f;

public:
    IndividualButton () {
        shape.setSize(sf::Vector2f(100, 50));
        shape.setOutlineColor(sf::Color::Black);
        shape.setFillColor(normalColor);
        shape.setOutlineThickness(5);
        shape.setPosition(250, 250);
    }

    void setPosition(sf::Vector2f pos) {
        shape.setPosition(pos);
    }

    sf::Vector2f getPosition() const {
        return shape.getPosition();
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(shape);
    }

    void update(const sf::RenderWindow &window, QueueManager& queueManager) {

        if (shape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            shape.setFillColor(hoverColor);

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock.getElapsedTime().asSeconds() >= clickTime) {
                shape.setFillColor(sf::Color::Blue);
                queueManager.getRegularQueue().push(Visitor(-1, false, false));
                queueManager.updateVisitors();
                clock.restart();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && clock.getElapsedTime().asSeconds() >= clickTime) {
                shape.setFillColor(sf::Color::Blue);
                queueManager.getVIPQueue().push(Visitor(-1, false, true));
                queueManager.updateVisitors();
                clock.restart();
            }

        } else {
            shape.setFillColor(normalColor);
        }
    }
};
#endif //Button_H
#ifndef GroupButton_H
#define GroupButton_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include <deque>
#include <chrono>
#include "VisualVisitor.h"
#include "Group.h"
#include "QueueManager.h"
#include "OnScreenVisitors.h"
#include "QueueManager.h"

// Group Button class is used to create the object that operates a the group visitor addition button. At the end of development, the 
class GroupButton {
private:
    sf::RectangleShape shape;
    sf::Clock clock;
    sf::Color normalColor = sf::Color::White;
    sf::Color hoverColor = sf::Color::Cyan;
    float clickTime = 0.5f;
    float clickTime2 = 0.5f;

public:
    GroupButton () {
        shape.setSize(sf::Vector2f(100, 50));
        shape.setOutlineColor(sf::Color::Black);
        shape.setFillColor(normalColor);
        shape.setOutlineThickness(5);
        shape.setPosition(500, 250);
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
                queueManager.enqueueRegularGroup();
                clock.restart();
            } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && clock.getElapsedTime().asSeconds() >= clickTime) {
                shape.setFillColor(sf::Color::Blue);
                queueManager.enqueueVIPGroup();
                clock.restart();
            }

        } else {
            shape.setFillColor(normalColor);
        }
    }
    
};
#endif //GroupButton_H
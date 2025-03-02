#ifndef VisualVisitor_H
#define VisualVisitor_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Visitor {
private:
    sf::CircleShape shape;
    int id;
    int group;
    bool dummy;
    sf::Text text;
    static sf::Font font; 
    sf::Color normalColor;
    sf::Color hoverColor;
    static int totalVisitors; 

public:

    Visitor(float x, float y, int group, bool dummy) : group(group), dummy(dummy) {
        //cout << "Visitor constructor" << endl;

        this->id = totalVisitors;

        if (dummy) {
            normalColor = sf::Color::White;  
            text.setString(" ");
        } else if (group == -1) {
            normalColor = sf::Color::Green;
            text.setString("Person Id: " + std::to_string(id) + "\nGroup: N/A");
        } else {
            normalColor = sf::Color::Blue;
            text.setString("Person Id: " + std::to_string(id) + "\nGroup: " + std::to_string(group));
        }
        hoverColor = sf::Color::Cyan;

        shape.setRadius(40);
        shape.setFillColor(normalColor);
        shape.setPosition(x, y);
        shape.setOrigin(40, 40);

        static bool fontLoaded = false;
        if (!fontLoaded) {
            if (!font.loadFromFile("fonts/Roboto-Regular.ttf")) {
                std::cerr << "Error: Failed to load font from fonts/Roboto-Regular.ttf" << std::endl;
            } else {
                fontLoaded = true;
                std::cout << "Font loaded successfully." << std::endl;
            }
        }
       
        
        text.setFont(font);
        text.setCharacterSize(8);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x - 22, y - 12);

        totalVisitors++; 
        //cout << "Total Visitors: " << totalVisitors << endl;
    }

    void setPosition(sf::Vector2f pos) {
        shape.setPosition(pos);
    }

    sf::Vector2f getPosition() const {
        return shape.getPosition();
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(shape);
        //cout << "Visitor shape draw" << endl;
        window.draw(text);
        //cout << "Visitor text draw" << endl;
    }

    void update(const sf::RenderWindow &window) {
        // Check if the mouse is over the button
        if (shape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            shape.setFillColor(hoverColor);
            // Check if the mouse button is pressed
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                shape.setFillColor(sf::Color::White);
            }
        } else {
            shape.setFillColor(normalColor);
        }
    }
};
#endif
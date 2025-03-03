#ifndef VisualVisitor_H
#define VisualVisitor_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;

class Visitor {
private:
    sf::CircleShape shape;
    int id, group;
    float x, y;
    bool dummy;
    sf::Text text;
    static sf::Font font; 
    sf::Color normalColor, hoverColor;
    static int totalVisitors; 

public:
    Visitor(int group, bool dummy) : group(group), dummy(dummy) {
        //cout << "Visitor constructor" << endl;
        this->x = 0;
        this->y = 0;

        if (dummy) {
            normalColor = sf::Color::Transparent;
            text.setString("");
            this->id = -1;
        } else if (group == -1) {
            normalColor = sf::Color::Green;
            this->id = totalVisitors;
            text.setString("Person Id: " + std::to_string(id) + "\nGroup: N/A");
            totalVisitors++; 
        } else {
            normalColor = sf::Color::Blue;
            this->id = totalVisitors;
            text.setString("Person Id: " + std::to_string(id) + "\nGroup: " + std::to_string(group));
            totalVisitors++; 
        }
        
        hoverColor = sf::Color::Cyan;

        shape.setRadius(40);
        shape.setFillColor(normalColor);
        shape.setPosition(0, 0);
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

        //cout << "Total Visitors: " << totalVisitors << endl;
    }

    int getId() const {
        return id;
    }

    void setPosition(sf::Vector2f pos) {
        shape.setPosition(pos);
        text.setPosition(pos.x - 22, pos.y - 12);
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

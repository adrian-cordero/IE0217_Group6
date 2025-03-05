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
    int id, group;
    float x, y;
    bool dummy, vip;
    sf::Text text;
    static sf::Font font; 
    sf::Color normalColor, hoverColor;
    static int totalVisitors; 

public:
    Visitor(int group, bool dummy, bool vip) : group(group), dummy(dummy), vip(vip) {
        //cout << "Visitor constructor" << endl;
        this->x = 50;
        this->y = 600;

        if (dummy) {
            normalColor = sf::Color::Transparent;
            text.setString("");
            this->id = -1;
            this->vip = false;
        } else if (group == -1) {
            normalColor = sf::Color::Green;
            this->id = totalVisitors;
            text.setString("Person Id: " + std::to_string(id) + "\nGroup: N/A" + "\nVIP: " + std::to_string(vip));
            totalVisitors++; 
        } else {
            normalColor = sf::Color::Blue;
            this->id = totalVisitors;
            text.setString("Person Id: " + std::to_string(id) + "\nGroup: " + std::to_string(group) + "\nVIP: " + std::to_string(vip));
            totalVisitors++; 
        }
        
        hoverColor = sf::Color::Cyan;

        shape.setRadius(40);
        shape.setFillColor(normalColor);
        shape.setPosition(0, 0);
        shape.setOrigin(40, 40);

        static bool fontLoaded = false;
        if (!fontLoaded) {
            if (!font.loadFromFile("fonts/Montserrat-Medium.ttf")) {
                cerr << "Error: Failed to load font from fonts/Montserrat-Medium.ttf" << endl;
            } else {
                fontLoaded = true;
                cout << "Font loaded successfully." << endl;
            }
        }
       
        text.setFont(font);
        text.setCharacterSize(8);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x - 22, y - 12);            

        cout << "Total Visitors: " << totalVisitors << endl;
    }

    int getId() const {
        return id;
    }

    bool isVIP() const {
        return vip;
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

    void update(const sf::RenderWindow &window, deque<Visitor>& visitorQueue, int i) {
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

#include <SFML/Graphic.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

class VisualVisitor {
    private:
        sf::CircleShape shape;
        sf::Vector2f velocity;
        float speed;
        int id;
        sf::Font font;
        sf::Text text;
    
    public:
        VisualVisitor(float x, float y, float radius, sf::Color color, int id, sf::Text text)
            : id(id), text(text) {
            // Set up the shape (circle)
            shape.setRadius(radius);
            shape.setFillColor(color);
            shape.setPosition(x, y);
            shape.setOrigin(radius, radius);  // Center the origin
    
    
            // Load font (make sure you have "arial.ttf" in the project folder)
            if (!font.loadFromFile("Montserrat-Medium.ttf")) {
                std::cerr << "Error loading font\n";
            }
    
            // Set up the text
            text.setFont(font);
            text.setString(std::to_string(id));  // Convert ID to string
            text.setCharacterSize(20);  
            text.setFillColor(sf::Color::White);
            text.setStyle(sf::Text::Bold);
            text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
        }
    
        void update() {
            // Move the ball
            shape.move(velocity);
            text.move(velocity);  // Move text with the ball

            // Update text position to stay inside the ball
            text.setPosition(shape.getPosition().x, shape.getPosition().y);
        }
    
        void draw(sf::RenderWindow& window) {
            window.draw(shape);
            window.draw(text);
        }
};
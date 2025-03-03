#ifndef Button_H
#define Button_H


Class Button {
    private:
    sf::RectangleShape shape;
    int id;
    sf::Color normalColor;
    sf::Color hoverColor = sf::Color::Cyan;

public:
    Visitor(float x, float y, float radius, sf::Color userColor, int id) : id(id), normalColor(userColor) {
        shape.setSize(sf::Vector2f(100, 50));
        shape.setOutlineColor(sf::Color::Black);
        shape.setFillColor(normalColor);
        shape.setOutlineThickness(5);
        shape.setPosition(1000, 2000);
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

    void update(const sf::RenderWindow &window) {
        // Check if the mouse is over the button
        if (shape.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            shape.setFillColor(hoverColor);
            // Check if the mouse button is pressed
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                shape.setFillColor(sf::Color::Grey);
                Visitor(0, 0, 30, sf::Color::Red, -1)
            }
        } else {
            shape.setFillColor(normalColor);
        }
    }
}
#endif //Button_H
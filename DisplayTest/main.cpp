#include <SFML/Graphics.hpp>
#include <VisualVisitor.h>
#include <VisitorMatrix.h>

int Visitor::totalVisitors = 0;
sf::Font Visitor::font;

int main() {
    // Create a window with a title and a size (width x height)
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    sf::Color Beige(245, 245, 220);
    OnScreenVisitors visitorVctr;
    for (int i = 0; i < 10; i++) {
        visitorVctr.visitorQueuePush(Visitor(-1, false));
    }


    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();  // Close window if close event is detected
            }
        }

        /*visitorMatrix1.update();*/
        visitorVctr.update(window);

        // Clear the screen
        window.clear(Beige);

        // Draw things here (optional)
        //visitorMatrix1.draw(window);
        visitorVctr.draw(window);

        // Display what has been drawn
        window.display();
    }

    return 0;
}
#include <SFML/Graphics.hpp>
#include <deque>
#include <iostream>
#include "IndividualButton.h"
//#include "GroupButton.h"
#include "VisualVisitor.h"
#include "OnScreenVisitors.h"




int Visitor::totalVisitors = 0;
int Group::groupId = 0;
sf::Font Visitor::font;

int main() {
    // Create a window with a title and a size (width x height)
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    sf::Color Beige(245, 245, 220);
    IndividualButton indButton;
    //GroupButton groupButton;
    QueueManager queueManager;

    OnScreenVisitors visitorVctr(queueManager);
    


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
        indButton.update(window, queueManager);
        //groupButton.update(window, queueManager);

        // Clear the screen
        window.clear(Beige);

        // Draw things here (optional)
        //visitorMatrix1.draw(window);
        visitorVctr.draw(window);
        indButton.draw(window);
        //groupButton.draw(window);


        // Display what has been drawn
        window.display();
    }

    return 0;
}


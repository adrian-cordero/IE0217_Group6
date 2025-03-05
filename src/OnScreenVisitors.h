#ifndef OnScreenVisitors_H
#define OnScreenVisitors_H
#include "VisualVisitor.h"
#include "QueueManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <deque>
#include <thread>
#include <chrono>

using namespace std;

class OnScreenVisitors {
    private:
        //vector<Visitor> onScreenVctr;
        QueueManager& queueManager;
        vector<bool> occupiedVctr;
        deque<Visitor>& visitorQueue;
        int onScreenQty = 7;
        int currentOnScreen = 0;
        const float startX = 90, startY = 100;
        const float spacing = 100;  // Distance between visitors
        sf::Clock clock;
    
    public:
        OnScreenVisitors (QueueManager& manager) : queueManager(manager), visitorQueue(queueManager.getVisitors()) {

            this->onScreenQty = 7;  // The maximum number of visitors to display at once
            this->currentOnScreen = 0;  // Set the initial number of visitors on screen
            this->occupiedVctr.resize(onScreenQty, false);  // Track which positions are occupied on the screen
        }
        
        void update(const sf::RenderWindow &window) {
            for (int i = 0; i < onScreenQty && i < visitorQueue.size(); i++) {
                visitorQueue[i].setPosition(sf::Vector2f(startX + i * spacing, startY));
                
                if (!occupiedVctr[i]) {
                    //cout << "Position of visitor " << i << " is " << startX + i * spacing << endl;
                    occupiedVctr[i] = true;
                    currentOnScreen++;       
                }
            }
        
            if (clock.getElapsedTime().asSeconds() >= 3) {
                if (currentOnScreen > 0) {
                    cout << "Visitor queue size: " << visitorQueue.size() << endl;
                    cout << "Current visitor id: " << visitorQueue.front().getId() << endl;
                    visitorQueue.pop_front();

                    for (int i = 0; i < onScreenQty - 2; ++i) {
                        occupiedVctr[i] = occupiedVctr[i + 1];  
                    }
                    occupiedVctr[currentOnScreen - 1] = false;

                    /*for (int i = 0; i < occupiedVctr.size(); ++i) {
                        cout << "Occupied " << i << " : " << occupiedVctr[i] << endl; 
                    }
                    cout << "******************" << endl;*/
        
                    currentOnScreen--;
                }
        
                clock.restart();
            }
        }

    
        // Render all visitors
        void draw(sf::RenderWindow& window) const {
            //cout << "Drawing " << currentOnScreen << " visitors" << endl;

            for (size_t i = 0; i < currentOnScreen; ++i) {
                visitorQueue[i].draw(window);
            }
        }
};
#endif
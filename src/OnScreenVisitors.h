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

// This class contains the necessary elements to manage the screen, including update of which visitors are on screen
class OnScreenVisitors {
    private:
        QueueManager& queueManager;
        vector<bool> occupiedVctr; // tracks which positions are occupied
        deque<Visitor>& visitorQueue; // deque with all visitors
        int onScreenQty = 7; // Amount of visitors allowed to be on screen at the same time
        int currentOnScreen = 0; // Amount of visitors currently on screen
        const float startX = 90, startY = 100; // Initial position for the first visitor
        const float spacing = 100;  // Distance between visitors
        sf::Clock clock;
        int attentionRate = 5;  // Time in seconds to attend each visitor
    
    public:
        OnScreenVisitors (QueueManager& manager) : queueManager(manager), visitorQueue(queueManager.getVisitors()) {

            this->onScreenQty = 7;
            this->currentOnScreen = 0;
            this->occupiedVctr.resize(onScreenQty, false);
        }
        
        void update(const sf::RenderWindow &window) {
            //Update of the queue prior to printing on screen
            queueManager.updateVisitors();

            // Setting the position of the visitors on screen
            for (int i = 0; i < onScreenQty && i < visitorQueue.size(); i++) {
                visitorQueue[i].setPosition(sf::Vector2f(startX + i * spacing, startY));
                
                if (!occupiedVctr[i]) {
                    //cout << "Position of visitor " << i << " is " << startX + i * spacing << endl;
                    occupiedVctr[i] = true;
                    currentOnScreen++;       
                }
            }
        
            // Every attionRate seconds, remove a visitor from the front of the queue
            if (clock.getElapsedTime().asSeconds() >= attentionRate) {
                if (currentOnScreen > 0) {
                    //cout << "Visitor queue size: " << visitorQueue.size() << endl;
                    //cout << "Current visitor id: " << visitorQueue.front().getId() << endl;
                    visitorQueue.pop_front();

                    // Set which positions on screen are occupied
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

    
        // Draw all visitor objects
        void draw(sf::RenderWindow& window) const {
            //cout << "Drawing " << currentOnScreen << " visitors" << endl;

            for (size_t i = 0; i < currentOnScreen; ++i) {
                visitorQueue[i].draw(window);
            }
        }
};
#endif
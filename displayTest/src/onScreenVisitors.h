#ifndef VisitorMatrix_H
#define VisitorMatrix_H
#include <VisualVisitor.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <deque>
#include <thread>
#include <chrono>

using namespace std;

class OnScreenVisitors {
    private:
        vector<bool> occupiedVctr;
        //vector<Visitor> onScreenVctr;
        deque<Visitor>& visitorQueue;
        int onScreenQty = 7;
        int currentOnScreen = 0;
        const float startX = 90, startY = 100;
        const float spacing = 100;  // Distance between visitors
        sf::Clock clock;
    
    public:
        OnScreenVisitors (deque<Visitor>& visitorQueue) : visitorQueue(visitorQueue) {
            this->onScreenQty = 7;
            this->currentOnScreen = 0;
            for (int i = 0; i < onScreenQty; i++) {
                occupiedVctr.push_back(false);
            }
        }

        void visitorQueuePush(Visitor visitor) {
            //cout << "Visitor added to queue" << endl;
            visitorQueue.push_back(visitor);
        }
    
        // Update logic: shift visitors & add new ones
        void update(const sf::RenderWindow &window) {

            for (size_t i = onScreenQty-1; i >= 0 && !visitorQueue.empty(); i--) {
                //cout << "Checking position " << i << endl;
                //cout << "Occupied: " << occupiedVctr[i] << endl;
                if (!occupiedVctr[i]) {
                    //cout << "Position in vector: " << i << endl;
                    //cout << "Get Id: " << onScreenVctr[i].getId() << endl;
                    //cout << "Coordinates: " << i * spacing - startX + 200  << ", " << startY << endl;
                    onScreenVctr[i].setPosition(sf::Vector2f(i * spacing - startX + 220, startY));
                    occupiedVctr[i] = true;
                    currentOnScreen++;
                    //cout << "Visitor added to position " << i << endl;
                }
            }

            // Check if 3 seconds have passed
            if (clock.getElapsedTime().asSeconds() >= 3) {
                // Remove the last visitor in the vector
                if (occupiedVctr[onScreenQty - 1]) {
                    // Shift all visitors towards the end (to the right)
                    visitorQueue.pop_front();
                    occupiedVctr[onScreenQty - 1 - currentOnScreen] = false;
                    currentOnScreen--;  // Decrease the number of visitors on screen
                }

                // Reset the clock after 3 seconds
                clock.restart();
            }
            
            /*for (int i = 0; i < onScreenQty; i++) {
                cout << "Occupied: " << onScreenVctr[i].getId() << endl;
            }*/

            // Update all visitors
            for (int i = 0; i < onScreenQty; i++) {
                if (occupiedVctr[i]) {
                    onScreenVctr[i].update(window);
                }
            }
        }

    
        // Render all visitors
        void draw(sf::RenderWindow& window) const {
            //cout << "VisitorMatrix update" << endl;
            //cout << "Matrix size: " << visitorMatrix.size() << " x " << visitorMatrix[0].size() << endl;

            for (size_t i = 0; i < currentOnScreen; ++i) {
                visitorQueue[i].draw(window);
            }
        }
};
#endif
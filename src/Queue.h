#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <iostream>
#include "Visitor.h"

using namespace std;

class Queue {
    private:
        queue<Visitor> dataQueue;

    public:
        bool enqueue(const Visitor& visitor) {
            dataQueue.push(visitor);
            return true;
        }

        const Visitor dequeue() {
            if (dataQueue.empty()) {
                return Visitor("No visitors left", false, -1, -1);
            }
            Visitor visitor = dataQueue.front();
            dataQueue.pop();
            return visitor;
        }

        bool isEmpty() const {
            return dataQueue.empty();
        }

        // Function to get the front element of the queue
        int getFront() {
      
        // Checking if the queue is empty
            if (this->isEmpty()) {
                cout << "Queue is empty\n";
                return -1;
            }
            return dataQueue.front().getVisitorId();
        }
};

#endif

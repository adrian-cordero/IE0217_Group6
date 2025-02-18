#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <iostream>
#include "Interface.h"

using namespace std;

class Queue {
    private:
        queue<int> dataQueue;

    public:
        void enqueue(int visitorId) {
            dataQueue.push(visitorId);
        }

        int dequeue() {
            if (dataQueue.empty()) {
                return INT_MIN;
            }
            int visitorId = dataQueue.front();
            dataQueue.pop();
            return visitorId;
        }

        bool isEmpty() const {
            return dataQueue.empty();
        }

        void display(Interface& interface) {
            queue<int> tempQueue = dataQueue;
            cout << "Visitantes en la cola: ";
            while (!tempQueue.empty()) {
                cout << tempQueue.front() << " ";
                tempQueue.pop();
            }
            cout << endl;
            interface.update();
        }
};

#endif

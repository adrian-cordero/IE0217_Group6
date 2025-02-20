#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <iostream>
#include "DummyInferface.h"

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
                return 0;
            }
            int visitorId = dataQueue.front();
            dataQueue.pop();
            return visitorId;
        }

        bool isEmpty() const {
            return dataQueue.empty();
        }
};

#endif

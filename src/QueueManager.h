#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H

#include "Visitor.h"
#include "Group.h"
#include "DoublyLinkedList.h"
#include "Queue.h"
//#include "DummyInferface.h"
#include <unistd.h>

using namespace std;

class QueueManager {
private:
    Queue vipQueue;         // Cola para visitantes VIP individuales
    Queue regularQueue;     // Cola para visitantes regulares individuales
    Queue vipGroups;        // Lista de grupos con al menos un VIP
    Queue regularGroups;    // Lista de grupos regulares

public:
    void enqueueVisitor(const Visitor& visitor) {
        if (visitor.isVIP()){
            vipQueue.enqueue(visitor);
        } else {
            regularQueue.enqueue(visitor);
        }
    }

    void enqueueGroup(Group& group) {
        while (group.getFirst() != nullptr) {
            Visitor* temp = group.getFirst();  // Get the first visitor
            
            if (group.hasVIP()) {
                vipGroups.enqueue(*temp);  // Enqueue the visitor into the VIP queue
            } else {
                regularGroups.enqueue(*temp);  // Enqueue the visitor into the regular queue
            }
    
            group.removeFirst();  // Remove the visitor safely AFTER processing it
        }
    }

    bool dequeueVisitor() {
        cout << "Entre a dequeue" << endl;
        if (!vipQueue.isEmpty()) {
            Visitor visitor = vipQueue.dequeue();
            cout << "VIP Visitor dequeue" << visitor.getVisitorId();
            return true;
        } else if (!regularQueue.isEmpty()) {
            Visitor visitor = regularQueue.dequeue();
            cout << "Regular Visitor dequeue" << visitor.getVisitorId();
            return true;
        } else if (!vipGroups.isEmpty()) {
            Visitor visitor = vipGroups.dequeue();
            cout << "VIP Group dequeue" << visitor.getVisitorId();
            return true;
        } else if (!regularGroups.isEmpty()) {
            Visitor visitor = regularGroups.dequeue();
            cout << "Regular Group dequeue" << visitor.getVisitorId();
            return true;
        }
        return false;
    }

    void printQueues () {
        cout << "Regular individual queue front: " << regularQueue.getFront() << endl;
        cout << "VIP individual queue front: " << vipQueue.getFront() << endl;
        cout << "Regular group queue front: " << regularGroups.getFront() << endl;
        cout << "VIP group queue front: " << vipGroups.getFront() << endl;
    }
};

#endif // QUEUEMANAGER_H

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
        if (group.hasVIP()) {
            while (group.getFirst() != nullptr) {
                Visitor* temp = group.getFirst();  // Get the first visitor
                vipGroups.enqueue(*temp);  // Enqueue the visitor into the VIP queue
                group.removeFirst();  // Remove the visitor safely AFTER processing it
            }
            return ;
        } else {
            while (group.getFirst() != nullptr) {
                Visitor* temp = group.getFirst();  // Get the first visitor
                regularGroups.enqueue(*temp);
                group.removeFirst();  // Enqueue the visitor into the regular queue
            }
            return ;
        }
    }

    Visitor dequeueVisitor() {
        if (!vipQueue.isEmpty()) {     
            Visitor visitor = vipQueue.dequeue();
            return visitor;
        } else if (!regularQueue.isEmpty()) {
            Visitor visitor = regularQueue.dequeue();
            return visitor;
        } else if (!vipGroups.isEmpty()) {
            Visitor visitor = vipGroups.dequeue();
            return visitor;
        } else if (!regularGroups.isEmpty()) {
            Visitor visitor = regularGroups.dequeue();
            return visitor;
        }
        return Visitor("", false, -1, -1);
    }

    void printQueues () {
        cout << "Regular individual queue front: " << regularQueue.getFront() << endl;
        cout << "VIP individual queue front: " << vipQueue.getFront() << endl;
        cout << "Regular group queue front: " << regularGroups.getFront() << endl;
        cout << "VIP group queue front: " << vipGroups.getFront() << endl;
    }
};

#endif // QUEUEMANAGER_H

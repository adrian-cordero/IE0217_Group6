#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H

#include "VisualVisitor.h"
#include "Group.h"
#include "DoublyLinkedList.h"
#include <queue>
#include <deque>

using namespace std;

class QueueManager {
private:
    queue<Visitor> vipQueue;         // Cola para visitantes VIP individuales
    queue<Visitor> regularQueue;     // Cola para visitantes regulares individuales
    queue<Visitor> vipGroups;        // Lista de grupos con al menos un VIP
    queue<Visitor> regularGroups;    // Lista de grupos regulares
    deque<Visitor> visitors;

public:
    void enqueueVIPVisitor() {
        Visitor visitor = Visitor(-1, false, true);
        vipQueue.push(visitor);
    }

    void enqueueRegularVisitor() {
        Visitor visitor = Visitor(-1, false, false);
        regularQueue.push(visitor);
    }

    void enqueueRegularGroup() {
        Group group = Group(false);
        cout << "Group size: " << group.getGroupSize() << endl;
        for (int i = 0; i < group.getGroupSize(); i++) { 
            //cout << "Got Here" << endl;   
            //Visitor temp = group.getVisitor(i); 
            regularGroups.push(group.getVisitor(i));
        }
    }

    void enqueueVIPGroup() {
        Group group = Group(true);
        
        for (int i = 0; i < group.getGroupSize(); i++) {
            vipGroups.push(group.getVisitor(i)); 
        }
    }

    void updateVisitors() {
        if (!vipQueue.empty()) {    
            //cout << "VIP visitor added to visitors" << endl; 
            Visitor visitor = vipQueue.front();
            vipQueue.pop();
            visitors.push_front(visitor);
        } else if (!regularQueue.empty()) {
            //cout << "Regular visitor added to visitors" << endl; 
            Visitor visitor = regularQueue.front();
            regularQueue.pop();
            visitors.push_back(visitor);
        } else if (!vipGroups.empty()) {
            Visitor visitor = vipGroups.front();
            vipGroups.pop();
            visitors.push_front(visitor);
        } else if (!regularGroups.empty()) {
            Visitor visitor = regularGroups.front();
            regularGroups.pop();
            visitors.push_back(visitor);
        }
    }

    void printQueues () {
        cout << "Regular individual queue front: " << regularQueue.front().getId() << endl;
        cout << "VIP individual queue front: " << vipQueue.front().getId() << endl;
        cout << "Regular group queue front: " << regularGroups.front().getId() << endl;
        cout << "VIP group queue front: " << vipGroups.front().getId() << endl;
    }

    deque<Visitor>& getVisitors() {
        return visitors;
    }

    queue<Visitor>& getVIPQueue() {
        return vipQueue;
    }

    queue<Visitor>& getRegularQueue() {
        return regularQueue;
    }

    queue<Visitor>& getVIPGroups() {
        return vipGroups;
    }   

    queue<Visitor>& getRegularGroups() {
        return regularGroups;
    }

};

#endif // QUEUEMANAGER_H

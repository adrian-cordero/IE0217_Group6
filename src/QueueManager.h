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

    void enqueueRegularGroup(int n) {
        Group group = Group(false);
        for (int i; i<n; i++) {
            group.addRegMember();
        }
        
        while (group.getFirst() != nullptr) {
            Visitor* temp = group.getFirst();  
            regularGroups.push(*temp);  
            group.removeFirst();  
        }
    }

    void enqueueVIPGroup(int n) {
        Group group = Group(true);
        for (int i; i<n; i++) {
            group.addRegMember();
        }
        
        while (group.getFirst() != nullptr) {
            Visitor* temp = group.getFirst();  
            vipGroups.push(*temp);  
            group.removeFirst();  
        }
    }

    void updateVisitors() {
        if (!vipQueue.empty()) {     
            Visitor visitor = vipQueue.front();
            regularQueue.pop();
            visitors.push_back(visitor);
        } else if (!regularQueue.empty()) {
            Visitor visitor = regularQueue.front();
            regularQueue.pop();
            visitors.push_back(visitor);
        } else if (!vipGroups.empty()) {
            Visitor visitor = vipGroups.front();
            regularQueue.pop();
            visitors.push_back(visitor);
        } else if (!regularGroups.empty()) {
            Visitor visitor = regularGroups.front();
            regularQueue.pop();
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

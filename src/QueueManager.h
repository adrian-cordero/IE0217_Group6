#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H

#include "Visitor.h"
#include "Group.h"
#include "DoublyLinkedList.h"
#include "Queue.h"
#include "DummyInferface.h"

using namespace std;

class QueueManager {
private:
    Queue vipQueue;       // Cola para visitantes VIP individuales
    Queue regularQueue;   // Cola para visitantes regulares individuales
    DoublyLinkedList<Group> vipGroups;    // Lista de grupos con al menos un VIP
    DoublyLinkedList<Group> regularGroups; // Lista de grupos regulares

public:
    void enqueueVisitor(const Visitor& visitor) {
        if (visitor.getType() == VIP)
            vipQueue.enqueue(visitor.getGroupId());
        else
            regularQueue.enqueue(visitor.getGroupId());
    }

    void enqueueGroup(Group& group) {
        if (group.hasVIP()) {
            vipGroups.append(group);
        } else {
            regularGroups.append(group);
        }
    }

    Visitor dequeueVisitor() {
        if (!vipQueue.isEmpty()) {
            int visitorId = vipQueue.dequeue();
            return Visitor("VIP_" + to_string(visitorId), VIP);
        } else if (!regularQueue.isEmpty()) {
            int visitorId = regularQueue.dequeue();
            return Visitor("Regular_" + to_string(visitorId), REGULAR);
        }
        return Visitor("", REGULAR);
    }

    Group dequeueGroup() {
        if (vipGroups.getLength() > 0) {
            Group group = vipGroups.getHead();
            vipGroups.deleteFirst();
            return group;
        } else if (regularGroups.getLength() > 0) {
            Group group = regularGroups.getHead();
            regularGroups.deleteFirst();
            return group;
        }
        return Group(-1);
    }

};

#endif // QUEUEMANAGER_H

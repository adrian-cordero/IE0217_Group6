#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H

#include "Visitor.h"
#include "Group.h"
#include "DoublyLinkedList.h"
#include "Queue.h"

using namespace std;

class QueueManager {
    private:
        Queue vipQueue; // Cola para visitantes VIP
        Queue regularQueue; // Cola para visitantes regulares
        DoublyLinkedList<Group> groups;

    public:
        void enqueueVisitor(const Visitor& visitor) {
            if (visitor.getType() == VIP)
                vipQueue.enqueue(visitor.getGroupId());
            else
                regularQueue.enqueue(visitor.getGroupId());
        }

        void enqueueGroup(const Group& group) {
            groups.append(group);
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
            if (groups.getLength() > 0) {
                Group group = groups.getHead();
                groups.deleteFirst();
                return group;
            }
            return Group(-1);
        }


        DoublyLinkedList<Group>& getGroups() {
            return groups;
        }

        void display(Interface& interface) {
            cout << "VIP Queue: ";
            vipQueue.display(interface);
            cout << "Regular Queue: ";
            regularQueue.display(interface);
            interface.update();
        }
};

#endif // QUEUEMANAGER_H

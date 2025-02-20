#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include "LinkedList.h"
#include "Visitor.h"

using namespace std;

class Group {
private:
    int groupId;
    LinkedList<Visitor> members;

public:
    Group() : groupId(-1) {}

    Group(int id) : groupId(id) {}

    int getGroupId() const {
        return groupId;
    }

    void addMember(const Visitor& visitor) {
        members.append(visitor);
    }

    void removeMember(int index) {
        members.deleteNode(index);
    }

    int getGroupSize() const {
        return members.getLength();
    }

    bool isEmpty() const {
        return members.getLength() == 0;
    }

    LinkedList<Visitor>& getMembers() {
        return members;
    }

    // Método para determinar si el grupo tiene al menos un VIP
    bool hasVIP() {
        for (int i = 0; i < members.getLength(); ++i) {
            if (members.get(i).getType() == VIP) {
                return true;
            }
        }
        return false;
    }
};

#endif  // GROUP_H

#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "VisualVisitor.h"

using namespace std;

class Group {
private:
    LinkedList<Visitor*> members;
    static int groupId;
    bool vip;
    int membersCount = 0;

public:

    Group(bool vip) : vip(vip) {
        groupId++;
        if (vip) {
            for (int i = 0; i < 4; ++i) {
                addVIPMember();
            }
        } else {
            for (int i = 0; i < 4; ++i) {
                addRegMember();
            }
        }
    }

    int getGroupId() const {
        return groupId;
    }

    void addRegMember() {
        Visitor* visitor = new Visitor(groupId, false, false);
        membersCount++;
        members.append(visitor);
    }

    void addVIPMember() {
        Visitor* visitor = new Visitor(groupId, false, true);
        membersCount++;
        members.append(visitor);
    }

    Visitor* getFirst() {
        return members.getFirst();
    }

    void removeFirst() {
        members.deleteFirst();
    }


    int getGroupSize() const {
        return members.getLength();
    }

    bool isEmpty() const {
        return members.getLength() == 0;
    }

    /*LinkedList<Visitor>& getMembers() {
        return members;
    }*/

    // Método para determinar si el grupo tiene al menos un VIP
    bool hasVIP() {
        for (int i = 0; i < members.getLength(); ++i) {
            if (members.get(i)->isVIP()) {
                return true;
            }
        }
        return false;
    }
};

#endif  // GROUP_H

#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Visitor.h"

using namespace std;

class Group {
private:
    int groupId;
    LinkedList<Visitor*> members;

public:

    Group() {
        int groupIdInput;

        cout << "Input Group ID (int): ";
        cin >> groupIdInput;
        cin.ignore();

        groupId = groupIdInput;
    }

    Group(int id) : groupId(id) {}

    int getGroupId() const {
        return groupId;
    }

    void addMember() {
        cout << "Input Group " << groupId << " visitor information" << endl;
        Visitor* visitor = new Visitor();

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

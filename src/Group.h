#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

class Group {
private:
    int groupId;
    LinkedList<int> members;

public:
    // Constructor por defecto
    Group() : groupId(-1) {}

    // Constructor con un id específico
    Group(int id) : groupId(id) {}

    int getGroupId() const {
        return groupId;
    }

    void addMember(int memberId) {
        members.append(memberId);
    }

    void removeMember(int index) {
        members.deleteNode(index);
    }

    int getGroupSize() const {
        return members.getLength();
    }

    void printMembers() const {
        cout << "Group " << groupId << " Members:" << endl;
        members.printList();
    }

    bool isEmpty() const {
        return members.getLength() == 0;
    }

    LinkedList<int>& getMembers() {
        return members;
    }
};

#endif  // GROUP_H

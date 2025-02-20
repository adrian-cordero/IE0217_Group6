#ifndef DUMMY_INTERFACE_H
#define DUMMY_INTERFACE_H

#include <iostream>
#include "QueueManager.h"

using namespace std;

class DummyInterface {
public:
    void print(string message) {
        cout << message << endl;
    }

    void displayVisitor(Visitor& visitor) {
        cout << "[Atendiendo a visitante] " << visitor.getName() << " (" 
                  << (visitor.getType() == VIP ? "VIP" : "Regular") << ")" << endl;
    }

    void displayGroup(Group& group) {
        cout << "[Atendiendo a grupo] ID: " << group.getGroupId() << "\nMiembros:" << endl;
        for (int i = 0; i < group.getGroupSize(); ++i) {
            cout << " - " << group.getMembers().get(i).getName() << endl;
        }
    }
};

#endif // DUMMY_INTERFACE_H

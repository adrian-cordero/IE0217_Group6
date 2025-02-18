#include "QueueManager.h"
#include "Interface.h"
#include <unistd.h>
#include <iostream>

using namespace std;

class Simulation {
private:
    QueueManager queueManager;
    Interface interface;
    int attentionRate;

public:
    Simulation(int rate) : attentionRate(rate) {}

    void run() {
        while (true) {
            Visitor visitor = queueManager.dequeueVisitor();
            if (!visitor.getName().empty()) {
                cout << "Atendiendo a: " << visitor.getName() << endl;
                sleep(attentionRate);
            } else {
                Group group = queueManager.dequeueGroup();
                if (!group.isEmpty()) {
                    cout << "Atendiendo al grupo: " << group.getGroupId() << endl;
                    // Iterar sobre los miembros del grupo
                    for (int i = 0; i < group.getGroupSize(); ++i) {
                        int memberId = group.getMembers().get(i)->value;
                        cout << "- Miembro " << memberId << endl;
                        sleep(attentionRate);
                    }
                }
            }
            interface.update();
        }
    }

    void addVisitor(const Visitor& visitor) {
        queueManager.enqueueVisitor(visitor);
    }

    void addGroup(const Group& group) {
        queueManager.enqueueGroup(group);
    }
};

/*#include "QueueManager.h"
//#include "Interface.h"
//#include "DummyInferface.h"
#include <unistd.h>
#include <iostream>

using namespace std;

class Simulation {
private:
    QueueManager queueManager;
    int attentionRate;
    //DummyInterface& interface;

public:
    //Simulation(int rate, DummyInterface& iface) : attentionRate(rate), interface(iface) {}

    
    Simulation(int rate, DummyInterface& iface) 
        : attentionRate(rate), interface(iface) {
        if (rate <= 0) {
            throw std::invalid_argument("La tasa de atención debe ser positiva");
        }
    }
    

    Simulation(int rate) {
        if (rate <= 0) {
            throw std::invalid_argument("La tasa de atención debe ser positiva");
        }
    }


    void run() {
        while (true) {
            
            Visitor visitor = queueManager.dequeueVisitor();
            if (!visitor.getName().empty()) {
                cout << "Attending individual visitor" << endl;
                //interface.displayVisitor(visitor);
                sleep(attentionRate);
            } else {

                Group group = queueManager.dequeueGroup();
                if (group.getGroupId() != -1 && !group.isEmpty()) {  
                    cout << "Attending group" << endl;
                    //interface.displayGroup(group);
                    for (int i = 0; i < group.getGroupSize(); ++i) {
                        Visitor member = group.getMembers().get(i);
                        cout << "Attending group visitor" << endl;
                        //interface.print("- Miembro: " + member.getName());
                        sleep(attentionRate);
                    }
                }                
        }
        }
    }

    void addVisitor(const Visitor& visitor) {
        queueManager.enqueueVisitor(visitor);
    }

    void addGroup( Group& group) {
        queueManager.enqueueGroup(group);
    }
};*/

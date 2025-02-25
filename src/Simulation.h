#include "QueueManager.h"
//#include "Interface.h"
//#include "DummyInferface.h"
#include <unistd.h>
#include <iostream>

using namespace std;

class Simulation {
private:
    QueueManager& queueManager;
    int attentionRate;
    //DummyInterface& interface;

public:
    //Simulation(int rate, DummyInterface& iface) : attentionRate(rate), interface(iface) {}

    
    Simulation(int rate, QueueManager& queue) : attentionRate(rate), queueManager(queue) {
        if (rate <= 0) {
            throw std::invalid_argument("La tasa de atención debe ser positiva");
        }
    }

    void run() {
        while (true) {
            
            Visitor visitor = queueManager.dequeueVisitor();
            if (visitor.getVisitorId() != -1) {
                sleep(attentionRate);
                cout << "Attending visitor: " << visitor.getVisitorId() << endl;
                //interface.displayVisitor(visitor);
            }
        }
    }

    void addVisitor(const Visitor& visitor) {
        queueManager.enqueueVisitor(visitor);
    }

    void addGroup( Group& group) {
        queueManager.enqueueGroup(group);
    }
};

//#include <SFML/Graphics.hpp>
//#include "Simulation.h"
#include "Visitor.h"
#include "Group.h"
#include "QueueManager.h"
//#include "Interface.h"
#include <iostream>

using namespace std;

int main() {

    //DummyInterface interface;
    //Simulation simulation(2);             *****
    QueueManager queueTip;

    // Agregar visitantes individuales
    Visitor visitor1;
    Visitor visitor2;

    // Crear y agregar un grupo VIP
    Group group1(1);
    group1.addMember();
    group1.addMember();

    // Crear y agregar un grupo Regular
    Group group2(2);
    group2.addMember();
    group2.addMember();

    // Test
    queueTip.enqueueVisitor(visitor1);
    queueTip.enqueueVisitor(visitor2);

    cout << "Queue: " << endl;
    queueTip.printQueues();
    
    queueTip.enqueueGroup(group1);
    queueTip.enqueueGroup(group2);

    cout << "Queue: " << endl;
    queueTip.printQueues();

    queueTip.dequeueVisitor(2);
    queueTip.dequeueVisitor(2);
    queueTip.dequeueVisitor(2);
    queueTip.dequeueVisitor(2);
    queueTip.dequeueVisitor(2);

    // Ejecutar la simulación
    // simulation.run();

    return 0;
}


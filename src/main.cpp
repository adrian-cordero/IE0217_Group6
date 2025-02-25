//#include <SFML/Graphics.hpp>
#include "Simulation.h"
#include "Visitor.h"
#include "Group.h"
#include "QueueManager.h"
//#include "Interface.h"
#include <iostream>

using namespace std;

int main() {

    //DummyInterface interface;
    QueueManager queueTip;
    Simulation simulation(2, queueTip);

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
    
    queueTip.enqueueGroup(group1);
    queueTip.enqueueGroup(group2);

    Visitor visitor = queueTip.dequeueVisitor();
    cout << "Attending visitor" << visitor.getVisitorId() << endl;

    // Ejecutar la simulación
    simulation.run();

    return 0;
}


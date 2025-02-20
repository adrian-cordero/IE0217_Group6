//#include <SFML/Graphics.hpp>
#include "Simulation.h"
#include "Visitor.h"
#include "Group.h"
#include "QueueManager.h"
#include "Interface.h"
#include <iostream>

using namespace std;

int main() {

    DummyInterface interface;
    Simulation simulation(2, interface);

    // Agregar visitantes individuales
    simulation.addVisitor(Visitor("Juan", REGULAR));
    simulation.addVisitor(Visitor("Maria", VIP));
    simulation.addVisitor(Visitor("Carlos", REGULAR));

    // Crear y agregar un grupo VIP
    Group group1(1);
    group1.addMember(Visitor("VIP1", VIP));
    group1.addMember(Visitor("Regular1", REGULAR));

    // Crear y agregar un grupo Regular
    Group group2(2);
    group2.addMember(Visitor("Regular2", REGULAR));
    group2.addMember(Visitor("Regular3", REGULAR));

    simulation.addGroup(group1);
    simulation.addGroup(group2);

    // Ejecutar la simulación
    simulation.run();

    return 0;
}


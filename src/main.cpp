#include <SFML/Graphics.hpp>
#include "Simulation.h"
#include "Visitor.h"
#include "Group.h"
#include "QueueManager.h"
#include "Interface.h"

int main() {
    // Crear una simulación con una tasa de atención de 2 segundos
    Simulation simulation(2);  

    // Agregar algunos visitantes individuales
    simulation.addVisitor(Visitor("Juan", REGULAR));
    simulation.addVisitor(Visitor("Maria", VIP));
    simulation.addVisitor(Visitor("Carlos", REGULAR));

    // Crear y agregar un grupo de visitantes
    Group group1(1);
    group1.addMember(1);
    group1.addMember(2);
    group1.addMember(3);

    // Crear y agregar otro grupo de visitantes
    Group group2(2);
    group2.addMember(4);
    group2.addMember(5);
    group2.addMember(6);

    // Agregar los grupos a la simulación
    simulation.addGroup(group1);
    simulation.addGroup(group2);

    // Ejecutar la simulación
    simulation.run();

    return 0;
}

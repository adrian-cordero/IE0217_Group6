#ifndef VISITOR_H
#define VISITOR_H

#include <string>


using namespace std;

enum VisitorType { REGULAR, VIP };

//Representa a un visitante del Parque de Atracciones
class Visitor {
    
    private:
        string name;
        VisitorType type;
        int groupId;  // -1 como valor default (sin grupo)

    public:
        //Constructor
        Visitor(string name, VisitorType type, int groupId = -1) : name(name), type(type), groupId(groupId) {}

        // Getters y Setters
        string getName() const { return name; }
        VisitorType getType() const { return type; }
        int getGroupId() const { return groupId; }
};

#endif

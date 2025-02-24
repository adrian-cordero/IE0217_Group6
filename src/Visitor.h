#ifndef VISITOR_H
#define VISITOR_H

#include <string>
#include <iostream>


using namespace std;

//enum VisitorType { REGULAR, VIP };

//Representa a un visitante del Parque de Atracciones
class Visitor {
    private:
        string name;
        bool VIP;
        int groupId;  // -1 como valor default (sin grupo)
        int visitorId; // -1 como valor default (no se ha asignado un valor)

    public:
        //Constructores
        Visitor(){
            string visitor_name;
            string isVIPInput;
            bool isVIP;
            int visitorIdInput;

            cout << "Input visitor information" << endl;

            cout << "Visitor Name: ";
            cin >> visitor_name;
            cin.ignore();

            cout << "VIP (Y/N): ";
            cin >> isVIPInput;
            cin.ignore();

            cout << "Visitor ID (int): ";
            cin >> visitorIdInput;
            cin.ignore();

            if (isVIPInput == "Y") {
                isVIP = true;
            } else {
                isVIP = false;
            }

            name = visitor_name;
            VIP = isVIP;
            groupId = -1;
            visitorId = visitorIdInput;
        }
        Visitor(string name, bool VIP, int groupId = -1, int visitorId = -1) : name(name), VIP(VIP), groupId(groupId), visitorId(visitorId) {}

        // Getters y Setters
        string getName() const { return name; }
        bool isVIP() const { return VIP; }
        int getVisitorId() const { return visitorId; }
        int getGroupId() const { return groupId; }
};

#endif

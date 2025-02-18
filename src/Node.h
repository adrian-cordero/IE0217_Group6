#ifndef NODE_H
#define NODE_H

class Node {
public:
    int value;    // Almacena el valor del nodo
    Node* next;   // Puntero al siguiente nodo
    Node* prev;   // Puntero al nodo anterior

    // Constructor que inicializa el nodo con un valor y establece los punteros next y prev en nullptr
    Node(int value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

#endif // NODE_H

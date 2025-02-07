#ifndef QUEUE_H  // Preprocesador para evitar múltiples inclusiones
#define QUEUE_H

#include <iostream>
#include "Node.h"

using namespace std;

class Queue {
    private:
        Node* first;  // Puntero al primer nodo de la cola
        Node* last;   // Puntero al último nodo de la cola
        int length;   // Longitud de la cola (número de elementos)

    public:
        // Constructor por defecto: inicializa una cola vacía
        Queue() {
            first = nullptr;
            last = nullptr;
            length = 0;
        }

        // Constructor que inicializa la cola con un único nodo
        Queue(int value) {
            Node* newNode = new Node(value);  // Crear un nuevo nodo con el valor dado
            first = newNode;
            last = newNode;
            length = 1;
        }

        // Método para imprimir todos los elementos de la cola
        void printQueue() {
            Node* temp = first;
            while (temp) {  // Recorre la cola desde el primer hasta el último nodo
                cout << temp->value << endl;  // Imprime el valor del nodo actual
                temp = temp->next;  // Avanza al siguiente nodo
            }
        }

        // Método para obtener el primer elemento de la cola
        void getFirst() {
            if (first == nullptr) {  // Si la cola está vacía, imprime nullptr
                cout << "First: nullptr" << endl;
            } else {
                cout << "First: " << first->value << endl;
            }
        }

        // Método para obtener el último elemento de la cola
        void getLast() {
            if (last == nullptr) {  // Si la cola está vacía, imprime nullptr
                cout << "Last: nullptr" << endl;
            } else { 
                cout << "Last: " << last->value << endl;
            }  
        }

        // Método para obtener la longitud de la cola
        void getLength() {
            cout << "Length: " << length << endl;
        }

        // Método para verificar si la cola está vacía
        bool isEmpty() {
            return (length == 0);  // Devuelve true si la longitud es 0, false en caso contrario
        }

        // Método para obtener el valor del primer elemento de la cola sin eliminarlo
        int firstValue() { 
            if (first) return first->value;  // Si la cola no está vacía, devuelve el valor del primer nodo
            return INT_MIN;  // Si está vacía, devuelve un valor indicativo (mínimo entero)
        }

        // Método para agregar un nuevo elemento al final de la cola
        void enqueue(int value) {
            Node* newNode = new Node(value);  // Crear un nuevo nodo con el valor dado
            if (length == 0) {  // Si la cola está vacía, el nuevo nodo será el primero y el último
                first = newNode;
                last = newNode;
            } else {  // Si no está vacía, agregar el nuevo nodo al final
                last->next = newNode;
                last = newNode;  // Actualizar el puntero al último nodo
            }
            length++;  // Incrementar la longitud de la cola
        }

        // Método para eliminar y devolver el primer elemento de la cola
        int dequeue() {
            if (length == 0) return INT_MIN;  // Si la cola está vacía, devuelve un valor indicativo
            Node* temp = first;  // Guardar el nodo que se va a eliminar
            int dequeuedValue = first->value;  // Guardar el valor del nodo
            if (length == 1) {  // Si la cola tiene un solo elemento, vaciarla
                first = nullptr;
                last = nullptr;
            } else {  // Si tiene más de un elemento, avanzar el puntero first
                first = first->next;
            }
            delete temp;  // Liberar la memoria del nodo eliminado
            length--;  // Decrementar la longitud de la cola
            return dequeuedValue;  // Devolver el valor del nodo eliminado
        }
};

#endif // QUEUE_H

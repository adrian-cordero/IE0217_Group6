#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>

template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;

        Node(T val) : value(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    ~DoublyLinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void append(T value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    // Implementación de deleteFirst para eliminar el primer nodo
    void deleteFirst() {
        if (head == nullptr) return;
        
        Node* temp = head;
        head = head->next;
    
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
    
        delete temp;
        length--;
    }
    
    // Implementación de deleteLast para eliminar el último nodo
    void deleteLast() {
        if (length == 0) return;
        if (length == 1) {
            deleteFirst();
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        length--;
    }

    // Implementación de deleteNode que elimina el nodo en el índice dado
    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();

        Node* temp = get(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        length--;
    }

    // Método para obtener el puntero al nodo en el índice dado
    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp;
    }

    T getHead() const {
        return head ? head->value : T();
    }

    int getLength() const {
        return length;
    }

    // Método adicional para imprimir la lista (solo para depuración)
    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    bool isEmpty(){
        return length == 0;
    }
};

#endif  // DOUBLYLINKEDLIST_H

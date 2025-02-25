#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(T val) : data(val), next(nullptr) {}
    };

    Node* head;
    int length;

public:
    LinkedList() : head(nullptr), length(0) {}

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void append(T data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        length++;
    }

    void remove(int index) {
        if (index >= length || index < 0) return;

        Node* current = head;

        if (index == 0) {
            head = current->next;
            delete current;
        } else {
            Node* prev = nullptr;
            for (int i = 0; current != nullptr && i < index; i++) {
                prev = current;
                current = current->next;
            }
            if (current == nullptr) return;
            prev->next = current->next;
            delete current;
        }

        length--;
    }

    int getLength() const {
        return length;
    }

    void deleteFirst() {
        if (head == nullptr) return; // Ensure the list isn't already empty
    
        Node* temp = head;
        head = head->next; // Move head to the next node
    
        delete temp; // Free the memory of the first node
        length--;
    
        if (head == nullptr) { // If the list is now empty, make sure it's properly reset
            length = 0;
        }
    }
    

    void deleteLast() {
        if (length == 0) return;
        if (length == 1) {
            deleteFirst();
            return;
        }
        Node* current = head;
        while (current->next && current->next->next) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = nullptr;
        delete temp;
        length--;
    }

    // Función para obtener un puntero al nodo en un índice específico
    T get(int index) {
        if (index >= length || index < 0) {
            throw std::out_of_range("Índice fuera de rango");
        }
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    T getFirst () {
        if (head == nullptr) {
            return nullptr;  // Ensure safe return when the list is empty
        }
        return head->data;
    }

    // Función para establecer un nuevo valor en un nodo en un índice específico
    bool set(int index, int data) {
        Node* temp = get(index);
        if (temp) {
            temp->data = data;
            return true;
        }
        return false;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();
        Node* prev = head;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        length--;
    }
};

#endif  // LINKEDLIST_H

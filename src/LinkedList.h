#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T value;
        Node* next;

        Node(T val) : value(val), next(nullptr) {}
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

    void append(T value) {
        Node* newNode = new Node(value);
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

    T get(int index) const {
        if (index >= length || index < 0) return T();
        Node* current = head;
        for (int i = 0; current != nullptr && i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
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
    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp;
    }

    // Función para establecer un nuevo valor en un nodo en un índice específico
    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();

        Node* prev = get(index - 1);
        Node* temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }

    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

#endif  // LINKEDLIST_H

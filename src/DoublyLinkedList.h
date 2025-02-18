#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>

class DoublyLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
        int length;

    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

        ~DoublyLinkedList() {
            Node<T>* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void append(T value) {
            Node<T>* newNode = new Node<T>(value);
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

        void printList() {
            Node<T>* temp = head;
            while (temp != nullptr) {
                cout << temp->value.getName() << endl;
                temp = temp->next;
            }
        }

        bool isEmpty() const {
            return length == 0;
        }

        T removeFirst() {
            if (length == 0) return T();
            Node<T>* temp = head;
            T value = temp->value;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            length--;
            return value;
        }
};

#endif

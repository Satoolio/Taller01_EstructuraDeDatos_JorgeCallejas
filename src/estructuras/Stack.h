#pragma once
#include "Node.h"

template <typename T>
class Stack {
private:
    Node<T>* start;
    int size;
public:
    Stack() {
        this->start = nullptr;
        this->size = 0;
    }

    bool isEmpty() { return this->start == nullptr; }
    int getSize() { return this->size; }

    void push(T value) {
        Node<T>* nuevo = new Node<T>(value);
        nuevo->setNext(this->start);
        this->start = nuevo;
        this->size++;
    }

    T top() {
        if (this->start == nullptr) throw 0;
        return this->start->getValue();
    }

    void pop() {
        if (this->start == nullptr) throw 0;
        Node<T>* toDelete = this->start;
        this->start = toDelete->getNext();
        delete toDelete;
        this->size--;
    }

    T get(int index) {
        if (index < 0 || index >= this->size) throw 0;
        Node<T>* cursor = this->start;
        for (int i = 0; i < index; i++) {
            cursor = cursor->getNext();
        }
        return cursor->getValue();
    }

    void clear() {
        while (this->start != nullptr) {
            this->pop();
        }
    }

    ~Stack() { this->clear(); }
};

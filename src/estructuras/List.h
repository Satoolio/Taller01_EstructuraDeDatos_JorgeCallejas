#pragma once
#include "Node.h"

template <typename T>
class List {
private:
    Node<T>* start;
    int size;
public:
    List() {
        this->start = nullptr;
        this->size = 0;
    }

    bool isEmpty() { return this->start == nullptr; }
    int getSize() { return this->size; }

    void insertFirst(T value) {
        Node<T>* nuevo = new Node<T>(value);
        nuevo->setNext(this->start);
        this->start = nuevo;
        this->size++;
    }

    void insertLast(T value) {
        if (this->start == nullptr) {
            this->insertFirst(value);
            return;
        }
        Node<T>* cursor = this->start;
        while (cursor->getNext() != nullptr) {
            cursor = cursor->getNext();
        }
        cursor->setNext(new Node<T>(value));
        this->size++;
    }

    void insert(T value, int index) {
        if (index < 0 || index > this->size) throw 0;
        if (index == 0) {
            this->insertFirst(value);
            return;
        }
        Node<T>* cursor = this->start;
        for (int i = 0; i < index - 1; i++) {
            cursor = cursor->getNext();
        }
        Node<T>* nuevo = new Node<T>(value);
        nuevo->setNext(cursor->getNext());
        cursor->setNext(nuevo);
        this->size++;
    }

    T get(int index) {
        if (index < 0 || index >= this->size) throw 0;
        Node<T>* cursor = this->start;
        for (int i = 0; i < index; i++) {
            cursor = cursor->getNext();
        }
        return cursor->getValue();
    }

    T getFirst() { return this->get(0); }
    T getLast() { return this->get(this->size - 1); }

    void remove(int index) {
        if (index < 0 || index >= this->size) throw 0;
        Node<T>* toDelete;
        if (index == 0) {
            toDelete = this->start;
            this->start = toDelete->getNext();
        } else {
            Node<T>* cursor = this->start;
            for (int i = 0; i < index - 1; i++) {
                cursor = cursor->getNext();
            }
            toDelete = cursor->getNext();
            cursor->setNext(toDelete->getNext());
        }
        delete toDelete;
        this->size--;
    }

    void clear() {
        while (this->start != nullptr) {
            Node<T>* temp = this->start->getNext();
            delete this->start;
            this->start = temp;
        }
        this->size = 0;
    }

    ~List() { this->clear(); }
};

#pragma once

template <typename T>
class Node {
private:
    T value;
    Node<T>* next;
public:
    Node(T value) : value(value), next(nullptr) {}

    T getValue() { return this->value; }
    Node<T>* getNext() { return this->next; }

    void setValue(T value) { this->value = value; }
    void setNext(Node<T>* next) { this->next = next; }

    ~Node() {}
};

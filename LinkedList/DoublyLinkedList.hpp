#pragma once

#include <iostream>
#include <vector>

template <typename T>
struct Node
{
    Node* previous;
    Node* next;
    T data;
};

template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList(const T* input, size_t size);
    explicit DoublyLinkedList(std::vector<T> inputs);
    ~DoublyLinkedList();

    bool operator==(const DoublyLinkedList& other) const;

private:
    template <typename P>
    friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<P>& doublyLinkedList);

    Node<T>* first = nullptr;
    size_t size = 0;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);

#include "DoublyLinkedList.tpp"

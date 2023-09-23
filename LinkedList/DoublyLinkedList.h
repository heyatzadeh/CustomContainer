#pragma once

#include <iostream>
#include <vector>

struct Node
{
    Node* previous;
    Node* next;
    int data;
};


class DoublyLinkedList
{
public:
    DoublyLinkedList(const int* input, int size);
    explicit DoublyLinkedList(std::vector<int> inputs);
    ~DoublyLinkedList();

    bool operator==(const DoublyLinkedList& other) const;

private:
    friend std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& doublyLinkedList);

    Node* first = nullptr;
    int size = 0;
};

std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& doublyLinkedList);

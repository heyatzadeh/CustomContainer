#pragma once

#include <iostream>

struct Node
{
    int data;
    struct Node* next;
};

class LinkedList
{
public:
    LinkedList(int* A, int size);
    void display();
    int count();
    int sum();

    friend std::ostream& operator<<(std::ostream& out, const LinkedList& linkedList);

private:
    static void displayRecursive(struct Node* first);
    static int countRecursive(struct Node* first);
    static int sumRecursive(struct Node* first);

    Node* first;
};

std::ostream& operator<<(std::ostream& out, const LinkedList& linkedList);
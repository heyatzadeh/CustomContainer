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
    int max();
    Node* LinearSearch(int target);
    Node* LinearSearchImprove(int key);

    friend std::ostream& operator<<(std::ostream& out, const LinkedList& linkedList);

private:
    static void displayRecursive(struct Node* first);
    static int countRecursive(struct Node* first);
    static int sumRecursive(struct Node* first);
    static int maxRecursive(struct Node* first);
    static int minRecursive(struct Node* first);
    static Node* LinearSearchRecursive(struct Node* first, int target);

    Node* first;
};

std::ostream& operator<<(std::ostream& out, const LinkedList& linkedList);
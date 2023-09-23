#pragma once

#include <iostream>
#include <vector>

struct Node
{
    int data;
    struct Node* next;
};

class LinkedList
{
public:
    LinkedList(int* A, int size);
    explicit LinkedList(std::vector<int> input);
    void display();
    [[nodiscard]] int count() const;
    int sum();
    int max();
    Node* LinearSearch(int target);
    Node* LinearSearchImprove(int key);
    void insert(int index, int value);
    int remove(int index);
    bool isSorted();
    void removeOrderedDuplicate();
    void reverse();
    void concat(const LinkedList& other);
    void mergeSortedList(LinkedList& other);
    [[nodiscard]] bool IsLinkedListHaveLoop() const;

    friend std::ostream& operator<<(std::ostream& out, const LinkedList& linkedList);
    bool operator==(const LinkedList& other) const;

private:
    static void displayRecursive(struct Node* first);
    static int countRecursive(struct Node* first);
    static int sumRecursive(struct Node* first);
    static int maxRecursive(struct Node* first);
    static int minRecursive(struct Node* first);
    static Node* LinearSearchRecursive(struct Node* first, int target);
    void reverseRecursion(struct Node* node, Node* tailOfNode = nullptr);

public:
    Node* first;
};

std::ostream& operator<<(std::ostream& out, const LinkedList& linkedList);
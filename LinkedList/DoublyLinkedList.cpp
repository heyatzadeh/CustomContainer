#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(const int* input, int size)
{
    if (size < 1)
    {
        return;
    }

    first = new Node(nullptr, nullptr, input[0]);
    this->size = size;
    auto start{first};

    for (int i = 1; i < size; ++i)
    {
        auto tempNode = new Node(start, nullptr, input[i]);
        start->next = tempNode;
        start = start->next;
    }
}

DoublyLinkedList::DoublyLinkedList(std::vector<int> inputs) : DoublyLinkedList(inputs.data(), inputs.size())
{
}

DoublyLinkedList::~DoublyLinkedList()
{
    auto node{first};

    while (node)
    {
        first = first->next;
        delete node;
        node = first;
    }
}

std::ostream& operator<<(std::ostream& out, const DoublyLinkedList& doublyLinkedList)
{
    out << '[';
    auto node{doublyLinkedList.first};

    while (node)
    {
        out << node->data << ' ';
        node = node->next;
    }
    out << ']';
    return out;
}

bool DoublyLinkedList::operator==(const DoublyLinkedList& other) const
{
    if (size != other.size)
    {
        return false;
    }
    auto firstNode{first}, secondNode{other.first};
    while (firstNode && secondNode)
    {
        if (firstNode->data != secondNode->data)
        {
            return false;
        }
        firstNode = firstNode->next;
        secondNode = secondNode->next;
    }
    return true;
}

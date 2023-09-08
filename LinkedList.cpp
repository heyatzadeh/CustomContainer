#include "LinkedList.h"

LinkedList::LinkedList(int* A, int size)
{
    first = new Node();
    first->data = A[0];
    first->next = nullptr;
    auto last = first;

    for (int i = 1; i < size; ++i)
    {
        auto temp = new Node();
        temp->data = A[i];
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
}

void LinkedList::display()
{
    std::cout << "[ ";
    displayRecursive(first);
    std::cout << "], Size: " << countRecursive(first) << ", Sum: " << sumRecursive(first);
}

void LinkedList::displayRecursive(struct Node* first)
{
    if (first)
    {
        std::cout << first->data << ' ';
        displayRecursive(first->next);
    }
}

std::ostream& operator<<(std::ostream& out, const LinkedList& linkedList)
{
    auto temp = linkedList.first;

    out << "[ ";
    while (temp)
    {
        out << temp->data << " ";
        temp = temp->next;
    }
    out << "]";
    return out;
}

int LinkedList::count()
{
    int result{0};
    auto last{first};
    while (last)
    {
        last = last->next;
        result++;
    }
    return result;
}

int LinkedList::countRecursive(struct Node* first)
{
    if (!first)
    {
        return 0;
    }
    return countRecursive(first->next) + 1;
}

int LinkedList::sum()
{
    auto result{0};
    auto last{first};
    while (last)
    {
        result += last->data;
        last = last->next;
    }
    return result;
}

int LinkedList::sumRecursive(struct Node* first)
{
    if (!first)
    {
        return 0;
    }
    return first->data + sumRecursive(first->next);
}

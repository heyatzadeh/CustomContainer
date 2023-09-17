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
    std::cout << "], Size: " << countRecursive(first) << ", Sum: " << sumRecursive(first) << ", Max: " << maxRecursive(first) << ", Min: " << minRecursive(first) << std::endl;

    std::cout << LinearSearchRecursive(first, 80)->data;
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

int LinkedList::max()
{
    auto max = first->data;
    auto last{first};
    while (last)
    {
        max = (max < last->data) ? last->data : max;
        last = last->next;
    }
    return max;
}

int LinkedList::maxRecursive(struct Node* first)
{
    int current;
    if (!first->next)
    {
        return first->data;
    }

    current = maxRecursive(first->next);
    return (current > first->data) ? current : first->data;
}

int LinkedList::minRecursive(struct Node* first)
{
    int min;
    if (!first->next)
    {
        return first->data;
    }
    min = minRecursive(first->next);
    return (min > first->data) ? first->data : min;
}

Node* LinkedList::LinearSearch(int target)
{
    auto last{first};
    while (last)
    {
        if (last->data == target)
        {
            return last;
        }
        last = last->next;
    }
    return nullptr;
}

Node* LinkedList::LinearSearchRecursive(struct Node* first, int target)
{
    if (!first->next)
    {
        return nullptr;
    }

    if (first->data == target)
    {
        return first;
    }

    return LinearSearchRecursive(first->next, target);
}

Node* LinkedList::LinearSearchImprove(int key)
{
    auto q{first}, p{first};
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return first;
        }
        q = p;
        p = p->next;
    }
    return nullptr;
}

void LinkedList::insert(int index, int value)
{
    auto last{first};
    auto createdNode = new Node;
    createdNode->data = value;

    if (index == 0)
    {
        createdNode->next = first;
        first = createdNode;
        return;
    }
    for (int i = 0; i < index - 1 && last; i++)
    {
        last = last->next;
    }
    if (last)
    {
        createdNode->next = last->next;
        last->next = createdNode;
    }
}

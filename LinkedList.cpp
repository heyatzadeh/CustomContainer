#include "LinkedList.h"

LinkedList::LinkedList() : first(nullptr)
{
}

LinkedList::LinkedList(const int* A, int size)
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

LinkedList::LinkedList(std::vector<int> input) : LinkedList(input.data(), input.size())
{
}

LinkedList::~LinkedList()
{
    if (IsLinkedListHaveLoop())
    {
        return;
    }
    auto node{first};
    while (node)
    {
        first = first->next;
        delete node;
        node = first;
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

bool LinkedList::operator==(const LinkedList& other) const
{
    if (count() != other.count())
    {
        return false;
    }

    auto p{first};
    auto q{other.first};
    while (p)
    {
        if (p->data != q->data)
        {
            return false;
        }
        p = p->next;
        q = q->next;
    }

    return true;
}

int LinkedList::count() const
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

int LinkedList::remove(int index)
{
    auto p{first}, q{first};
    int result = -1;

    if (index < 0 || count() <= index)
    {
        return result;
    }

    if (index == 0)
    {
        first = first->next;
        result = p->data;
        delete p;
    }

    else
    {
        for (int i = 0; i < index; ++i)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        result = p->data;
        delete p;
    }
    return result;
}

bool LinkedList::isSorted()
{
    auto last{first};
    int previousData = first->data;

    while (last)
    {
        if (previousData > last->data)
        {
            return false;
        }
        previousData = last->data;
        last = last->next;
    }
    return true;
}

void LinkedList::removeOrderedDuplicate()
{
    auto p{first->next}, q{first};

    while (p)
    {
        if (p->data == q->data)
        {
            q->next = p->next;
            delete p;
            p = q->next;
        }

        else
        {
            q = p;
            p = p->next;
        }
    }
}

void LinkedList::reverse()
{
    // By moving elements
    //    auto p{first}, q{first};
    //    std::vector<int> temp;
    //    while (p)
    //    {
    //        temp.push_back(p->data);
    //        p = p->next;
    //    }
    //    while (q)
    //    {
    //        q->data = temp.back();
    //        temp.pop_back();
    //        q = q->next;
    //    }

    // By modifying links
    //    Node *firstNode{first}, *middleNode{nullptr}, *lastNode{nullptr};
    //    while (firstNode)
    //    {
    //        lastNode = middleNode;
    //        middleNode = firstNode;
    //        firstNode = firstNode->next;
    //        middleNode->next = lastNode;
    //    }
    //    first = middleNode;

    // By using recursion
    auto temp{first};
    LinkedList::reverseRecursion(temp);
}

void LinkedList::reverseRecursion(struct Node* node, Node* tailOfNode)
{
    if (node)
    {
        reverseRecursion(node->next, node);
        node->next = tailOfNode;
    }
    else
    {
        this->first = tailOfNode;
    }
}

void LinkedList::concat(const LinkedList& other)
{
    auto node{first};
    while (node->next)
    {
        node = node->next;
    }
    node->next = other.first;
}

void LinkedList::mergeSortedList(LinkedList& other)
{
    auto firstNode{first}, secondNode{other.first};
    Node* lastNode{nullptr};

    if (firstNode->data > secondNode->data)
    {
        first = lastNode = secondNode;
        secondNode = secondNode->next;
    }
    else
    {
        first = lastNode = firstNode;
        firstNode = firstNode->next;
    }
    lastNode->next = nullptr;

    while (firstNode && secondNode)
    {
        if (firstNode->data > secondNode->data)
        {
            lastNode->next = secondNode;
            lastNode = secondNode;
            secondNode = secondNode->next;
        }
        else
        {
            lastNode->next = firstNode;
            lastNode = firstNode;
            firstNode = firstNode->next;
        }
        lastNode->next = nullptr;
    }

    if (firstNode)
    {
        lastNode->next = firstNode;
    }
    else
    {
        lastNode->next = secondNode;
    }
}

bool LinkedList::IsLinkedListHaveLoop() const
{
    auto oneJumper{first}, twoJumper{first->next};

    while (oneJumper && twoJumper)
    {
        if (oneJumper == twoJumper)
        {
            return true;
        }
        oneJumper = oneJumper->next;
        twoJumper = (twoJumper->next) ? twoJumper->next->next : nullptr;
    }
    return false;
}

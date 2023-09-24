template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const T* input, size_t size)
{
    if (size == 0)
    {
        return;
    }

    first = new Node<T>(nullptr, nullptr, input[0]);
    auto start{first};

    for (int i = 1; i < size; ++i)
    {
        auto tempNode = new Node<T>(start, nullptr, input[i]);
        start->next = tempNode;
        start = start->next;
    }
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(std::vector<T> inputs) : DoublyLinkedList(inputs.data(), inputs.size())
{
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    auto node{first};

    while (node)
    {
        first = first->next;
        delete node;
        node = first;
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList)
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

template <typename T>
bool DoublyLinkedList<T>::operator==(const DoublyLinkedList& other) const
{
    if (size() != other.size())
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

template <typename T>
size_t DoublyLinkedList<T>::size() const
{
    auto node{first};
    size_t counter = 0;
    while (node)
    {
        counter++;
        node = node->next;
    }
    return counter;
}

template <typename T>
void DoublyLinkedList<T>::insert(size_t index, T value)
{
    if (index == 0)
    {
        auto tempNode = new Node<T>(nullptr, first, value);
        if (first)
        {
            first->previous = tempNode;
        }
        first = tempNode;
    }

    auto node{first};
    ;
    for (int i = 0; i < index - 1 && node; ++i)
    {
        node = node->next;
    }
    if (node)
    {
        auto tempNode = new Node<T>(node, node->next, value);
        if (node->next)
        {
            node->next->previous = tempNode;
        }
        node->next = tempNode;
    }
}

template <typename T>
T DoublyLinkedList<T>::remove(size_t index)
{
    if (index == 0)
    {
        auto node{first->next};
        auto result{first->data};
        delete first;
        if (node)
        {
            node->previous = nullptr;
        }
        first = node;
        return result;
    }

    Node<T>* node{first};

    for (int i = 0; i < index && node; ++i)
    {
        node = node->next;
    }
    if (node)
    {
        node->previous->next = node->next;
        if (node->next)
        {
            node->next->previous = node->previous;
        }
        auto result = node->data;
        delete node;
        return result;
    }
    return -1;
}
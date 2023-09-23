template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const T* input, size_t size)
{
    if (size < 1)
    {
        return;
    }

    first = new Node<T>(nullptr, nullptr, input[0]);
    this->size = size;
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

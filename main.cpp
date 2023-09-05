#include "LinkedList.h"
#include <iostream>

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    LinkedList linkedList(A, 5);
    std::cout << linkedList << " Size: " << linkedList.count() << '\n';
    linkedList.display();
    return 0;
}
#include "LinkedList.h"
#include <iostream>

int main()
{
    int A[] = {3, 5, 7, 10, 15, 8, 12, 20};
    LinkedList linkedList(A, std::size(A));
    std::cout << linkedList << ", Size: " << linkedList.count()
              << ", Sum: " << linkedList.sum() << '\n';
    linkedList.display();
    return 0;
}
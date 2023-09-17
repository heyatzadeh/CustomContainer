#include "LinkedList.h"
#include <iostream>

int main()
{
    int A[] = {3, 5, 7, 5, 1, 80, 10, 15, 8, 12, 20};
    LinkedList linkedList(A, std::size(A));
    std::cout << linkedList << ", Size: " << linkedList.count()
              << ", Sum: " << linkedList.sum() << ", Max: " << linkedList.max() << '\n';
    std::cout << "\n---------------------------\n";
    linkedList.insert(11,85);
    std::cout << linkedList;
    return 0;
}
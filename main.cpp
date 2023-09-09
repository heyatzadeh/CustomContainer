#include "LinkedList.h"
#include <iostream>

int main()
{
    int A[] = {3, 5, 7, 5, 1, 80, 10, 15, 8, 12, 20};
    LinkedList linkedList(A, std::size(A));
    std::cout << linkedList << ", Size: " << linkedList.count()
              << ", Sum: " << linkedList.sum() << ", Max: " << linkedList.max() << '\n';
    linkedList.display();
    std::cout << "\n---------------------------\n";
    std::cout << linkedList.LinearSearchImprove(80) << std::endl;
    std::cout << linkedList;
    std::cout << linkedList.LinearSearchImprove(80) << std::endl;
    return 0;
}
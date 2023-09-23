#include "DoublyLinkedList.h"
#include <catch_amalgamated.hpp>

TEST_CASE("Constructor")
{
    SECTION("Can create Simple Node")
    {
        int inputs[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        DoublyLinkedList doublyLinkedList1(inputs, std::size(inputs));
        DoublyLinkedList doublyLinkedList2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        DoublyLinkedList doublyLinkedList3({1, 2, 3, 4, 5, 15, 7, 8, 9, 10});
        DoublyLinkedList doublyLinkedList4({1, 2});
        REQUIRE(doublyLinkedList1 == doublyLinkedList2);
        REQUIRE(doublyLinkedList1 != doublyLinkedList3);
        REQUIRE(doublyLinkedList2 != doublyLinkedList3);
        REQUIRE(doublyLinkedList3 != doublyLinkedList4);
    }
}
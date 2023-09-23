#include "DoublyLinkedList.hpp"
#include <catch_amalgamated.hpp>

TEST_CASE("Constructor")
{
    SECTION("Can create Simple Node")
    {
        int inputs[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        DoublyLinkedList doublyLinkedList1(inputs, std::size(inputs));
        DoublyLinkedList<int> doublyLinkedList2({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
        DoublyLinkedList<int> doublyLinkedList3({1, 2, 3, 4, 5, 15, 7, 8, 9, 10});
        DoublyLinkedList<double> doublyLinkedList4({1, 2});
        DoublyLinkedList<double> doublyLinkedList5({1});
        REQUIRE(doublyLinkedList1 == doublyLinkedList2);
        REQUIRE(doublyLinkedList1 != doublyLinkedList3);
        REQUIRE(doublyLinkedList2 != doublyLinkedList3);
        REQUIRE(doublyLinkedList4 != doublyLinkedList5);
    }
}
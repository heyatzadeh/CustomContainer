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

TEST_CASE("size")
{
    SECTION("Normal list")
    {
        DoublyLinkedList<int> list({1, 2, 3, 4, 5});
        REQUIRE(list.size() == 5);
    }
    SECTION("one element list")
    {
        DoublyLinkedList<int> list({1});
        REQUIRE(list.size() == 1);
    }
    SECTION("zero element list")
    {
        DoublyLinkedList<int> list({});
        REQUIRE(list.size() == 0);
    }
}

TEST_CASE("insert")
{
    SECTION("Insert element at some index")
    {
        DoublyLinkedList<int> list({1, 2, 3, 4, 5});
        list.insert(3, 10);
        REQUIRE(list == DoublyLinkedList<int>({1, 2, 3, 10, 4, 5}));
    }
    SECTION("Insert element at zero index")
    {
        DoublyLinkedList<int> list({1, 2, 3, 4, 5});
        list.insert(0, 10);
        REQUIRE(list == DoublyLinkedList<int>({10, 1, 2, 3, 4, 5}));
    }
    SECTION("Insert element at one index")
    {
        DoublyLinkedList<int> list({1, 2, 3, 4, 5});
        list.insert(1, 10);
        REQUIRE(list == DoublyLinkedList<int>({1, 10, 2, 3, 4, 5}));
    }
    SECTION("Insert element in empty list")
    {
        DoublyLinkedList<int> list({});
        list.insert(0, 10);
        list.insert(1, 20);
        REQUIRE(list == DoublyLinkedList<int>({10, 20}));
    }
    SECTION("Insert element at not valid index")
    {
        DoublyLinkedList<int> list({1, 2, 3, 4, 5});
        list.insert(6, 10);
        REQUIRE(list == DoublyLinkedList<int>({1, 2, 3, 4, 5}));
    }
    SECTION("Insert element last index")
    {
        DoublyLinkedList<int> list({1, 2, 3, 4, 5});
        list.insert(5, 10);
        REQUIRE(list == DoublyLinkedList<int>({1, 2, 3, 4, 5, 10}));
    }
    SECTION("Insert element second last index")
    {
        DoublyLinkedList<int> list({1, 2, 3, 4, 5});
        list.insert(4, 10);
        REQUIRE(list == DoublyLinkedList<int>({1, 2, 3, 4, 10, 5}));
    }
}

TEST_CASE("remove")
{
    SECTION("remove at first index")
    {
        DoublyLinkedList<int> list({1, 2, 3, 4, 5});
        REQUIRE(list.remove(0) == 1);
        REQUIRE(list == DoublyLinkedList<int>({2, 3, 4, 5}));
    }
    SECTION("remove at first index with one element")
    {
        DoublyLinkedList<int> list({1});
        REQUIRE(list.remove(0) == 1);
        REQUIRE(list == DoublyLinkedList<int>({}));
    }
    SECTION("remove at some index")
    {
        DoublyLinkedList<int> list({1, 2, 3, 4, 5});
        REQUIRE(list.remove(3) == 4);
        REQUIRE(list == DoublyLinkedList<int>({1, 2, 3, 5}));
    }
    SECTION("remove last index")
    {
        DoublyLinkedList<int> list({1, 3});
        REQUIRE(list.remove(1) == 3);
        REQUIRE(list == DoublyLinkedList<int>({1}));
    }
    SECTION("remove second last index")
    {
        DoublyLinkedList<int> list({1, 2, 3});
        REQUIRE(list.remove(1) == 2);
        REQUIRE(list == DoublyLinkedList<int>({1, 3}));
    }
}
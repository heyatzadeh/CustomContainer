#include "LinkedList.h"
#include <catch_amalgamated.hpp>

TEST_CASE("isSorted")
{
    SECTION("Not Sorted")
    {
        int A[] = {3, 10, 5, 7, 20};
        LinkedList linkedList(A, std::size(A));
        CHECK_FALSE(linkedList.isSorted());
    }
    SECTION("Is Sorted")
    {
        int A[] = {3, 5, 7, 20};
        LinkedList linkedList(A, std::size(A));
        CHECK(linkedList.isSorted());
    }
}

TEST_CASE("removeOrderedDuplicate")
{
    SECTION("At begging")
    {
        int A[] = {3, 3, 10, 5};
        LinkedList linkedList(A, std::size(A));
        linkedList.removeOrderedDuplicate();
        REQUIRE(linkedList == LinkedList({3, 10, 5}));
    }
    SECTION("At end")
    {
        int A[] = {3, 3, 3, 5, 5, 5, 5};
        LinkedList linkedList(A, std::size(A));
        linkedList.removeOrderedDuplicate();
        REQUIRE(linkedList == LinkedList({3, 5}));
    }
    SECTION("Multiply")
    {
        int A[] = {3, 3, 3, 10, 5};
        LinkedList linkedList(A, std::size(A));
        linkedList.removeOrderedDuplicate();
        REQUIRE(linkedList == LinkedList({3, 10, 5}));
    }
    SECTION("Only one")
    {
        int A[] = {200, 200};
        LinkedList linkedList(A, std::size(A));
        linkedList.removeOrderedDuplicate();
        REQUIRE(linkedList == LinkedList({200}));
    }
}

TEST_CASE("reverse")
{
    SECTION("Normal example")
    {
        LinkedList linkedList({2, 4, 6, 8});
        linkedList.reverse();
        REQUIRE(linkedList == LinkedList({8, 6, 4, 2}));
    }

    SECTION("Only one")
    {
        LinkedList linkedList({2});
        linkedList.reverse();
        REQUIRE(linkedList == LinkedList({2}));
    }

    SECTION("Repeated number")
    {
        LinkedList linkedList({2, 3, 800, 800, 800});
        linkedList.reverse();
        REQUIRE(linkedList == LinkedList({800, 800, 800, 3, 2}));
    }
}

TEST_CASE("concat")
{
    SECTION("join two lists")
    {
        LinkedList linkedList1({2, 4, 6, 8});
        LinkedList linkedList2({100, 200, 300});
        linkedList1.concat(linkedList2);
        REQUIRE(linkedList1 == LinkedList({2, 4, 6, 8, 100, 200, 300}));
    }
}

TEST_CASE("mergeSortedList")
{
    SECTION("merge two sorted lists to get one sorted list")
    {
        LinkedList linkedList1({2, 8, 10, 15});
        LinkedList linkedList2({4, 7, 12, 14});
        linkedList1.mergeSortedList(linkedList2);
        REQUIRE(linkedList1 == LinkedList({2, 4, 7, 8, 10, 12, 14, 15}));
    }
    SECTION("one element list")
    {
        LinkedList linkedList1({4});
        LinkedList linkedList2({2});
        linkedList1.mergeSortedList(linkedList2);
        REQUIRE(linkedList1 == LinkedList({2, 4}));
    }
}
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
}
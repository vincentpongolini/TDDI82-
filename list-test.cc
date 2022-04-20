
#include "List.h"
#include "catch.hpp"
#include <iostream>

TEST_CASE( "Create list" )
{
    List lst{1,4,2,6,8,9};
    CHECK(lst.at(2) == 2);
    CHECK(lst.size() == 6);
    List l2;
    l2 = lst;
    CHECK(l2.size() == lst.size());
    CHECK(l2.front() == lst.front());
    CHECK(l2.back() == lst.back());
}

TEST_CASE( "Swap" )
{
    List l1{1,4,2,6,8,9};
    List l2{5,9,1,4,6};
    l2.swap(l1);
    CHECK(l1.at(2) == 1);
    CHECK(l2.at(4) == 8);
    CHECK(l1.size() == 5);
    CHECK(l2.size() == 6);
    
}

TEST_CASE( "Push front and push back" )
{
    List l1{1,4,2,6,8,9};
    l1.push_front(4);
    CHECK(l1.at(0) == 4);
    CHECK(l1.size() == 7);
    l1.push_back(5);
    CHECK(l1.at(7) == 5);
    CHECK(l1.size() == 8);
}

TEST_CASE("Iterators")
{
    List l1{5,4,3,7,1};
    auto rb { std::make_reverse_iterator(l1.end()) };
    auto re { std::make_reverse_iterator(l1.begin()) };
    for ( auto it = rb; it != re; ++it )
    {
	std::cout << *it << ' ';
    }
}

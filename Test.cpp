#include "Board.hpp"
#include "Direction.hpp"
#include "doctest.h"
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;
ariel::Board board;

TEST_CASE("Good case")
{
    // 00:Hey__
    // 01:whats
    // 02:up___
    // 03:with_
    // 04:you?_
    board.post(0, 0, Direction::Horizontal, "Hey");
    board.post(1, 0, Direction::Horizontal, "whats");
    board.post(2, 0, Direction::Horizontal, "up");
    board.post(3, 0, Direction::Horizontal, "with");
    board.post(4, 0, Direction::Horizontal, "you?");
    CHECK(board.read(0, 0, Direction::Horizontal, 3) == string("Hey"));
    CHECK(board.read(1, 0, Direction::Horizontal, 5) == string("whats"));
    CHECK(board.read(2, 0, Direction::Horizontal, 2) == string("up"));
    CHECK(board.read(3, 0, Direction::Horizontal, 4) == string("with"));
    CHECK(board.read(4, 0, Direction::Horizontal, 4) == string("you?"));
    board.post(0, 0, Direction::Vertical, "Night");
    // 00:Ney__
    // 01:ihats
    // 02:gp___
    // 03:hith_
    // 04:tou?_
    CHECK(board.read(0, 0, Direction::Vertical, 5) == string("Night"));
    CHECK(board.read(0, 0, Direction::Horizontal, 3) == string("Ney"));
    CHECK(board.read(1, 0, Direction::Horizontal, 5) == string("ihats"));
    CHECK(board.read(2, 0, Direction::Horizontal, 2) == string("gp"));
    CHECK(board.read(3, 0, Direction::Horizontal, 4) == string("hith"));
    CHECK(board.read(4, 0, Direction::Horizontal, 4) == string("tou?"));
    board.post(0, 0, Direction::Vertical, "_____");
    // 00:_ey__
    // 01:_hats
    // 02:_p___
    // 03:_ith_
    // 04:_ou?_
    CHECK(board.read(0, 0, Direction::Vertical, 5) == string("_____"));
    CHECK(board.read(0, 0, Direction::Horizontal, 3) == string("_ey"));
    CHECK(board.read(1, 0, Direction::Horizontal, 5) == string("_hats"));
    CHECK(board.read(2, 0, Direction::Horizontal, 2) == string("_p"));
    CHECK(board.read(3, 0, Direction::Horizontal, 4) == string("_ith"));
    CHECK(board.read(4, 0, Direction::Horizontal, 4) == string("_ou?"));
    board.post(2,5,Direction::Vertical,"ubmarine");
    // 00:_ey__
    // 01:_hats
    // 02:_p__u
    // 03:_ithb
    // 04:_ou?m
    // 05:____a
    // 06:____r
    // 07:____i
    // 08:____n
    // 09:____e
    CHECK(board.read(1,5,Direction::Vertical,9)==string("submarine"));
    board.post(6,4,Direction::Horizontal,"ead");
    // 00:_ey_____
    // 01:_hats___
    // 02:_p__u___
    // 03:_ithb___
    // 04:_ou?m___
    // 05:____a___
    // 06:____read
    // 07:____i___
    // 08:____n___
    // 09:____e___
    CHECK(board.read(6,5,Direction::Vertical,4)==string("read"));
    CHECK(board.read(4,3,Direction::Horizontal,3)==string("?m_"));
}

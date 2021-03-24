#include <iostream>
#include "doctest.h"
#include "Board.hpp"
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
using namespace ariel;
using namespace std;
Board board;

TEST_CASE("check if board is really initiallzed properly")
{

    CHECK(board.read(50, 50, Direction::Vertical, 10) == string("__________"));
    CHECK(board.read(13, 7, Direction::Horizontal, 6) == string("______"));
    CHECK(board.read(0, 10, Direction::Horizontal, 1) == string("_"));
    CHECK(board.read(10, 0, Direction::Horizontal, 2) == string("__"));
    CHECK(board.read(100, 200, Direction::Vertical, 1) == string("_"));
    CHECK(board.read(5, 7, Direction::Vertical, 2) == string("__"));
}

TEST_CASE("post correct")
{
    CHECK_NOTHROW(board.post(0, 0, Direction::Horizontal, "hey"));
    CHECK_NOTHROW(board.post(3, 4, Direction::Vertical, "my"));
    CHECK_NOTHROW(board.post(5, 8, Direction::Horizontal, "name"));
    CHECK_NOTHROW(board.post(9, 10, Direction::Horizontal, "is"));
    CHECK_NOTHROW(board.post(11, 23, Direction::Vertical, "freaky freaky"));
    CHECK_NOTHROW(board.post(24, 33, Direction::Vertical, "slim shady"));
}
TEST_CASE("post and read correct")
{
    board.post(0, 0, Direction::Horizontal, "hey");
    board.post(3, 4, Direction::Vertical, "my");
    board.post(5, 8, Direction::Horizontal, "name");
    board.post(9, 10, Direction::Horizontal, "is");
    board.post(11, 23, Direction::Vertical, "freaky freaky");
    board.post(24, 33, Direction::Vertical, "slim shady");

    CHECK(board.read(0, 0, Direction::Horizontal, 3) == string("hey"));
    CHECK(board.read(3, 4, Direction::Vertical, 2) == string("my"));
    CHECK(board.read(5, 8, Direction::Horizontal, 4) == string("name"));
    CHECK(board.read(9, 10, Direction::Horizontal, 2) == string("is"));
    CHECK(board.read(11, 23, Direction::Vertical, 13) == string("freaky freaky"));
    CHECK(board.read(24, 33, Direction::Vertical, 10) == string("slim shady"));

    CHECK(board.read(0, 0, Direction::Vertical, 3) == string("h__"));
    CHECK(board.read(3, 4, Direction::Horizontal, 2) == string("m_"));
    
    
}
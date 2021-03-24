#include <string>
#include <iostream>
#include <array>
#include <stdexcept>
#include <vector>
#include "Direction.hpp"
const int ALOT = 1000;
using namespace std;
namespace ariel
{
    class Board
    {
        unsigned int row;
        unsigned int col;
        vector<vector<char>> board;
        public:
        Board(){
            board = vector<vector<char>>(ALOT , vector<char> (ALOT, '_')); 
            row = ALOT;
            col = ALOT;

        }

        void post( unsigned int row,  unsigned int colum, Direction direct, std::string message);
        std::string read( unsigned int row,  unsigned int colum, Direction direct,  unsigned int length);
        void show();
    };
}
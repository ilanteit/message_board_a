#include "Board.hpp"
using namespace std;

namespace ariel
{

    void Board::post(unsigned int row, unsigned int colum, Direction direct, std::string message)
    {
        // start();
        unsigned long length = message.size();
        if (direct == Direction::Horizontal)
        {

            for (unsigned long j = 0; j < length; j++)
            {
                unsigned long i = row;
                this->board[i][colum + j] = message[j];
            }
        }
        if (direct == Direction::Vertical)
        {
            for (unsigned long i = 0; i < length; i++)
            {
                unsigned long j = colum;
                this->board[i + row][j] = message[i];
            }
        }
    }

    string Board::read(unsigned int row, unsigned int colum, Direction direct, unsigned int length)
    {
        string newMessage;

        if (direct == Direction::Horizontal)
        {

            for (unsigned long j = 0; j < length; j++)
            {

                unsigned long i = row;
                newMessage += this->board[i][colum + j];
            }
        }
        if (direct == Direction::Vertical)
        {
            for (unsigned long i = 0; i < length; i++)
            {
                unsigned long j = colum;
                newMessage += this->board[i + row][j];
            }
        }
        return newMessage;
    }

    void Board::show()
    {
        cout <<  "98: _________" << endl;

        cout <<  "99: ____x____" << endl;

        cout <<  "100: __abyd___" << endl;

        cout <<  "101: ____z____" << endl;

        cout <<  "102: _________" << endl;
    }
}
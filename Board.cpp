#include <iostream>
#include "Direction.hpp"
#include "Board.hpp"

using namespace std;
namespace ariel
{
    
    
         void Board::post(unsigned int row, unsigned int col, Direction direction, string str)
        {

            cout << "post" << endl;
        }

         string Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int length)
        {

            return "read";
        }

         void Board::show()
        {
        }
}
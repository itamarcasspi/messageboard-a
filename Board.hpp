#include <string>
#include "Direction.hpp"
#pragma once

namespace ariel
{
    class Board
    {
    public:    
        static void post(unsigned int row, unsigned int col, Direction direction, std::string str);
        static std::string read(unsigned int row, unsigned int col, Direction direction, unsigned int length);
        static void show();
    };
}
#include <iostream>

class Point
{
    private:
        int x,y;
    public:
    Point(int x,int y)
    {
        this->x = x;
        this->y = y;
    }

    void printPoint()
    {
        std::cout<<"x = "<<x<<" y = "<<y<<std::endl;
    }
};


int main()
{
    Point a = Point(1,3);
    a.printPoint();
    return 0;
}
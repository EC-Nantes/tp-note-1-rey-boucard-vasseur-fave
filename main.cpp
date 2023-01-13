#include <stdio.h>
#include <iostream>
#include "Point2D.hpp"
using namespace std;

int main() {
    // printf() displays the string inside quotation
    std::cout << "Hello world !\n" << std::endl;

    int a = 3;
    int b = 5;

    Point2D<int> point(a,b);
    cout << "X point 1 : " << point.getX() << "  Y point 1 : " << point.getY() << endl;
    point.translater(2, 6);
    cout << "X point translaté : " << point.getX() << "  Y point translaté : " << point.getY() << endl;
    Point2D<int> point2(point);
    cout << "X point 2 : " << point2.getX() << "  Y point 2 : " << point2.getY() << endl;
    cout << point;

   return 0;
}

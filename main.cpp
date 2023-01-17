#include <stdio.h>
#include "Parcelle.hpp"
#include "ZU.hpp"


void test_creationPoint()
{
    std::cout << " ~~~~~~" << __func__ << "~~~~~~" << std::endl;
    int a = 3;
    int b = 5;

    Point2D<int> point(a,b);
    std::cout << "X point 1 : " << point.getX() << "  Y point 1 : " << point.getY() << std::endl;
    point.translater(2, 6);
    std::cout << "X point translate : " << point.getX() << "  Y point translate : " << point.getY() << std::endl;
    Point2D<int> point2(point);
    std::cout << "X point 2 : " << point2.getX() << "  Y point 2 : " << point2.getY() << std::endl;
    std::cout << point;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}

void test_creationPolygone()
{
    std::cout << " ~~~~~~" << __func__ << "~~~~~~" << std::endl;
    int a = 3;
    int b = 5;
    int c = 8;
    int d = 1;

    Point2D<int> p1(a, b);
    Point2D<int> p2(c, d);
    vector<Point2D<int>> listeSommets;
    listeSommets.push_back(p1);
    listeSommets.push_back(p2);

    Polygone<int> Poly1(listeSommets);
    std::cout << Poly1 << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}
void test_calculSurface()
{
    std::cout << " ~~~~~~" << __func__ << "~~~~~~" << std::endl;
    int a = 3;
    int b = 5;
    int c = 8;
    int d = 1;

    Point2D<int> p1(3, 3);
    Point2D<int> p2(1, 3);
    Point2D<int> p3(1, 1);
    Point2D<int> p4(3, 1);
    vector<Point2D<int>> listeSommets;
    listeSommets.push_back(p1);
    listeSommets.push_back(p2);
    listeSommets.push_back(p3);
    listeSommets.push_back(p4);

    Polygone<int> Poly1(listeSommets);
    std::cout << Poly1 << std::endl;
    //Parcelle<int> parc(1, "toto", Poly1);
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}

int main() {
    test_creationPoint();
    test_creationPolygone();
    test_calculSurface();
    return 0;
}




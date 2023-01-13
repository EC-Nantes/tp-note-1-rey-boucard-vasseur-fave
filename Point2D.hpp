/*
 * Point2D.hpp
 *
 *  Created on: 13 jan. 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

template<typename T>
class Point2D;

template<typename T>
std::ostream& operator<<(std::ostream &, Point2D<T> const&);

template<typename T>
class Point2D {
protected:
    T x;
    T y;
public:
	Point2D(T _x, T _y);
    Point2D(Point2D<T> const &);
    Point2D(void);
    T getX() const;
    void setX(T x);
    T getY() const;
    void setY(T x);
    void translater(T a, T b);

	friend std::ostream& operator<< <T>(std::ostream& os, Point2D<T> const &R);
};

template<typename T>
Point2D<T>::Point2D(T x, T y){
    this->x = x;
    this->y = y;
}

template<typename T>
Point2D<T>::Point2D(Point2D<T> const & Point2D){
    this->x = Point2D.getX();
    this->y = Point2D.getY();
}

template<typename T>
Point2D<T>::Point2D(void){
    this->x = (T) 0;
    this->y = (T) 0;
}

template<typename T>
T Point2D<T>::getX() const{
    return this->x;
}

template<typename T>
void Point2D<T>::setX(T x){
    this->x = x;
}

template<typename T>
T Point2D<T>::getY() const{
    return this->y;
}

template<typename T>
void Point2D<T>::setY(T y){
    this->y = y;
}

template<typename T>
void Point2D<T>::translater(T a, T b){
    this->x += a;
    this->y += b;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Point2D<T> const &Point2D){
	os << "x = " << Point2D.getX() << ", y = " << Point2D.getY() << ";" << std::endl;
	return os;
}

#endif /*POINT2D_H*/
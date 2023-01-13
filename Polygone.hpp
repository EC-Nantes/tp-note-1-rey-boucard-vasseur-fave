/*
 * Polygone.hpp
 *
 *  Created on: 13 jan. 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef POLYGONE_HPP
#define POLYGONE_HPP

#include <vector>
#include "Point2D.hpp"

template <typename T>
class Polygone;

template <typename T>
std::ostream& operator<<(std::ostream &, Polygone<T> const&);

template <typename T>
class Polygone
{
protected:
    vector<Point2D<T>> sommets_;

public:
    /*Constructeurs*/
    Polygone();
    Polygone(vector<Point2D<T>> listeSommets);
    Polygone(Polygone<T> const& poly);

    /*Getters*/
    vector<Point2D<T>> getSommets() const;

    /*Setters*/
    void setSommets(vector<Point2D<T>> listeSommets);

    /*Methods*/
    void addPoint(Point2D<T> p);
    void translate(T x, T y);
    friend std::ostream& operator<< <T>(std::ostream &, Polygone const&);
};

template<typename T>
Polygone<T>::Polygone(){
}

template<typename T>
Polygone<T>::Polygone(vector<Point2D<T>> listeSommets){
    this->sommets_ = listeSommets;
}

template<typename T>
Polygone<T>::Polygone(Polygone<T> const& poly){
    this->sommets_ = poly.getSommets();
}

template<typename T>
vector<Point2D<T>> Polygone<T>::getSommets() const{
    return this->sommets_;
}

template<typename T>
void Polygone<T>::setSommets(vector<Point2D<T>> listeSommets){
    this->sommets_.clear();
    this->sommets_ = listeSommets;
}

template<typename T>
void Polygone<T>::addPoint(Point2D<T> p){
    this->sommets_.push_back(p);
}

template<typename T>
void Polygone<T>::translate(T x, T y){
    for(auto i = this->sommets_.begin(); i != this->sommets_.end(); i++){
        this->sommets_[i].x += x;
        this->sommets_[i].y += y;
    }
}

template <typename T>
std::ostream& operator<<(std::ostream &output, Polygone<T> const &p)
{
    int nb_sommets = 0;
    output << "Le polygone a pour sommets : {" << std::endl;
    for(auto i = p.sommets_.begin(); i != p.sommets_.end(); i++){
        output << "p" << nb_sommets << " : " << *i;
        nb_sommets++;
    }
    output << "}";
    return output;
}

#endif /* RECTANGLE_H */
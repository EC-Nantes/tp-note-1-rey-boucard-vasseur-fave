/*
 * ZU.hpp
 *
 *  Created on: 13 jan. 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef ZU_HPP
#define ZU_HPP 

#include <cstdlib>
#include <random>
#include "Parcelle.hpp"
#include "Constructible.hpp"

template <typename T>
class ZU;

template <typename T>
std::ostream& operator<<(std::ostream &, ZU<T> const&);

template <typename T>
class ZU : public Parcelle<T>, public Constructible{
private:
    float surfaceConstructible_;
    float surfaceConstruite;
public:
    /* Constructeurs */
    ZU(int num, string prop, Polygone<T> forme);
    ZU(Parcelle<T> const& parc);

    /* Méthodes */
    void setType(string type_);
    float getsurfaceConstructible();
    float getsurfaceConstruite();
    void surfaceConstructible();
    friend std::ostream& operator<< <T>(std::ostream &, ZU const&);
};

template<typename T>
ZU<T>::ZU(int num, string prop, Polygone<T> forme) : Parcelle<T> (num, prop, forme){
    this->setType("ZU");
    this->pConstructible = 1;
    this->surfaceConstructible();
}

template<typename T>
ZU<T>::ZU(Parcelle<T> const& parc) : Parcelle<T> (parc){
    this->setType("ZU");
    this->pConstructible = 1;
    this->surfaceConstructible();
}

template<typename T>
void ZU<T>::setType(string type_){
    this->type = type_;
}

template<typename T>
float ZU<T>::getsurfaceConstructible(){
    return this->surfaceConstructible_;    
}

template<typename T>
float ZU<T>::getsurfaceConstruite(){
    return this->surfaceConstruite;    
}

template<typename T>
void ZU<T>::surfaceConstructible(){
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<double> dist(1.0f, this->getSurface()); 
    surfaceConstructible_ = dist(gen);
    std::uniform_real_distribution<double> dis(1.0f, surfaceConstructible_); 
    surfaceConstruite = dis(gen);
}

template <typename T>
std::ostream& operator<<(std::ostream &output, ZU<T> const &parc)
{
    output << "Parcelle n°" << parc.getNumero() << " :" << std::endl;
    output << "\tType : " << parc.getType() << std::endl;
    output << "\tPolygone : " << parc.getForme() << std::endl;
    output << "\tProprietaire : " << parc.getProprietaire() << std::endl;
    output << "\tSurface : " << parc.getSurface() << std::endl;
    return output;
}

#endif /*ZU.HPP*/
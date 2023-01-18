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
    ZU(int num, string prop, int pConstructible_, float surfaceConstruite_, Polygone<T> forme);
    ZU(Parcelle<T> const& parc, int pConstructible_, float surfaceConstruite_);

    /* Méthodes */
    void setType(string type_);
    float getsurfaceConstructible();
    float getsurfaceConstruite();
    void surfaceConstructible();
    friend std::ostream& operator<< <T>(std::ostream &, ZU const&);
};

template<typename T>
ZU<T>::ZU(int num, string prop, int pConstructible_, float surfaceConstruite_, Polygone<T> forme) : Parcelle<T> (num, prop, forme){
    this->setType("ZU");
    this->pConstructible = pConstructible_;
    this->surfaceConstruite = surfaceConstruite_;
    this->surfaceConstructible();
}

template<typename T>
ZU<T>::ZU(Parcelle<T> const& parc, int pConstructible_, float surfaceConstruite_) : Parcelle<T> (parc){
    this->setType("ZU");
    this->pConstructible = pConstructible_;
    this->surfaceConstruite = surfaceConstruite_;
    this->surfaceConstructible();
}

template<typename T>
void ZU<T>::setType(string type_){
    this->type = type_;
}

template<typename T>
float ZU<T>::getsurfaceConstruite(){
    return this->surfaceConstruite;    
}

template<typename T>
float ZU<T>::getsurfaceConstructible(){
    return this->surfaceConstructible_;    
}

template<typename T>
void ZU<T>::surfaceConstructible(){
    std::random_device rd;  
    std::mt19937 gen(rd());
    this->surfaceConstructible_ = this->pConstructible * this->getSurface();
    this->surfaceConstructible_ -= this->surfaceConstruite;
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
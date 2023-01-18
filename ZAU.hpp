/*
 * ZAU.hpp
 *
 *  Created on: 13 jan. 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef ZAU_HPP
#define ZAU_HPP 

#include <cstdlib>
#include <random>
#include "Parcelle.hpp"
#include "Constructible.hpp"

template <typename T>
class ZAU;

template <typename T>
std::ostream& operator<<(std::ostream &, ZAU<T> const&);

template <typename T>
class ZAU : public Parcelle<T>, public Constructible{
private:
    float surfaceConstructible_;
public:
    /* Constructeurs */
    ZAU(int num, string prop, int pConstructible_, Polygone<T> forme);
    ZAU(Parcelle<T> const& parc, int pConstructible_);

    /* Méthodes */
    void setType(string type_);
    float getsurfaceConstructible();
    void surfaceConstructible(void);
    friend std::ostream& operator<< <T>(std::ostream &, ZAU const&);
};

template<typename T>
ZAU<T>::ZAU(int num, string prop, int pConstructible_, Polygone<T> forme) : Parcelle<T> (num, prop, forme){
    this->setType("ZAU");
    this->pConstructible = pConstructible_;
    this->surfaceConstructible();
}

template<typename T>
ZAU<T>::ZAU(Parcelle<T> const& parc, int pConstructible_) : Parcelle<T> (parc){
    this->setType("ZAU");
    this->pConstructible = pConstructible_;
    this->surfaceConstructible();
}

template<typename T>
void ZAU<T>::setType(string type_){
    this->type = type_;
}

template<typename T>
float ZAU<T>::getsurfaceConstructible(){
    return this->surfaceConstructible_;
}

template<typename T>
void ZAU<T>::surfaceConstructible(void){
    this->surfaceConstructible_ = this->getSurface() * this->pConstructible;
}

template <typename T>
std::ostream& operator<<(std::ostream &output, ZAU<T> const &parc)
{
    output << "Parcelle n°" << parc.getNumero() << " :" << std::endl;
    output << "\tType : " << parc.getType() << std::endl;
    output << "\tPolygone : " << parc.getForme() << std::endl;
    output << "\tProprietaire : " << parc.getProprietaire() << std::endl;
    output << "\tSurface : " << parc.getSurface() << std::endl;
    return output;
}

#endif /*ZAU.HPP*/
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
    ZAU(int num, string prop, Polygone<T> forme);
    ZAU(Parcelle<T> const& parc);

    /* Méthodes */
    void setType(string type_);
    float getsurfaceConstructible();
    void surfaceConstructible(void);
    friend std::ostream& operator<< <T>(std::ostream &, ZAU const&);
};

template<typename T>
ZAU<T>::ZAU(int num, string prop, Polygone<T> forme) : Parcelle<T> (num, prop, forme){
    this->setType("ZAU");
    this->pConstructible = 1;
    this->surfaceConstructible();
}

template<typename T>
ZAU<T>::ZAU(Parcelle<T> const& parc) : Parcelle<T> (parc){
    this->setType("ZAU");
    this->pConstructible = 1;
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
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<double> dist(1.0f, 100.0f); 
    this->pConstructible = dist(gen);
    this->surfaceConstructible_ = this->getSurface() * this->pConstructible;
}

template <typename T>
std::ostream& operator<<(std::ostream &output, ZAU<T> const &parc)
{
    output << "Parcelle n*" << parc.getNumero() << " :" << std::endl;

    output << "\tType : " << parc.getType() << std::endl;
    output << "\tPolygone : " << parc.getForme() << std::endl;
    output << "\tProprietaire : " << parc.getProprietaire() << std::endl;
    output << "\tSurface : " << parc.getSurface() << std::endl;
    output << "\t % constructible : " << parc.getPConstructible() << " % " << std::endl;
    return output;
}

#endif /*ZAU.HPP*/
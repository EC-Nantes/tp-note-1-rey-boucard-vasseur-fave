/*
 * ZN.hpp
 *
 *  Created on: 13 jan. 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef ZN_HPP
#define ZN_HPP 

#include "Parcelle.hpp"

template <typename T>
class ZN;

template <typename T>
std::ostream& operator<<(std::ostream &, ZN<T> const&);

template <typename T>
class ZN : public Parcelle{
public:
    /*Constructeurs*/
    ZN(int num, string prop, Polygone<T> forme);
    ZN(Parcelle const& parc);

    /*Methods*/
    void setType(string type);
    friend std::ostream& operator<< <T>(std::ostream &, ZN const&);
};

template<typename T>
ZN<T>::ZN(int num, string prop, Polygone<T> forme) : Parcelle(num, prop, forme){
    this->setType("ZN");
    this->pConstructible = 0;
}

template<typename T>
ZN<T>::ZN(Parcelle const& parc) : Parcelle(parc){
    this->setType("ZN");
    this->pConstructible = 0;
}

template<typename T>
void ZN<T>::setType(string type){
    this->type = type;    
}

template <typename T>
std::ostream& operator<<(std::ostream &output, ZN<T> const &parc)
{
    output << "Parcelle n°" << parc.getNumero() << " :" << std::endl;
    output << "\tType : " << parc.getType() << std::endl;
    output << "\tPolygone : " << parc.getForme() << std::endl;
    output << "\tProprietaire : " << parc.getProprietaire() << std::endl;
    output << "\tSurface : " << parc.getSurface() << std::endl;
    return output;
}

#endif /*ZN.HPP*/
/*
 * Carte.hpp
 *
 *  Created on: 18 jan. 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef CARTE_HPP
#define CARTE_HPP

#include "Parcelle.hpp"
#include "ZA.hpp"
#include "ZU.hpp"
#include "ZAU.hpp"
#include "ZN.hpp"

template<typename T>
class Carte;

template<typename T>
std::ostream& operator<<(std::ostream &, Carte<T> const&);

template<typename T>
class Carte {
protected:
    float surface_totale_;
    vector<Parcelle<T>> list_Parcelles_;
public:
    Carte();

    float getSurfaceTotale() const;
    vector<Parcelle<T>> getListParcelles() const;
	friend std::ostream& operator<< <T>(std::ostream& os, Carte<T> const &C);
};

template<typename T>
Carte<T>::Carte(){
    this->surface_totale_ = 0;
}

template<typename T>
float Carte<T>::getSurfaceTotale() const{
    return this->surface_totale_;
}

template<typename T>
vector<Parcelle<T>> Carte<T>::getListParcelles() const{
    return this->list_Parcelles_;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Carte<T> const &C){
	for(auto i = C.list_Parcelles_.begin(); i != C.list_Parcelles_.end(); i++){
        output << *i;
    }
	return os;
}

#endif /*CARTE_HPP*/
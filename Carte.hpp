/*
 * Carte.hpp
 *
 *  Created on: 18 jan. 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef CARTE_HPP
#define CARTE_HPP

#include <fstream>

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
std::ofstream& operator<<(std::ofstream &, Carte<T> const&);

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
    friend std::ofstream& operator<< <T>(std::ofstream& file, Carte<T> const &C);
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
        os << *i;
    }
	return os;
}

template<typename T>
std::ofstream& operator<<(std::ofstream& file, Carte<T> const &C){
	string type_parcelle;
    for(auto i = C.list_Parcelles_.begin(); i != C.list_Parcelles_.end(); i++){
        type_parcelle = (*i).getType();
        file << type_parcelle << (*i).getNumero() << (*i).getProprietaire();
        if(type_parcelle == "ZU"){
            file << (*i).getPConstructible() << (*i).getsurfaceConstruite() << std::endl;
        }
        else if(type_parcelle == "ZAU"){
            file << (*i).getPConstructible() << std::endl;
        }
        else if(type_parcelle == "ZA"){
            file << (*i).gettypeCulture() << std::endl;
        }
        file << (*i).getForme() << std::endl;
    }
	return file;
}

#endif /*CARTE_HPP*/
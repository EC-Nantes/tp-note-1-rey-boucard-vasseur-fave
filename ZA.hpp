/*
 * ZA.hpp
 *
 *  Created on: 13 jan. 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef ZA_HPP
#define ZA_HPP 

#include <random>
#include "Parcelle.hpp"
#include "Constructible.hpp"

template <typename T>
class ZA;

template <typename T>
std::ostream& operator<<(std::ostream &, ZA<T> const&);

template <typename T>
class ZA : public Parcelle<T>, public Constructible{
private:
    string typeCulture;
    float surfaceConstructible_;
public:
    /*Constructeurs*/
    ZA(int num, string prop, string typeCultutre_, Polygone<T> forme);
    ZA(Parcelle<T> const& parc, string typeCulture_);

    /*Methods*/
    void setType(string type);
    string gettypeCulture() const;
    float getsurfaceConstructible(void);
    void surfaceConstructible();
    friend std::ostream& operator<< <T>(std::ostream &, ZA const&);
};

template<typename T>
ZA<T>::ZA(int num, string prop, string typeCulture_, Polygone<T> forme) : Parcelle<T> (num, prop, forme){
    this->setType("ZA");
    this->pConstructible = 0;
    this->surfaceConstructible();
    this->typeCulture = typeCulture_;
}

template<typename T>
ZA<T>::ZA(Parcelle<T> const& parc, string typeCulture_) : Parcelle<T> (parc){
    this->setType("ZA");
    this->pConstructible = 0;
    this->surfaceConstructible();
    this->typeCulture = typeCulture_;
}

template<typename T>
void ZA<T>::setType(string type){
    this->type = type;    
}

template<typename T>
string ZA<T>::gettypeCulture() const{
    return this->typeCulture;    
}

template<typename T>
float ZA<T>::getsurfaceConstructible(){
    return this->surfaceConstructible_;    
}

template<typename T>
void ZA<T>::surfaceConstructible(){
    this->surfaceConstructible_ =  this->getSurface() * 0.1;
    this->pConstructible = 10;
    if (this->surfaceConstructible_ > 200){
        this->surfaceConstructible_ = 200;
        this->pConstructible = (200 * 100)/this->getSurface();
    } 
}

template <typename T>
std::ostream& operator<<(std::ostream &output, ZA<T> const &parc)
{
    output << "Parcelle n*" << parc.getNumero() << " :" << std::endl;

    output << "\tType : " << parc.getType() << std::endl;
    output << "\tPolygone : " << parc.getForme() << std::endl;
    output << "\tProprietaire : " << parc.getProprietaire() << std::endl;
    output << "\tSurface : " << parc.getSurface() << std::endl;
    output << "\tType culture : " << parc.gettypeCulture() << std::endl;

    return output;
}

#endif /*ZA.HPP*/
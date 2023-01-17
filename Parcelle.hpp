/*
 * Parcelle.hpp
 *
 *  Created on: 07 dec. 2022
 *      Author: REY Maxime, BOUCARD Romain, VASSEUR François, FAVE Jonathan
 */

#ifndef Parcelle_H_
#define Parcelle_H_

#include <iostream>
#include <fstream>
#include <string.h>
#include "Polygone.hpp"

using namespace std;

template <typename T>
class Parcelle {
private:
   int numero;
   string proprietaire;
   float surface;
   Polygone<int> forme;

protected:
   string type;
   int pConstructible;

public:
    Parcelle(int num, string prop, Polygone<T> forme); 
    Parcelle(Parcelle const& parc);
    Parcelle(void);
    
    float calculerSurface();
    //getters
    string getType() const;
    int getNumero() const;
    string getProprietaire() const;
    float getSurface() const;
    Polygone<int> getForme() const;
    int getPConstructible() const;

    //setters
    virtual void setType(string type) = 0;
    void setNumero(int numero);
    void setProprietaire(string proprietaire);
    void setForme(Polygone<int> forme);

    // virtual ~Parcelle();
};

template <typename T>
float Parcelle<T>::calculerSurface()
{
    float surface = 0;
    vector<Point2D<int>> sommets = this->forme.getSommets();
    int nombre_sommets = sommets.size();
    for (int i=0; i<nombre_sommets-1; i++){
        surface += sommets[i].getX()*sommets[i+1].getY() - sommets[i+1].getX()*sommets[i].getY();
    }
    //affiche sommets 
    surface += sommets[nombre_sommets-1].getX()*sommets[0].getY() - sommets[0].getX()*sommets[nombre_sommets-1].getY();
    surface = surface/2;
    std::cout << "Surface : " << surface << endl;
    return surface;
}

//contructors
template <typename T>
Parcelle<T>::Parcelle(int num, string prop, Polygone<T> forme)
{
    this->numero = num;
    this->proprietaire = prop;
    this->forme =  forme;
    this->surface = calculerSurface();
    this->type = "Parcelle";
}

template <typename T>
Parcelle<T>::Parcelle(Parcelle const& parc) {
    this->numero = parc.getNumero();
    this->proprietaire = parc.getProprietaire();
    this->surface = parc.getSurface();
    this->type = parc.getType();
    this->forme = parc.getForme();
}

template <typename T>
Parcelle<T>::Parcelle(void) {
    this->numero = 0;
    this->proprietaire = "";
    this->surface = 0;
    this->type = "Parcelle";
}

//getters 
template <typename T>
string Parcelle<T>::getType() const {
    return this->type;
}
template <typename T>
int Parcelle<T>::getNumero() const {
    return this->numero;
}
template <typename T>
string Parcelle<T>::getProprietaire() const {
    return this->proprietaire;
}
template <typename T>
float Parcelle<T>::getSurface() const {
    return this->surface;
}
template <typename T>
Polygone<int> Parcelle<T>::getForme() const {
    return this->forme;
}
template <typename T>
int Parcelle<T>::getPConstructible() const {
    return this->pConstructible;
}

//setters
template <typename T>
void Parcelle<T>::setNumero(int numero) {
    this->numero = numero;
}
template <typename T>
void Parcelle<T>::setProprietaire(string proprietaire) {
    this->proprietaire = proprietaire;
}

template <typename T>
void Parcelle<T>::setForme(Polygone<int> forme) {
    this->forme = forme;
    this->surface = calculerSurface();
}

#endif /* Parcelle_H_ */
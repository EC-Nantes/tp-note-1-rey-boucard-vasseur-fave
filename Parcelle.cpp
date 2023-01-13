#include "Parcelle.hpp"
#include "Point2D.hpp"
#include <vector>

//contructors

float Parcelle::calculerSurface()
{
    float surface = 0;
    vector<Point2D<int>> sommets = this->forme.getSommets();
    
    for (int i=0; i<sommets.size(); i++){
        surface += sommets[i].getX()*sommets[i+1].getY() - sommets[i+1].getX()*sommets[i].getY();
    }
    surface = surface/2;
    return surface;
}

Parcelle::Parcelle(int num, string prop)
{
    this->numero = num;
    this->proprietaire = prop;
    this->surface = 0;
    this->pConstructible = 0;
    this->type = "Parcelle";
}

Parcelle::Parcelle(Parcelle parc) {
    this->numero = parc.getNumero();
    this->proprietaire = parc.getProprietaire();
    this->surface = parc.getSurface();
    this->pConstructible = parc.getPConstructible();
    this->type = parc.getType();
}


Parcelle::Parcelle(void) {
    this->numero = 0;
    this->proprietaire = "";
    this->surface = 0;
    this->pConstructible = 0;
    this->type = "Parcelle";
}

#getters 

string Parcelle::getType() const {
    return this->type;
}

int Parcelle::getNumero() const {
    return this->numero;
}

string Parcelle::getProprietaire() const {
    return this->proprietaire;
}

float Parcelle::getSurface() const {
    return this->surface;
}

//Polygone<int> Parcelle::getForme() const {

//    return this->forme;
//}

int Parcelle::getPConstructible() const {
    return this->pConstructible;
}

#setters

void Parcelle::setNumero(int numero) {
    this->numero = numero;
}

void Parcelle::setProprietaire(string proprietaire) {
    this->proprietaire = proprietaire;
}

void Parcelle::setSurface(float surface) {
    this->surface = surface;
}

//void Parcelle::setForme(Polygone<int> forme) {

//    this->forme = forme;
//}

void Parcelle::setPConstructible(int pConstructible) {
    this->pConstructible = pConstructible;
}

//calcul surface of any polygon
 



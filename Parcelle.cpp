#include "Parcelle.hpp"
#include "Point2D.hpp"
#include <vector>



float Parcelle::calculerSurface()
{
    float surface = 0;
    vector<Point2D<int>> sommets = this->forme.getSommets();
    //std::cout << sommets.size();
    int nombre_sommets = sommets.size();
    int var = 0;
    for (int i=0; i<nombre_sommets-1; i++){
        var = sommets[i].getX()*sommets[i+1].getY() - sommets[i+1].getX()*sommets[i].getY();
        surface += var;
        std::cout << "var : " << var << endl;
    }
    surface = surface/2;
    return surface;
}

//contructors
Parcelle::Parcelle(int num, string prop)
{
    this->numero = num;
    this->proprietaire = prop;
    this->surface = calculerSurface();
    this->pConstructible = 0;
    this->type = "Parcelle";
}

Parcelle::Parcelle(Parcelle const& parc) {
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

//getters 

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

Polygone<int> Parcelle::getForme() const {
    return this->forme;
}

int Parcelle::getPConstructible() const {
    return this->pConstructible;
}

//setters

void Parcelle::setNumero(int numero) {
    this->numero = numero;
}

void Parcelle::setProprietaire(string proprietaire) {
    this->proprietaire = proprietaire;
}

void Parcelle::setSurface(float surface) {
    this->surface = surface;
}

void Parcelle::setForme(Polygone<int> forme) {
    this->forme = forme;
    this->surface = calculerSurface();
}

void Parcelle::setPConstructible(int pConstructible) {
    this->pConstructible = pConstructible;
}


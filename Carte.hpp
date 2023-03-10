/*
 * Carte.hpp
 *
 *  Created on: 18 jan. 2023
 *      Author: REY Maxime, BOUCARD Romain, FAVE Jonathan, VASSEUR Francois
 */

#ifndef CARTE_HPP
#define CARTE_HPP

#include <iostream>
#include <fstream>
#include <sstream>

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
    vector<Parcelle<T>*> list_Parcelles_;
public:
    Carte(std::string file);

    void parseFile(std::string filename);
    int getNbwords(std::string line);
    void createSommets(std::string line, vector<Point2D<T>> *Sommets);
    void calculSurfaceTotale(void);
    float getSurfaceTotale() const;
    vector<Parcelle<T>*> getListParcelles() const;
	
    friend std::ostream& operator<< <T>(std::ostream& os, Carte<T> const &C);
    friend std::ofstream& operator<< <T>(std::ofstream& file, Carte<T> const &C);
};

template<typename T>
Carte<T>::Carte(std::string file){
    this->parseFile(file);
    this->surface_totale_ = 0;
    this->calculSurfaceTotale();
}

template<typename T>
int Carte<T>::getNbwords(std::string line){
    int count = 0;
    for (int i=0; i<line.length(); i++){
        if (line[i] == ' ' && line[i+1]!='\0')count++;
    }
    count++;
    return count;
}

template<typename T>
void Carte<T>::createSommets(std::string line, vector<Point2D<T>> *Sommets){
    int nbwords = getNbwords(line); //Nombre de sommets de la parcelle
    std::istringstream coord(line);
    char a, b, c;
    int x, y;
    
    for (int i=0; i<nbwords; i++){
        coord >> a >> x >> b >> y >> c; //Extraction des coordonnées x et y dans les variables x et y; a=[ b=; et c=]
        Point2D<int> pt(x, y);
        Sommets->push_back(pt);
    }
}

template<typename T>
void Carte<T>::parseFile(std::string filename){
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)){
        std::istringstream iss(line);
        std::string word;
        iss >> word;
        std::string typeParcelle;
        int numero;
        std::string proprietaire;
        std::string typeCulture;
        int pConstructible;
        float surfaceConstruite;

        if (word == "ZA"){
            typeParcelle = word;
            iss >> numero;
            iss >> proprietaire;
            iss >> typeCulture;
            vector<Point2D<T>> Sommets;

            std::getline(file, line);
            createSommets(line, &Sommets);
            Polygone<int> Poly(Sommets);
            ZA<int> *ZoneA;
            ZoneA = new ZA<int>(numero, proprietaire, typeCulture, Poly);
            list_Parcelles_.push_back(ZoneA);
        }else if (word == "ZU"){
            typeParcelle = word;
            iss >> numero;
            iss >> proprietaire;
            iss >> pConstructible;
            iss >> surfaceConstruite;
            vector<Point2D<int>> Sommets;

            std::getline(file, line);
            createSommets(line, &Sommets);
            Polygone<int> Poly(Sommets);
            ZU<int> *ZoneU;
            ZoneU = new ZU<int>(numero, proprietaire, pConstructible, surfaceConstruite, Poly);
            list_Parcelles_.push_back(ZoneU);
        }else if (word == "ZAU"){
            typeParcelle = word;
            iss >> numero;
            iss >> proprietaire;
            iss >> pConstructible;
            iss >> surfaceConstruite;
            vector<Point2D<int>> Sommets;

            std::getline(file, line);
            createSommets(line, &Sommets);
            Polygone<int> Poly(Sommets);
            ZAU<int> *ZoneAU;
            ZoneAU = new ZAU<int>(numero, proprietaire, pConstructible, Poly);
            list_Parcelles_.push_back(ZoneAU);
        }else if (word == "ZN"){
            typeParcelle = word;
            iss >> numero;
            iss >> proprietaire;
            iss >> pConstructible;
            iss >> surfaceConstruite;
            vector<Point2D<int>> Sommets;

            std::getline(file, line);
            createSommets(line, &Sommets);
            Polygone<int> Poly(Sommets);
            ZN<int> *ZoneN;
            ZoneN = new ZN<int>(numero, proprietaire, Poly);
            list_Parcelles_.push_back(ZoneN);
        }
    }
}

template<typename T>
void Carte<T>::calculSurfaceTotale(){
    float surface_temp = 0.0;
    for (auto it = this->list_Parcelles_.begin(); it!=this->list_Parcelles_.end(); it++){
        surface_temp += (*it)->getSurface();
    }
    this->surface_totale_ = surface_temp;
    
}

template<typename T>
float Carte<T>::getSurfaceTotale() const{
    return this->surface_totale_;
}

template<typename T>
vector<Parcelle<T>*> Carte<T>::getListParcelles() const{
    return this->list_Parcelles_;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, Carte<T> const &C){
	for(auto i = C.list_Parcelles_.begin(); i != C.list_Parcelles_.end(); i++){
        os << *i;
        os << *i;
    }
	return os;
}

template<typename T>
std::ofstream& operator<<(std::ofstream& file, Carte<T> const &C){
	string type_parcelle;
    for(auto i = C.list_Parcelles_.begin(); i != C.list_Parcelles_.end(); i++){
        type_parcelle = (*i)->getType();
        file << type_parcelle << " " << (*i)->getNumero() << " " << (*i)->getProprietaire() << " ";
        if(type_parcelle == "ZU"){
            file << (*i)->getPConstructible() << " " << dynamic_cast<ZU<T>*>(*i)->getsurfaceConstruite() << std::endl;
        }
        else if(type_parcelle == "ZAU"){
            file << (*i)->getPConstructible() << std::endl;
        }
        else if(type_parcelle == "ZA"){
            file << dynamic_cast<ZA<T>*>(*i)->gettypeCulture() << std::endl;
        }
        else if(type_parcelle == "ZN"){
            file << std::endl;
        }
        file << (*i)->getForme() << std::endl;
    }
	return file;
}

#endif /*CARTE_HPP*/
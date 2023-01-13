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

class Parcelle {
private:
   
   string type;
   int numero;
   string proprietaire;
   float surface;
   Polygone<int> forme;
   int pConstructible;

public:
    Parcelle(int num, string prop); 
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
    //virtual void setType(string type) = 0;
    void setNumero(int numero);
    void setProprietaire(string proprietaire);
    void setSurface(float surface);
    void setForme(Polygone<int> forme);
    void setPConstructible(int pConstructible);




    // virtual ~Parcelle();


};


#endif /* Parcelle_H_ */
 

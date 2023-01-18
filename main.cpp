#include <stdio.h>
#include "Parcelle.hpp"
#include "ZU.hpp"
#include "ZA.hpp"
#include "ZN.hpp"
#include "ZAU.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


void test_creationPoint()
{
    std::cout << " ~~~~~~" << __func__ << "~~~~~~" << std::endl;
    int a = 3;
    int b = 5;

    Point2D<int> point(a,b);
    std::cout << "X point 1 : " << point.getX() << "  Y point 1 : " << point.getY() << std::endl;
    point.translater(2, 6);
    std::cout << "X point translate : " << point.getX() << "  Y point translate : " << point.getY() << std::endl;
    Point2D<int> point2(point);
    std::cout << "X point 2 : " << point2.getX() << "  Y point 2 : " << point2.getY() << std::endl;
    std::cout << point;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}

void test_creationPolygone()
{
    std::cout << " ~~~~~~" << __func__ << "~~~~~~" << std::endl;
    int a = 3;
    int b = 5;
    int c = 8;
    int d = 1;

    Point2D<int> p1(a, b);
    Point2D<int> p2(c, d);
    vector<Point2D<int>> listeSommets;
    listeSommets.push_back(p1);
    listeSommets.push_back(p2);

    Polygone<int> Poly1(listeSommets);
    std::cout << Poly1 << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}

void test_calculSurface()
{
    std::cout << " ~~~~~~" << __func__ << "~~~~~~" << std::endl;
    int a = 3;
    int b = 5;
    int c = 8;
    int d = 1;

    Point2D<int> p1(3, 3);
    Point2D<int> p2(1, 3);
    Point2D<int> p3(1, 1);
    Point2D<int> p4(3, 1);
    vector<Point2D<int>> listeSommets;
    listeSommets.push_back(p1);
    listeSommets.push_back(p2);
    listeSommets.push_back(p3);
    listeSommets.push_back(p4);

    Polygone<int> Poly1(listeSommets);
    std::cout << Poly1 << std::endl;
    //Parcelle<int> parc(1, "toto", Poly1);
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}

void test_ZU(){
    std::cout << " ~~~~~~" << __func__ << "~~~~~~" << std::endl;

    Point2D<int> p1(3, 3);
    Point2D<int> p2(1, 3);
    Point2D<int> p3(1, 1);
    Point2D<int> p4(3, 1);
    vector<Point2D<int>> listeSommets;
    listeSommets.push_back(p1);
    listeSommets.push_back(p2);
    listeSommets.push_back(p3);
    listeSommets.push_back(p4);

    Polygone<int> Poly1(listeSommets);
    ZU<int> ZoneU(12, "Pierre Dupont", 50, 200.5, Poly1);
    std::cout << ZoneU << endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}

void test_ZA(){
    std::cout << " ~~~~~~" << __func__ << "~~~~~~" << std::endl;

    Point2D<int> p1(3, 3);
    Point2D<int> p2(1, 3);
    Point2D<int> p3(1, 1);
    Point2D<int> p4(3, 1);
    vector<Point2D<int>> listeSommets;
    listeSommets.push_back(p1);
    listeSommets.push_back(p2);
    listeSommets.push_back(p3);
    listeSommets.push_back(p4);

    Polygone<int> Poly1(listeSommets);
    ZA<int> ZoneA(12, "Pierre Dupont", "Ble", Poly1);
    std::cout << ZoneA << endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}

void test_ZAU(){
    std::cout << " ~~~~~~" << __func__ << "~~~~~~" << std::endl;

    Point2D<int> p1(3, 3);
    Point2D<int> p2(1, 3);
    Point2D<int> p3(1, 1);
    Point2D<int> p4(3, 1);
    vector<Point2D<int>> listeSommets;
    listeSommets.push_back(p1);
    listeSommets.push_back(p2);
    listeSommets.push_back(p3);
    listeSommets.push_back(p4);

    Polygone<int> Poly1(listeSommets);
    ZAU<int> ZoneAU(12, "Pierre Dupont", 40, Poly1);
    std::cout << ZoneAU << endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}

void test_ZN(){
    std::cout << " ~~~~~~" << __func__ << "~~~~~~" << std::endl;

    Point2D<int> p1(3, 3);
    Point2D<int> p2(1, 3);
    Point2D<int> p3(1, 1);
    Point2D<int> p4(3, 1);
    vector<Point2D<int>> listeSommets;
    listeSommets.push_back(p1);
    listeSommets.push_back(p2);
    listeSommets.push_back(p3);
    listeSommets.push_back(p4);

    Polygone<int> Poly1(listeSommets);
    ZN<int> ZoneN(12, "Pierre Dupont",  Poly1);
    std::cout << ZoneN << std::endl;

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl << std::endl;
}

int getNbwords(std::string line){
    int count = 0;
    for (int i=0; i<line.length(); i++){
        if (line[i] == ' ' && line[i+1]!=NULL)count++;
    }
    count++;
    return count;
}

void createSommets(std::string line, vector<Point2D<int>> *Sommets){
    int nbwords = getNbwords(line); //Nombre de sommets de la parcelle
    std::cout << "Nb mots " << nbwords << std::endl;
    std::istringstream coord(line);
    char a, b, c;
    int x, y;
    
    for (int i=0; i<nbwords; i++){
        coord >> a >> x >> b >> y >> c; //Extraction des coordonnées x et y dans les variables x et y; a=[ b=; et c=]
        Point2D<int> pt(x, y);
        Sommets->push_back(pt);
    }
}

int main(int argc, char const *argv[]) {
    //test_creationPoint();
    //test_creationPolygone();
    //test_calculSurface();
    //testZU();
    //testZA();
    //testZAU();
    std::ifstream file(argv[1], std::ios::binary);
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
            vector<Point2D<int>> Sommets;

            std::getline(file, line);
            createSommets(line, &Sommets);
            Polygone<int> Poly(Sommets);
            ZA<int> ZoneA(numero, proprietaire, typeCulture, Poly);
            std::cout << ZoneA;
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
            ZU<int> ZoneU(numero, proprietaire, pConstructible, surfaceConstruite, Poly);
            std::cout << ZoneU;
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
            ZAU<int> ZoneAU(numero, proprietaire, pConstructible, Poly);
            std::cout << ZoneAU;
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
            ZN<int> ZoneN(numero, proprietaire, Poly);
            std::cout << ZoneN;
        }
    }
    return 0;
}





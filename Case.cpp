 /* 
 * File:   Case.cpp
 * Author: Bienvenue
 * 
 * Created on 30 novembre 2015, 23:19
 */

#include "Case.h"
#include <iostream>

using namespace std;

Case::Case(char c, int pion, int m, int max, int lien): symbole(c), nombrepions(pion), jouer(m), numerocase(nbrecases), nombrepionsmax(max), liencase(lien) {
    nbrecases++;
}

Case::Case(const Case& orig) {
}

Case::~Case() {
    cout << "destruction d'une case" << endl;
}

int Case::getNombrePions(){
    return nombrepions;
}

int Case::getNombrePionsMax(){
    return nombrepionsmax;
}

void Case::setNombrePions(int i){
    nombrepions = i;
}

int Case::getJouer(){
    return jouer;
}

int Case::getNumeroCase(){
    return numerocase;
}

int Case::getLienCase(){
    return liencase;
}

char Case::getSymbole(){
    return symbole;
}

bool Case::caseEstLibre(){
    return nombrepions<nombrepionsmax;
}

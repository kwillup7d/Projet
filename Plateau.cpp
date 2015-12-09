/* 
 * File:   Plateau.cpp
 * Author: Bienvenue
 * 
 * Created on 30 novembre 2015, 23:50
 */

#include "Plateau.h"

Plateau::Plateau(int n) : nombrecases(n), cases(new Case*[n]){
    for(int i=0; i<n; i++){
        Case c();
        cases[i] = &c;
    }
}

Plateau::~Plateau() {
    delete [] cases;
}

int Plateau::getNombreCases(){
    return nombrecases;
}

Case* Plateau::getCase(int i){
    return cases[i-1];
}

int Plateau::lancerDe(){
    return 6; //random
}

bool Plateau::caseLibre(Case* c){
    if(c->getNombrePions()>0){
        return false;
    }
    else return true;
}

bool Plateau::estEnFin(Case* c){
    return c==cases[nombrecases];
}

Case* Plateau::avancerPion(Case* c, int lancer){
    if(!(caseLibre(c+lancer))){
        return cases[0];
    }
    else{
        Case* tmp = cases[0];
        if(c+lancer - cases > nombrecases){ //à vérifier
            tmp = cases[nombrecases-1 -( c + lancer - cases - nombrecases)];
        }
        else{
            tmp = c+lancer;
        }
        if((tmp)->goTo()!=0){
            if(!(caseLibre(tmp+(tmp)->goTo()))){
                return cases[0];
            }
            else return tmp+(tmp)->goTo();
        }
    }
}




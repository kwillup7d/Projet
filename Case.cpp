 /* 
 * File:   Case.cpp
 * Author: Bienvenue
 * 
 * Created on 30 novembre 2015, 23:19
 */

#include "Case.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Case::Case(int pion, int m, int max): nombrepions(pion), jouer(m), numerocase(nbrecases), nombrepionsmax(max) {
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

void Case::setNombrePions(int i){
    nombrepions = i;
}

int Case::getJouer(){
    return jouer;
}

int Case::getNumeroCase(){
    return numerocase;
}

int Case::getNombrePionsMax(){
    return nombrepionsmax;
}

bool Case::caseEstLibre(){
    return nombrepions<nombrepionsmax;
}

int Case::goTo(){
    cout << "goto" << endl;
    return 0;
}

int Case::question(){
    srand (time(NULL));
    int a = 2;//rand() % 1000;
    int b = 7; //rand () % 1000;
    int c = rand() % 4;
    
    switch(c){
        case 0 : cout << "Quel est le résultat de " << a << "+" << b << endl;
        return a+b;
        case 1 : cout << "Quel est le résultat de " << a << "*" << b << endl;
        return a*b;
        case 2 : cout << "Quel est le résultat de " << a << "/" << b << endl;
        return a/b;
        case 3 : cout << "Quel est le résultat de " << a << "%" << b << endl;
        return a%b;
    }
}

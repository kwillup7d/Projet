/* 
 * File:   Humain.cpp
 * Author: Bienvenue
 * 
 * Created on 30 novembre 2015, 23:34
 */

#include "Humain.h"
#include <iostream>

using namespace std;

Humain::Humain(int n) : Joueur(n) {
}

Humain::Humain(const Humain& orig) {
}

Humain::~Humain() {
}

int Humain::choixPions(){
    int choix = 1;
    if(nombrepions == 1){
        return choix;
    }
    else{
        cout << "Avec quel pion voulez-vous jouer ? " << endl;
        cin >> choix;
        return choix;
    }
}

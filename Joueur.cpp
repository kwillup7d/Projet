/* 
 * File:   Joueur.cpp
 * Author: Bienvenue
 * 
 * Created on 30 novembre 2015, 23:19
 */

#include "Joueur.h"

Joueur::Joueur(int n): nombrepions(n), score(0), pions(new int[n]), jouer(0), numerojoueur(++numerojoueur) {
    for(int i=0;i<n;i++){
        pions[i]=i+1;
    }
}

Joueur::Joueur(const Joueur& orig) {
}

Joueur::~Joueur() {
    delete [] pions;
}

int Joueur::getNombrePions(){
    return nombrepions;
}

int Joueur::getScore(){
    return score;
}

bool Joueur::getJouer(){
    return jouer;
}

void Joueur::setJouer(int x){
    jouer = x;
}

int Joueur::getPion(int i){
    return pions[i];
}

int Joueur::getNumeroJoueur(){
    return numerojoueur;
}

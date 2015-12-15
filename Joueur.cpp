/* 
 * File:   Joueur.cpp
 * Author: Bienvenue
 * 
 * Created on 30 novembre 2015, 23:19
 */

#include "Joueur.h"
#include <iostream>

using namespace std;

Joueur::Joueur(Plateau* pla,int n): nombrepions(n), score(0), pions(new int[n]), jouer(0), plateau(pla) {
    for(int i=0;i<n;i++){
        pions[i]=i+1;
    }
    cout << "creation joueur" << endl;
}

Joueur::~Joueur() {
    delete [] pions;
    cout << "destruction du joueur" << endl;
}

int Joueur::getNombrePions(){
    return nombrepions;
}

int Joueur::getScore(){
    return score;
}

int Joueur::getJouer(){
    return jouer;
}

void Joueur::setJouer(int x){
    jouer = x;
}

int Joueur::getPion(int i){
    return pions[i];
}

Case* Joueur::avancerPion(Case* c, int lancer){
    Case* tmp = plateau->getCase(0);
    int numtmp = c->getNumeroCase() + lancer;
    
    if(numtmp > plateau->getNombreCases() - 1){ //Si on dépasse le nombre de cases autorisées, on recule 
        numtmp = 2*(plateau->getNombreCases() -1) - (c->getNumeroCase() + lancer);
    }
    
    if((plateau->getCase(numtmp)->caseEstLibre())){// On vérifie si la case est libre, si elle ne l'est pas, on retourne au départ
        tmp = plateau->getCase(numtmp);
                
        if(tmp->goTo()>0){// Si on peut se téléporter, on se téléporte //Si la case liée n'est pas libre, retour case départ
            if(plateau->getCase(tmp->goTo())->caseEstLibre()){
                tmp = plateau->getCase(tmp->goTo()); // Sinon on y va
            }
            else {
                tmp = plateau->getCase(0); //Sinon on retourne au départ
            }
        }
        
    }
    jouer = jouer - 1 + tmp->getJouer();
    return tmp;
}

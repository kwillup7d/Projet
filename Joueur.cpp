/* 
 * File:   Joueur.cpp
 * Author: Bienvenue
 * 
 * Created on 30 novembre 2015, 23:19
 */

#include "Joueur.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Joueur::Joueur(Plateau* pla,int n): nombrepions(n), score(0), jouer(0), plateau(pla) {
    cout << "creation joueur" << endl;
}

Joueur::~Joueur() {
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

int Joueur::choixDeplacement(){
    srand (time(NULL));
    return (rand()%6 + 1);
}

Case* Joueur::avancerPion(Case* c, int lancer){
    Case* tmp = plateau->getCase(0);
    int numtmp = c->getNumeroCase() + lancer;
    
    //Si on dépasse le nombre de cases autorisées, on recule
    if(numtmp > plateau->getNombreCases() - 1){  
        numtmp = 2*(plateau->getNombreCases() -1) - (c->getNumeroCase() + lancer);
    }
    
    // On vérifie si la case est libre, si elle ne l'est pas, on retourne au départ
    if((plateau->getCase(numtmp)->caseEstLibre())){
        tmp = plateau->getCase(numtmp);
        
        // Si on peut se téléporter, on se téléporte 
        if(tmp->getLienCase()>0){
            if(plateau->getCase(tmp->getLienCase())->caseEstLibre()){
                tmp = plateau->getCase(tmp->getLienCase());
            }
            else {
                //Si la case liée n'est pas libre, retour case départ
                tmp = plateau->getCase(0); 
            }
        }
        
    }
    //on enleve 1 car le joueur a fait son tour et on regarde si la case lui demande de rejouer ou de passer son tour
    jouer = jouer - 1 + tmp->getJouer();
    return tmp;
}

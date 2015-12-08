/* 
 * File:   Jeu.cpp
 * Author: Bienvenue
 * 
 * Created on 7 décembre 2015, 17:48
 */

#include "Jeu.h"
#include "Humain.h"
#include "Robot.h"

Jeu::Jeu(int cases, int joueurs, int robots, int pions) : plateau(cases), joueur(new Joueur[joueurs]){
    for(int i=0;i<joueurs-robots;i++){
        joueur[i] = new Humain(pions);
    }
    for(int i=joueurs-robots; i<joueurs; i++){
        joueur[i] = new Robot(pions);
    }
    for(int i=0;i<joueurs;i++){
        for(int j=0; j<pions;j++){
            placementpions.insert(pair<pair<int,int>, Case*>((joueur[i].getNumeroJoueur(),j+1),plateau.getCase(1)));
        }
    }
}

Jeu::Jeu(const Jeu& orig) {
}

Jeu::~Jeu() {
}


/* 
 * File:   Jeu.cpp
 * Author: Bienvenue
 * 
 * Created on 7 décembre 2015, 17:48
 */

#include "Jeu.h"
#include "Humain.h"
#include "Robot.h"
#include <iostream>

Jeu::Jeu(int cases) : plateau(cases), Tabjoueur(nullptr){
}

Jeu::Jeu(const Jeu& orig) {
}

Jeu::~Jeu() {
}

void Jeu::initialisation(){
    int joueurs = 1;
    do{
        cout << "Combien de joueurs voulez-vous ? (entre 1 et 4 joueurs" << endl;
        cin >> joueurs;
    }
    while(joueurs<1 || joueurs >4);
    
    int robots = 1;
    do{
        cout << "Combien de robots voulez-vous ? (au plus " << joueurs << ")" << endl;
        cin >> robots;
    }
    while(robots<0 || robots > joueurs);
    
    int pions = 1;
    do{
        cout << "Combien de pions voulez-vous par joueur ?" << endl;
        cin >> pions;
    }
    while(pions<1);
    
    Tabjoueur = new Joueur[joueurs];
    
    for(int i=0;i<joueurs-robots;i++){
        Tabjoueur[i] = new Humain(pions);
    }
    for(int i=joueurs-robots; i<joueurs; i++){
        Tabjoueur[i] = new Robot(pions);
    }
    for(int i=0;i<joueurs;i++){
        for(int j=0; j<pions;j++){
            placementpions.insert(pair<pair<int,int>, Case*>((Tabjoueur[i].getNumeroJoueur(),j+1),plateau.getCase(1)));
        }
    }
    
}

void Jeu::joueurAGagne(Joueur* j){
    
}

void Jeu::jouer(){
    
}


/* 
 * File:   Jeu.cpp
 * Author: Bienvenue
 * 
 * Created on 7 décembre 2015, 17:48
 */

#include "Jeu.h"
#include <iostream>

Jeu::Jeu(int cases) : plateau(cases), Tabjoueur(new list<Joueur*>){
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
    
    for(int i=0;i<joueurs-robots;i++){
        Humain h = new Humain(pions);
        Tabjoueur.push_back(&h);
    }
    for(int i=joueurs-robots; i<joueurs; i++){
        Robot r(pions);
        Tabjoueur.push_back(&r);
    }
    for(list<Joueur*>::iterator it=Tabjoueur.begin();it!=Tabjoueur.end();it++){
        for(int j=0; j<pions;j++){
            placementpions.insert(pair<pair<int,int>, Case*>(((*it)->getNumeroJoueur(),j+1),plateau.getCase(1)));
        }
    }
    
}

bool Jeu::joueurAGagne(Joueur* j){
    bool b = true;
    int i = 1;
    while(i<j->getNombrePions()+1 && b){
        b = plateau.estEnFin(placementpions.find((j->getNumeroJoueur(),i))->second);
        i++;
    }
    return b;
}

void Jeu::tourJoueur(Joueur* j){
    j->setJouer(j->getJouer()+1);
    while(j->getJouer()>0 && !joueurAGagne(j)){
        int choix = j->choixPions();
        int lancer = plateau.lancerDe();
        while(choix<1 || choix>j->getNombrePions()){
            choix = j->choixPions();
        }
        Case* tmp = plateau.avancerPion(placementpions.find((j->getNumeroJoueur(),choix))->second, lancer);
        placementpions.erase(placementpions.find((j->getNumeroJoueur(),choix)));
        placementpions.insert(make_pair((j->getNumeroJoueur(),choix),tmp));
        j->setJouer(j->getJouer() - 1 + tmp->getJouer());
    }
}

void Jeu::jouer(){
    bool jeufini = false;
    while(!jeufini){
        list<Joueur*>::iterator it = Tabjoueur.begin();
        while(it!=Tabjoueur.end() && !jeufini){
            tourJoueur(*it);
            if(tourJoueur(*it)){
                jeufini = true;
            }
            it++;
        }
    }
}


/* 
 * File:   Jeu.cpp
 * Author: Bienvenue
 * 
 * Created on 7 décembre 2015, 17:48
 */

#include "Jeu.h"
#include "Humain.h"
#include "Robot.h"
#include "HumainQuestion.h"
#include "RobotQuestion.h"
#include <iostream>

Jeu::Jeu(int cases) : plateau(cases){
}

Jeu::~Jeu() {
    cout << "destruction du jeu" << endl;
    for(list<Joueur*>::iterator it=Tabjoueur.begin();it!=Tabjoueur.end();it++){
        delete *it;
    }
    Tabjoueur.clear();
}

void Jeu::initialisation(){
    int joueurs = 1;
    do{
        cout << "Combien de joueurs voulez-vous ? (entre 1 et 4 joueurs)" << endl;
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
    
    Joueur* j;
    
    for(int i=0;i<joueurs-robots;i++){
        j = new HumainQuestion(&plateau,pions);
        Tabjoueur.push_back(j);
    }
    
    for(int i=joueurs-robots; i<joueurs; i++){
        j = new RobotQuestion(&plateau,pions);
        Tabjoueur.push_back(j);
    }
    
    pair<Joueur*,int> tmp;
    
    for(list<Joueur*>::iterator it=Tabjoueur.begin();it!=Tabjoueur.end();it++){
        for(int j=1; j<pions+1;j++){
            tmp = make_pair(*it,j);
            placementpions.insert(pair<pair<Joueur*,int>, Case*>(tmp,plateau.getCase(0)));
        }
    }
    
}

bool Jeu::joueurAGagne(Joueur* j){
    bool b = true;
    int i = 1;
    pair<Joueur*,int> tmp;
    while((i<(j->getNombrePions())+1) && b){
        tmp = make_pair(j,i);
        b = plateau.estEnFin(placementpions.find(tmp)->second);
        i++;
    }
    return b;
}

void Jeu::tourJoueur(Joueur* j){
    pair<Joueur*,int> pairetmp;
    cout << "debut tour" << endl;
    Case* ct;
    Case* tmp;
    j->setJouer(j->getJouer()+1);
    while((j->getJouer())>0 && !joueurAGagne(j)){
        int choix = j->choixPions();
        pairetmp = make_pair(j,choix);
        while(choix<0 || choix>j->getNombrePions() || plateau.estEnFin(placementpions.find(pairetmp)->second)){
            choix = j->choixPions();
            pairetmp = make_pair(j,choix); //problème avec 0
        }
        int lancer = plateau.lancerDe();
        while(choix<1 || choix>j->getNombrePions() || plateau.estEnFin(placementpions.find(pairetmp)->second)){
            choix = j->choixPions();
            pairetmp = make_pair(j,choix);
        }

        ct = placementpions.find(pairetmp)->second;
        tmp = j->avancerPion(ct, lancer);
        placementpions.find(pairetmp)->second->setNombrePions(placementpions.find(pairetmp)->second->getNombrePions()-1);
        placementpions.erase(placementpions.find(pairetmp));
        placementpions.insert(make_pair(pairetmp,tmp));
        tmp->setNombrePions(tmp->getNombrePions()+1);
        cout << "le pion est à la case " << tmp->getNumeroCase() << endl;
    }
}

void Jeu::jouer(){
    cout << "début du jeu" << endl;
    bool jeufini = false;
    list<Joueur*>::iterator it;
    while(!jeufini){
        it = Tabjoueur.begin();
        while(it!=Tabjoueur.end() && !jeufini){
            tourJoueur(*it);
            if(joueurAGagne(*it)){
                cout << "Un joueur a gagné" << endl;
                jeufini = true;
            }
            it++;
        }
    }
}


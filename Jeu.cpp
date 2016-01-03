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
#include "HumainCartagena.h"
#include "RobotCartagena.h"
#include <iostream>
#include <string>

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
    string joueur;
    char s(72);

    for(int i=0;i<joueurs-robots;i++){
        cout << "Quel style de joueur voulez-vous ? (normal, question, cartagena)" << endl;
        cin >> joueur;
        s++;
        if(joueur == "normal"){
            j = new Humain(&plateau,pions,s);
        }
        else if(joueur == "question"){
            j = new HumainQuestion(&plateau,pions,s);
        }
        else {
            j = new HumainCartagena(&plateau, 8, pions,s);
        }
        cout << "Caractère joueur :" << s << endl;
        Tabjoueur.push_back(j);
    }

    for(int i=joueurs-robots; i<joueurs; i++){
        cout << "Quel style de joueur voulez-vous ? (normal, question, cartagena)" << endl;
        cin >> joueur;
        ++s;
        if(joueur == "normal"){
            j = new Robot(&plateau,pions,s);
        }
        else if(joueur == "question"){
            j = new RobotQuestion(&plateau,pions,s);
        }
        else {
            j = new RobotCartagena(&plateau,8,pions,s);
        }
        cout << "Caractère joueur :" << s << endl;
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
    //on regarde si tous les pions du joueur sont en fin
    while((i<(j->getNombrePions())+1) && b){
        tmp = make_pair(j,i);
        //si un pion n'est pas en fin, alors b = false et on sort de la boucle : le joueur n'a pas gagné
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
    //on rajoute un au compteur de jouer du joueur
    j->setJouer(j->getJouer()+1);
    //s'il peut jouer et qu'il n'a pas gagné, on lance son tour
    while((j->getJouer())>0 && !joueurAGagne(j)){
        int choix = j->choixPions();
        pairetmp = make_pair(j,choix);
        //Le joueur fait son choix de pions et on vérifie que c'est vraiment un pion et qu'il n'est pas en fin
        //Ici, le joueur peut choisir 0 s'il veut choisir après le lancer de dé
        while(choix<0 || choix>j->getNombrePions() || (choix!=0 && plateau.estEnFin(placementpions.find(pairetmp)->second))){
            choix = j->choixPions();
            pairetmp = make_pair(j,choix);
        }
        int lancer = j->choixDeplacement();
        cout << "le lancer vaut " << lancer << endl;
        //Si le joueur n'a toujours pas fait son choix, on lui redemande de choisir
        while(choix<1 || choix>j->getNombrePions() || plateau.estEnFin(placementpions.find(pairetmp)->second)){
            choix = j->choixPions();
            pairetmp = make_pair(j,choix);
        }

        ct = placementpions.find(pairetmp)->second;
        //une fois la case du pions trouvée, on fait avancer le pion
        tmp = j->avancerPion(ct, lancer);
        //on enlève un pion à l'ancienne case
        ct->setNombrePions(ct->getNombrePions()-1);
        //on supprime le lien entre pion et case pour créer le nouveau lien
        placementpions.erase(placementpions.find(pairetmp));
        placementpions.insert(make_pair(pairetmp,tmp));
        //on rajoute un pion à la nouvelle case
        tmp->setNombrePions(tmp->getNombrePions()+1);
        cout << "le pion est à la case " << tmp->getNumeroCase() << endl;
        cout << "peut-il rejouer ? " << j->getJouer() << endl;

        string k;
        afficher();
        cin >> k;
        cout << k << endl;
    }
}

void Jeu::jouer(){
    cout << "début du jeu" << endl;
    bool jeufini = false;
    list<Joueur*>::iterator it;
    //tant que le jeu n'est pas fini, on recommence avec le premier joueur
    while(!jeufini){
        it = Tabjoueur.begin();
        //tant que le jeu n'est pas fini, chaque joueur effectue son tour
        while(it!=Tabjoueur.end() && !jeufini){
            tourJoueur(*it);
            //si le joueur courant a gagné, le jeu est fini
            if(joueurAGagne(*it)){
                cout << "Un joueur a gagné" << endl;
                jeufini = true;
            }
            it++;
        }
    }
}


void Jeu::afficher(){

    pair<Joueur*,int> pairtmp;

    for (int i=0; i<plateau.getNombreCases();i++){

        cout << i << " | " << plateau.getCase(i)->getSymbole() << " | ";


            list<Joueur*>::iterator it;
            it = Tabjoueur.begin();

            while ( it!=Tabjoueur.end()){
                    for (int k=0; k<((*it)->getNombrePions()+1); k++){
                pairtmp = make_pair(*it,k);
                if ((placementpions.find(pairtmp)->second)->getNumeroCase() == i ){
                    cout <<(*it)->getSymbole()<< k << " | ";
                    }
 }
                    it++;





        }

    cout << endl;

    }




}


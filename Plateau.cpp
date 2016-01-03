/*
 * File:   Plateau.cpp
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:50
 */

#include "Plateau.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Plateau::Plateau(int n) : nombrecases(n), cases(new Case*[n]){
    Case* c;
    srand (time(NULL));
    int aleatoire=0;
    char car;

    cases[0] = new Case('a',0,0,100,0);
    for(int i=1; i<n-1; i++){
        aleatoire = rand()%4;
        switch(aleatoire){
            case 0 : {
                car = 'a';
                break;
            }
            case 1 : {
                car = 'b';
                break;
            }
            case 2 : {
                car = 'c';
                break;
            }
            case 3: {
                car = 'd';
             break;
            }
        }

        if(i%9 == 0){
            //création des cases 'passer son tour'
           c = new Case(car,0,-1,1,0);
        }
        else if(i%13 == 0)
        {
            //création des cases 'rejouer'
            c = new Case(car,0,1,1,0);
        }
        else if(i%19 == 0){
            //creation des cases 'serpent' qui envoie le pion sur une case entre 1 et i-6
            aleatoire = 1 + rand()%(i-7);
            c = new Case(car,0,0,1,aleatoire);
        }
        else if(i%17 == 0){
            //creation des cases 'echelle' qui envoie le pion sur une case entre i+7 et nombrecases-2
            aleatoire = i + 7 + rand()%(nombrecases-9-i);
            c = new Case(car,0,0,1,aleatoire);
        }
        else {
            c = new Case(car);
        }
        cases[i] = c;
    }
    cases[n-1] = new Case('a',0,0,100,0);
    cout << "création du tableau" << endl;
}

Plateau::~Plateau() {
    delete [] cases;
    cout << "destruction plateau" << endl;
}

int Plateau::getNombreCases(){
    return nombrecases;
}

Case* Plateau::getCase(int i){
    return cases[i];
}

void Plateau::setCase(int i, Case* c){
    cases[i] = c;
}

bool Plateau::estEnFin(Case* c){
    //on regarde si la case c est bien la dernière case
    return c->getNumeroCase()==nombrecases-1; // On vérifie si la case est bien la dernière du plateau.
}



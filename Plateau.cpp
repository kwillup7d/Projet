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
    for(int i=0; i<n; i++){
        if(i%9 == 0){
           c = new Case(0,-1,1);
        }
        else if(i%13 == 0)
        {
            c = new Case(0,1,1);
        }
        else {
            c = new Case();
        }
        cases[i] = c;
    }
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

int Plateau::lancerDe(){
    srand (time(NULL));
    return (rand()%6 + 1);
}

bool Plateau::estEnFin(Case* c){
    return c->getNumeroCase()==nombrecases-1; // On vérifie si la case est bien la dernière du plateau.
}

/*Case* Plateau::avancerPion(Case* c, int lancer){
    cout << "bouh " << endl;
    Case* tmp = cases[0];
    int numtmp = c->getNumeroCase() + lancer;
    cout << c->getNumeroCase() << " c'est le plateau" << endl;
    
    if(numtmp > nombrecases - 1){ //Si on dépasse le nombre de cases autorisées, on recule 
        cout << "bah" << endl;//à vérifier
        numtmp = 2*(nombrecases -1) - (c->getNumeroCase() + lancer);
        cout << "bah " << numtmp << endl;
    }
    
    if(!(cases[numtmp]->caseEstLibre())){ // On vérifie si la case est libre, si elle ne l'est pas, on retourne au départ
        return tmp;
    }
    else{
        cout << "bih" << endl;
        tmp = cases[numtmp];
        cout << tmp->goTo() << endl;
        
        if(tmp->goTo()>0){ // Si on peut se téléporter, on se téléporte
            if(!(tmp+(tmp->goTo()))->caseEstLibre()){ //Si la case liée n'est pas libre, retour case départ
                return cases[0];
            }
            else {
                tmp = cases[tmp->getNumeroCase() + tmp->goTo()]; // Sinon on y va
                return tmp;
            }
        }
        else {
            cout << "boh" << endl;
            return tmp; // Sinon on va juste à la case demandée 
        }
    }
}
*/



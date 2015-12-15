/* 
 * File:   JoueurQuestion.cpp
 * Author: Bienvenue
 * 
 * Created on 14 décembre 2015, 09:34
 */

#include "JoueurQuestion.h"
#include <iostream>

using namespace std;

JoueurQuestion::JoueurQuestion(Plateau* plateau, int pions): Joueur(plateau, pions) {
    cout << "creation joueurquestion" << endl;
}

JoueurQuestion::~JoueurQuestion() {
    cout << "destruction joueurquestion" << endl;
}

Case* JoueurQuestion::avancerPion(Case* c, int lancer){
    Case* tmp = plateau->getCase(0);
    int numtmp = c->getNumeroCase() + lancer;
    
    if(numtmp > plateau->getNombreCases() - 1){ //Si on dépasse le nombre de cases autorisées, on recule 
        numtmp = 2*(plateau->getNombreCases() -1) - (c->getNumeroCase() + lancer);
    }
    
    if((plateau->getCase(numtmp)->caseEstLibre())){// On vérifie si la case est libre, si elle ne l'est pas, on retourne au départ
        tmp = plateau->getCase(numtmp);
        
        int question = tmp->question();
        
        if(reponse() == question){
            if(tmp->goTo() > tmp->getNumeroCase()){// Si on peut se téléporter, on se téléporte //Si la case liée n'est pas libre, retour case départ
                if(plateau->getCase(tmp->goTo())->caseEstLibre()){
                    tmp = plateau->getCase(tmp->goTo()); // Sinon on y va
                }
                else {
                    tmp = plateau->getCase(0);
                }
            }
        }
        else {
            if(tmp->goTo() < tmp->getNumeroCase() && plateau->getCase(tmp->goTo())->caseEstLibre()){
                tmp = plateau->getCase(tmp->goTo()); // Sinon on y va
            }
            else {
                tmp = c;
            }
        }
    }
    jouer = jouer - 1 + tmp->getJouer();
    return tmp;
}


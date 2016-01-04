/*
 * File:   JoueurQuestion.cpp
 * Author: Bienvenue
 *
 * Created on 14 décembre 2015, 09:34
 */

#include "JoueurQuestion.h"
#include <iostream>

using namespace std;

JoueurQuestion::JoueurQuestion(Plateau* plateau, int pions, char s): Joueur(plateau, pions, s) {
    cout << "creation joueurquestion" << endl;
}

JoueurQuestion::~JoueurQuestion() {
    cout << "destruction joueurquestion" << endl;
}

Case* JoueurQuestion::avancerPion(Case* c, int lancer){
    Case* tmp = plateau->getCase(0);
    int numtmp = c->getNumeroCase() + lancer;

    //Si on dépasse le nombre de cases autorisées, on recule
    if(numtmp > plateau->getNombreCases() - 1){
        numtmp = 2*(plateau->getNombreCases() -1) - (c->getNumeroCase() + lancer);
    }

    // On vérifie si la case est libre, si elle ne l'est pas, on retourne au départ
    if((plateau->getCase(numtmp)->caseEstLibre())){
        //si elle est libre, on va à la case demandée

        tmp = plateau->getCase(numtmp);

        //on vérifie si le joueur a bon à la question
        if(question()){
            //si on est sur une case 'échelle' on est transféré
            if(numtmp - tmp->getLienCase() > 0){
                //si la case n'est pas libre, on retourne au départ
                if(plateau->getCase(tmp->getLienCase())->caseEstLibre()){
                    tmp = plateau->getCase(tmp->getLienCase());
                }
                else {
                    cout << "La case n'est pas libre. Dommaaaage..."<< endl;
                    tmp = plateau->getCase(0);
                }
            }
        }
        //si le joueur a tort
        else {
            //si le joueur est sur une case 'serpent', qui ne peut pas être la case départ, on descend
            if(tmp->getLienCase() < tmp->getNumeroCase() && tmp->getLienCase()>0){
                //si la case n'est pas libre, on retourne au départ
                if(plateau->getCase(tmp->getLienCase())->caseEstLibre()){
                    tmp = plateau->getCase(tmp->getLienCase());
                }
                else {
                    cout << "La case n'est pas libre. Dommaaaage..."<< endl;
                    tmp = plateau->getCase(0);
                }
            }
            else {
                //sinon, on retourne à la case initiale
                tmp = c;

            }
    }
    }else{
        tmp = plateau->getCase(0);
    }

    jouer = jouer - 1 + tmp->getJouer();
    return tmp;

}


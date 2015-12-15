/* 
 * File:   HumainQuestion.cpp
 * Author: Bienvenue
 * 
 * Created on 14 décembre 2015, 09:52
 */

#include "HumainQuestion.h"
#include <iostream>

using namespace std;

HumainQuestion::HumainQuestion(Plateau* plateau, int pions) : JoueurQuestion(plateau, pions) {
    cout << "creation humain question" << endl;
}

HumainQuestion::~HumainQuestion() {
    cout << "destruction humainquestion" << endl;
}

int HumainQuestion::reponse(){
    int reponse;
    cin>> reponse;
    return reponse;
}

int HumainQuestion::choixPions(){
    int choix = 1;
    if(nombrepions == 1){
        return choix;
    }
    else{
        cout << "Avec quel pion voulez-vous jouer ? " << endl;
        cin >> choix;
        return choix;
    }
}


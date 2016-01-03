/*
 * File:   HumainQuestion.cpp
 * Author: Bienvenue
 *
 * Created on 14 décembre 2015, 09:52
 */

#include "HumainQuestion.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

HumainQuestion::HumainQuestion(Plateau* plateau, int pions, char s) : JoueurQuestion(plateau, pions, s) {
    cout << "creation humain question" << endl;
}

HumainQuestion::~HumainQuestion() {
    cout << "destruction humainquestion" << endl;
}

bool HumainQuestion::question(){
    srand (time(NULL));
    int a = rand() % 10;
    int b = 1 + rand() % 10;
    int c = rand() % 4;
    int result, reponse;

    switch(c){
        case 0 : {
            cout << "Quel est le résultat de bih " << a << "+" << b << endl;
            result = a+b;
            break;
        }
        case 1 : {
            cout << "Quel est le résultat de bah " << a << "*" << b << endl;
            result = a*b;
            break;
        }
        case 2 : {
            cout << "Quel est le résultat de boh " << a << "/" << b << endl;

            result = a/b;
            break;
        }
        case 3 : {
            cout << "Quel est le résultat de buh " << a << "%" << b << endl;
            result = a%b;
            break;
        }
    }
    cin >> reponse;
    return reponse==result;
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


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
    bool k;

    switch(c){
        case 0 : {
            cout << "Quel est le résultat de " << a << "+" << b << " ?" << endl;
            k = reponse(a+b);
            break;
        }
        case 1 : {
            cout << "Quel est le résultat de " << a << "*" << b << " ?"<< endl;
            k = reponse(a*b);
            break;
        }
        case 2 : {
            cout << "Quel est le résultat de " << a << "/" << b << " au centieme pres ?" << endl;

            float d = (float) a;
            k = reponse(d/b);
            break;
        }
        case 3 : {
            cout << "Quel est le résultat de " << a << "%" << b << " ?"<< endl;
            k = reponse(a%b);
            break;
        }
    }

    return k;
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

bool HumainQuestion::reponse ( int i ){
    int reponse;
    cin >> reponse;
    return (reponse == i);
}

bool HumainQuestion::reponse( float i){
    float reponse;
    cin >> reponse;
    return ( max(reponse,i)-min(reponse,i) < 0.02 );

}

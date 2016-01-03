/*
 * File:   HumainCartagena.cpp
 * Author: Bienvenue
 *
 * Created on 15 décembre 2015, 21:12
 */

#include "HumainCartagena.h"
#include <iostream>

using namespace std;

HumainCartagena::HumainCartagena(Plateau* plateau, int nombrecartes, int pions, char s) : JoueurCartagena(plateau, nombrecartes, pions, s) {
    cout << "creation humaincartagena" << endl;
}

HumainCartagena::~HumainCartagena() {
    cout << "destruction humaincartagena" << endl;
}

int HumainCartagena::choixPions(){
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

int HumainCartagena::choixDeplacement(){
    char car;
    char pioche = 'p';
    int choix;
    string tmp;
    cout << "nombre de a " << cartes.find('a')->second << endl;
    cout << "nombre de b " << cartes.find('b')->second << endl;
    cout << "nombre de c " << cartes.find('c')->second << endl;
    cout << "nombre de d " << cartes.find('d')->second << endl;


    cout << "Quel symbole choisissez-vous ? (a,b,c,d,p)" << endl;
    cin >> car;
    while (car!=pioche && (cartes.find(car)->second) == 0){
        cout << "Quel symbole choisissez-vous ? (a,b,c,d,p)" << endl;
        cin >> tmp;
        cout << tmp << endl;
        car = tmp[0];
        cout << car << endl;
    }
    choix = (int)car;
    return choix;
}


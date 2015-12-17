/* 
 * File:   JoueurCartagena.cpp
 * Author: Bienvenue
 * 
 * Created on 15 décembre 2015, 20:27
 */

#include "JoueurCartagena.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

JoueurCartagena::JoueurCartagena(Plateau* plateau, int nombrecartes, int pions) : Joueur(plateau,pions){
    srand(time(NULL));
    int aleatoire;
    
    cartes.insert(pair<char,int>('a',0));
    cartes.insert(pair<char,int>('b',0));
    cartes.insert(pair<char,int>('c',0));
    cartes.insert(pair<char,int>('d',0));
    
    int cartesrestantes = nombrecartes;
    while(cartesrestantes>0){
        aleatoire = rand()%4;
        switch(aleatoire){
            case 0 : {
                cartes.find('a')->second = cartes.find('a')->second +1;
                break;
            }
            case 1 : {
                cartes.find('b')->second = cartes.find('b')->second +1;
                break;
            }
            case 2 : {
                cartes.find('c')->second = cartes.find('c')->second +1;
                break;
            }
            case 3 : {
                cartes.find('d')->second = cartes.find('d')->second +1;
                break;
            }
        }
        cartesrestantes--;
    }
    cout << "creation joueurcartagena" << endl;
    cout << "nombre de a " << cartes.find('a')->second << endl;
}

JoueurCartagena::~JoueurCartagena() {
    cout << "destruction joueurcartagena" << endl;
}

void JoueurCartagena::rajouterUneCarte(){
    int aleatoire;
    aleatoire = rand()%4;
        switch(aleatoire){
            case 0 : {
                cartes.find('a')->second = cartes.find('a')->second +1;
                break;
            }
            case 1 : {
                cartes.find('b')->second = cartes.find('b')->second +1;
                break;
            }
            case 2 : {
                cartes.find('c')->second = cartes.find('c')->second +1;
                break;
            }
            case 3 : {
                cartes.find('d')->second = cartes.find('d')->second +1;
                break;
            }
        }
}

Case* JoueurCartagena::avancerPion(Case* c, int symbole){
    Case* tmp = plateau->getCase(0);
    int numcase = c->getNumeroCase()-1;
    
    if(symbole == 112){
        while(plateau->getCase(numcase)->getNombrePions()<1 || plateau->getCase(numcase)->getNombrePions()>2 || numcase >0){
            numcase--;
        }
        tmp = plateau->getCase(numcase);
        tmp->setNombrePions(tmp->getNombrePions()+1);
        rajouterUneCarte();
        if(tmp->getNombrePions()==2 || tmp->getNumeroCase() ==0){
            rajouterUneCarte();
        }
    }
    else{
        char car = (char)symbole;
        (cartes.find(car)->second)--;
        numcase = c->getNumeroCase()+1;
        int nombrecases = plateau->getNombreCases();
        while(!plateau->getCase(numcase)->caseEstLibre() || car!=plateau->getCase(numcase)->getSymbole()){
            numcase++;
        }
        //if(numcase == nombrecases){
        //tmp = avancerPion(c,0);
        //}
        //else {
            tmp = plateau->getCase(numcase);
            tmp->setNombrePions(tmp->getNombrePions()+1);
        //}
    }
    
    
    jouer = jouer - 1 + tmp->getJouer();
    return tmp;
}


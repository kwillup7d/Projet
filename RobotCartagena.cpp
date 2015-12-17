/* 
 * File:   RobotCartagena.cpp
 * Author: Bienvenue
 * 
 * Created on 15 décembre 2015, 21:17
 */

#include "RobotCartagena.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

RobotCartagena::RobotCartagena(Plateau* plateau, int nombrecartes, int pions) : JoueurCartagena(plateau, nombrecartes, pions){
    cout << "creation Robotcartagena" << endl;
}

RobotCartagena::~RobotCartagena() {
    cout << "destruction robotcartagena" << endl;
}

int RobotCartagena::choixPions(){
    int choix = 1;
    if(nombrepions == 1){
        return choix;
    }
    else{
        srand (time(NULL));
        return (rand()%nombrepions + 1);
    }
}

int RobotCartagena::choixDeplacement(){
    char car;
    int choix;
    int aleatoire;
    
    srand (time(NULL));
    while(car != 'p' || cartes.find(car)->second == 0){
        aleatoire = rand()%5;
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
            case 3 : {
                car = 'd';
                break;
            }
            case 4 : {
                    car = 'p';
                break;           
            }
        }
    }
    choix = (int)car;
    return choix;
}


/*
 * File:   Robot.cpp
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:36
 */

#include "Robot.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

Robot::Robot(Plateau* pla,int n, char s) : Joueur(pla, n, s) {
    cout << "creation d'un robot" << endl;
}

Robot::~Robot() {
    cout << "destruction d'un robot" << endl;
}

int Robot::choixPions(){
    int choix = 1;
    if(nombrepions == 1){
        return choix;
    }
    else{
        srand (time(NULL));
        return (rand()%nombrepions + 1);
    }
}



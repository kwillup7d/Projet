/* 
 * File:   Robot.cpp
 * Author: Bienvenue
 * 
 * Created on 30 novembre 2015, 23:36
 */

#include "Robot.h"

Robot::Robot(int n) : Joueur(n) {
}

Robot::Robot(const Robot& orig) {
}

Robot::~Robot() {
}

int* Robot::choixPions(){
    int choix = 1;
    if(nombrepions == 1){
        return choix;
    }
    else{
        return 2; //random
    }
}

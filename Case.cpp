/* 
 * File:   Case.cpp
 * Author: Bienvenue
 * 
 * Created on 30 novembre 2015, 23:19
 */

#include "Case.h"

Case::Case(int n, int m): nombrepions(n), jouer(m) {
}

Case::Case(const Case& orig) {
}

Case::~Case() {
}

int Case::getNombrePions(){
    return nombrepions;
}

int Case::getJouer(){
    return jouer;
}

int Case::goTo(){
    return 0;
}

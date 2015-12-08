/* 
 * File:   Teleportation.cpp
 * Author: Bienvenue
 * 
 * Created on 1 décembre 2015, 00:15
 */

#include "Teleportation.h"

Teleportation::Teleportation(int n, int m) : Case(n,m) {
}

Teleportation::Teleportation(const Teleportation& orig) {
}

Teleportation::~Teleportation() {
}

int Teleportation::goTo(int min, int max){
    return 6; //random
}

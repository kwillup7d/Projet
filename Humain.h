/*
 * File:   Humain.h
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:34
 */

#ifndef HUMAIN_H
#define	HUMAIN_H
#include "Joueur.h"
#include <string>


using namespace std;

class Humain : public Joueur {
public:
    Humain(Plateau*, int=1, char = 65);
    virtual ~Humain();
    virtual int choixPions();


private:
    string nom;
};

#endif	/* HUMAIN_H */


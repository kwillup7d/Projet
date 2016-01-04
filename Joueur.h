/*
 * File:   Joueur.h
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:19
 */

#ifndef JOUEUR_H
#define	JOUEUR_H
#include "plateau.h"
#include <string>

using namespace std;

class Joueur {
public:
    virtual ~Joueur();
    int getScore();
    int getNombrePions();
    int getJouer();
    void setJouer(int);
    virtual int choixDeplacement();
    virtual Case* avancerPion(Case*, int);
    virtual int choixPions()=0;
    char getSymbole();

protected:
    int jouer;
    int score;
    Plateau* plateau;
    int nombrepions;
    char symbole;
    Joueur(Plateau*,int=1,char=65);

};

#endif	/* JOUEUR_H */


/* 
 * File:   Joueur.h
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:19
 */

#ifndef JOUEUR_H
#define	JOUEUR_H
#include "plateau.h"

class Joueur {
public:
    virtual ~Joueur();
    int getScore();
    int getNombrePions();
    int getJouer();
    int getPion(int);
    void setJouer(int);
    virtual Case* avancerPion(Case*, int);
    virtual int choixPions()=0;
protected:
    int jouer;
    int score;
    int* pions;
    Plateau* plateau;
    int nombrepions;
    Joueur(Plateau*,int=1);
    
};

#endif	/* JOUEUR_H */


/* 
 * File:   Joueur.h
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:19
 */

#ifndef JOUEUR_H
#define	JOUEUR_H

class Joueur {
public:
    Joueur(int);
    Joueur(const Joueur& orig);
    virtual ~Joueur();
    int getScore();
    int getNombrePions();
    int getJouer();
    int getPion(int);
    void setJouer(int);
    int getNumeroJoueur();
protected:
    static int numerojoueur = 0;
    int score;
    int* pions;
    int nombrepions;
    virtual int choixPions()=0;
    int jouer;
};

#endif	/* JOUEUR_H */


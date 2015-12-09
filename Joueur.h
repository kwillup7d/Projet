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
    Joueur(const Joueur& orig);
    virtual ~Joueur();
    int getScore();
    int getNombrePions();
    int getJouer();
    int getPion(int);
    void setJouer(int);
    int getNumeroJoueur();
    virtual int choixPions()=0;
protected:
    int jouer;
    static int numerojoueur = 0;
    int score;
    int* pions;
    int nombrepions;
    Joueur(int=1);
    
};

#endif	/* JOUEUR_H */


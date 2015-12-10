/* 
 * File:   Joueur.h
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:19
 */

#ifndef JOUEUR_H
#define	JOUEUR_H
#include <list>

static int numerojoueur = 0;

enum class StatutPossible { Diamonds, Hearts, Clubs, Spades };


class Joueur {
public:
    Joueur(const Joueur& orig);
    virtual ~Joueur();
    int getScore();
    int getNombrePions();
    StatutPossible getStatut();
    list<Pion *> getPion();
    void setStatut(int);
    int getNumeroJoueur(); // à voir
    virtual int choixPions()=0;
protected:
    StatutPossible statut;  // utiliser une enumeration pour décrire le statut parmi les StatutsPossibles
    
    int score;
    Pions * pions;  // un tableau d'objets Pions
    int nombrepions;
    Joueur(StatutPossible=StatutPossible::Diamonds); //
    
};

#endif	/* JOUEUR_H */


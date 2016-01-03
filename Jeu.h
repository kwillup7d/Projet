/*
 * File:   Jeu.h
 * Author: Bienvenue
 *
 * Created on 11 décembre 2015, 20:02
 */

#ifndef JEU_H
#define	JEU_H
#include <list>
#include <utility>
#include <map>
#include "Joueur.h"
#include "JoueurQuestion.h"
#include "JoueurCartagena.h"
#include "Plateau.h"

using namespace std;

//template <class T>
class Jeu {
public:
    Jeu(int);
    Jeu(const Jeu& orig);
    virtual ~Jeu();
    void initialisation();
    void jouer();
    void tourJoueur(Joueur*);
    bool joueurAGagne(Joueur*);
    void afficher ();

protected:
    Plateau plateau;
    list<Joueur*> Tabjoueur;
    map<pair<Joueur*,int>,Case*> placementpions;
};

#endif	/* JEU_H */

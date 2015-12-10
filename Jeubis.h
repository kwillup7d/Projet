/* 
 * File:   Jeu.h
 * Author: Bienvenue
 *
 * Created on 7 décembre 2015, 17:48
 */

#ifndef JEU_H
#define	JEU_H
#include <list>
#include <utility>
#include <map>
#include "Joueur.h"
#include "Humain.h"
#include "Robot.h"
#include "Plateau.h"

using namespace std;

//template <class T>
class Jeu {
public:
    Jeu(int);
    virtual ~Jeu();
    void initialisation();
    void jouer();
    void tourJoueur(Joueur*);
    bool joueurAGagne(Joueur*);
protected:
    Plateau plateau;
    list<Joueur*> Tabjoueur;
    map<pair<Joueur,Pion>,Case*> placementpions;
};

#endif	/* JEU_H */


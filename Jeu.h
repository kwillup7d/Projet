/* 
 * File:   Jeu.h
 * Author: Bienvenue
 *
 * Created on 7 décembre 2015, 17:48
 */

#ifndef JEU_H
#define	JEU_H
#include <list>
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
    Jeu(const Jeu& orig);
    virtual ~Jeu();
    void initialisation();
    void jouer();
    void tourJoueur(Humain*);
    void tourJoueur(Robot*);
    bool joueurAGagne(Joueur*);
protected:
    Plateau plateau;
    list<Joueur*> Tabjoueur;
    multimap<multimap<int,int>,Case*> placementpions;
};

#endif	/* JEU_H */


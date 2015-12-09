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
    bool joueurAGagne(Joueur*);
protected:
    Plateau plateau;
    Joueur* Tabjoueur;
    multimap<multimap<int,int>,Case*> placementpions;
};

#endif	/* JEU_H */


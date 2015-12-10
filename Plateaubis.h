/* 
 * File:   Plateau.h
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:50
 */

#ifndef PLATEAU_H
#define	PLATEAU_H
#include "Case.h"

class Plateau {
public:
    Plateau(int /*, Vue * v  */);
    virtual ~Plateau();
    int getNombreCases();
    Case* getCase(int);
    virtual int lancerDe(); // à cause des deux jeux serpent/ carthagéna, on pense attribuer cette fonction au joueur
    virtual bool caseLibre(Case*);  // pourquoi ce n'est pas une méthode de case ?
    virtual Case* avancerPion(Case*, int); // int parce qu'on se concentre d'abord sur le serpent
    virtual bool estEnFin(Case*);
protected:
    int nombrecases;
    Case** cases;
    // On peut rajouter la vue, qui sera fournie en parametre lors de l'appel au constructeur
    // Vue *v;
};

#endif	/* PLATEAU_H */


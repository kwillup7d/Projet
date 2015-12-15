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
    Plateau(int=64);
    virtual ~Plateau();
    int getNombreCases();
    Case* getCase(int);
    void setCase(int, Case*);
    virtual int lancerDe();
    //virtual Case* avancerPion(Case*, int);
    virtual bool estEnFin(Case*);
protected:
    int nombrecases;
    Case** cases;

};

#endif	/* PLATEAU_H */


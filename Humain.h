/* 
 * File:   Humain.h
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:34
 */

#ifndef HUMAIN_H
#define	HUMAIN_H
#include "Joueur.h"

class Humain : public Joueur {
public:
    Humain(int);
    Humain(const Humain& orig);
    virtual ~Humain();
    virtual int choixPions();
private:

};

#endif	/* HUMAIN_H */


/* 
 * File:   JoueurCartagena.h
 * Author: Bienvenue
 *
 * Created on 15 décembre 2015, 20:27
 */

#ifndef JOUEURCARTAGENA_H
#define	JOUEURCARTAGENA_H
#include "Joueur.h"
#include <map>

using namespace std;

class JoueurCartagena : public Joueur {
public:
    JoueurCartagena(Plateau*, int, int=1);
    virtual ~JoueurCartagena();
    void rajouterUneCarte();
    virtual int choixPions()=0;
    virtual int choixDeplacement()=0;
    virtual Case* avancerPion(Case*, int);
protected:
    map<char,int> cartes;
    int nombrescartes;

};

#endif	/* JOUEURCARTAGENA_H */


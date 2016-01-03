/*
 * File:   Case.h
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:19
 */

#ifndef CASE_H
#define	CASE_H

static int nbrecases;

class Case {
public:
    Case(char,int=0, int=0, int=1, int=0);
    Case(const Case& orig);
    virtual ~Case();
    int getNombrePions();
    int getNombrePionsMax();
    void setNombrePions(int);
    int getJouer();
    int getNumeroCase();
    int getLienCase();
    char getSymbole();
    bool caseEstLibre();
protected:
    int nombrepions;
    int nombrepionsmax;
    int numerocase;
    int jouer;
    int liencase;
    char symbole;
};

#endif	/* CASE_H */


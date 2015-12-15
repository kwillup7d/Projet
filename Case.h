/* 
 * File:   Case.h
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:19
 */

#ifndef CASE_H
#define	CASE_H

static int nbrecases = 0;

class Case {
public:
    Case(int=0, int=0, int=1);
    Case(const Case& orig);
    virtual ~Case();
    int getNombrePions();
    int getNombrePionsMax();
    void setNombrePions(int);
    int getJouer();
    int getNumeroCase();
    virtual int goTo();
    bool caseEstLibre();
    virtual int question();
protected:
    int nombrepions;
    int nombrepionsmax;
    int numerocase;
    int jouer;
};

#endif	/* CASE_H */


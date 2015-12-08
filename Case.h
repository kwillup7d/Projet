/* 
 * File:   Case.h
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:19
 */

#ifndef CASE_H
#define	CASE_H

class Case {
public:
    Case(int=0, int=0);
    Case(const Case& orig);
    virtual ~Case();
    int getNombrePions();
    int getJouer();
    virtual int goTo();
protected:
    int nombrepions;
    int jouer;
};

#endif	/* CASE_H */


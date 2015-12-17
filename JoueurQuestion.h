/* 
 * File:   JoueurQuestion.h
 * Author: Bienvenue
 *
 * Created on 14 décembre 2015, 09:34
 */

#ifndef JOUEURQUESTION_H
#define	JOUEURQUESTION_H
#include "Joueur.h"

class JoueurQuestion : public Joueur {
public:
    JoueurQuestion(Plateau*, int=1);
    virtual ~JoueurQuestion();
    virtual bool question()=0;
    virtual Case* avancerPion(Case*, int);
private:

};

#endif	/* JOUEURQUESTION_H */


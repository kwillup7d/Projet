/* 
 * File:   HumainQuestion.h
 * Author: Bienvenue
 *
 * Created on 14 décembre 2015, 09:52
 */

#ifndef HUMAINQUESTION_H
#define	HUMAINQUESTION_H
#include "JoueurQuestion.h"

class HumainQuestion : public JoueurQuestion {
public:
    HumainQuestion(Plateau*, int=1);
    virtual ~HumainQuestion();
    virtual int reponse();
    virtual int choixPions();
private:

};

#endif	/* HUMAINQUESTION_H */

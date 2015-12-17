/* 
 * File:   HumainCartagena.h
 * Author: Bienvenue
 *
 * Created on 15 décembre 2015, 21:12
 */

#ifndef HUMAINCARTAGENA_H
#define	HUMAINCARTAGENA_H
#include "JoueurCartagena.h"

class HumainCartagena : public JoueurCartagena {
public:
    HumainCartagena(Plateau*, int, int=1);
    virtual ~HumainCartagena();
    virtual int choixPions();
    virtual int choixDeplacement();
private:

};

#endif	/* HUMAINCARTAGENA_H */


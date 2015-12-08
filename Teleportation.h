/* 
 * File:   Teleportation.h
 * Author: Bienvenue
 *
 * Created on 1 décembre 2015, 00:15
 */

#ifndef TELEPORTATION_H
#define	TELEPORTATION_H
#include "Case.h"

class Teleportation : public Case {
public:
    Teleportation(int=0, int=0);
    Teleportation(const Teleportation& orig);
    virtual ~Teleportation();
    virtual int goTo();
private:

};

#endif	/* TELEPORTATION_H */


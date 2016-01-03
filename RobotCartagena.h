/*
 * File:   RobotCartagena.h
 * Author: Bienvenue
 *
 * Created on 15 décembre 2015, 21:17
 */

#ifndef ROBOTCARTAGENA_H
#define	ROBOTCARTAGENA_H
#include "JoueurCartagena.h"

class RobotCartagena : public JoueurCartagena{
public:
    RobotCartagena(Plateau*,int,int=1, char = 65);
    virtual ~RobotCartagena();
    virtual int choixPions();
    virtual int choixDeplacement();
private:

};

#endif	/* ROBOTCARTAGENA_H */


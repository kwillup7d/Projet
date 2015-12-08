/* 
 * File:   Robot.h
 * Author: Bienvenue
 *
 * Created on 30 novembre 2015, 23:36
 */

#ifndef ROBOT_H
#define	ROBOT_H
#include "Joueur.h"

class Robot : public Joueur{
public:
    Robot(int);
    Robot(const Robot& orig);
    virtual ~Robot();
    virtual int choixPions();
private:

};

#endif	/* ROBOT_H */


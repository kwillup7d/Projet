/* 
 * File:   RobotQuestion.h
 * Author: Bienvenue
 *
 * Created on 14 décembre 2015, 09:55
 */

#ifndef ROBOTQUESTION_H
#define	ROBOTQUESTION_H
#include "JoueurQuestion.h"

class RobotQuestion : public JoueurQuestion {
public:
    RobotQuestion(Plateau* plateau, int=1);
    virtual ~RobotQuestion();
    virtual bool question();
    virtual int choixPions();
private:

};

#endif	/* ROBOTQUESTION_H */


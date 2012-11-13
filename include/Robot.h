#ifndef ROBOT_H
#define ROBOT_H

#include <IDiggingSystem.h>
#include <IDrivingSystem.h>

#include "Position.h"


class Robot : public IDiggingSystem, public IDrivingSystem
{
    public:
        ///Constructor: Robot ready to go in a position of (a,x,y)
        Robot(double a=0, double x=0, double y=0){Position(a,x,y);}
        virtual ~Robot();

        ///Go forward with velocity v, for time t. Implicitly t=timing
        void go(double v=0, double t=T);

        ///Turn to an angle a, implicitly a=0
        void Turn(double a=0);

        ///Go forward to reach the distance s, implicitly s=0
        void goForward(double s=0); //drive forward to a distance s

        ///Go to mining spot, avoiding obstacles - high-level function
        void GoToMineSpot();

        ///Go to lunabin to unload the content of the cylinder
        void GoToLunabin();


        ///Seeing an obstacle - avoid it
        bool AvoidObstacle(); //if success- true

        ///Sets the posision of the robot
         //not sure if ok

        ///Return the present position
        Position findPosition(){return m_position;} //for navigation

    private:
        ///
        Position m_position; //x, y, a



};

#endif // ROBOT_H

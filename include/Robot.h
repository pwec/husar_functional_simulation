/// |------------------------------------------------------------------------------------------------|
/// |                                                                                                |
/// |               Class Robot - describes the whole Lunabot, It contains:                          |
/// |           *Position [x, y, alpha]                                                              |
/// |           *Descend the methods from IDiggingSystem and IDriving system                         |                                                        |
/// -------------------------------------------------------------------------------------------------|
/// |               The DiggingSystem can                                                            |
/// |           *Do what both system are written for                                                 |
/// |           *Go to lunabin and to the mining spot                                                |
/// |           *Avoid obstacles on the way to and from lunabins and mining spot                     |
/// |           *Give its posiiton                                                                   |
/// |           *Go to a position                                                                    |
/// |------------------------------------------------------------------------------------------------|



#ifndef ROBOT_H
#define ROBOT_H

#include <IDiggingSystem.h>
#include <IDrivingSystem.h>
#include <cstdlib>


#include "Position.h"


class Robot : public IDiggingSystem, public IDrivingSystem
{
    public:
        ///Constructor: Robot ready to go in a position of (x,y,a)
        Robot(){
                md_position = new double [3];
                md_position[0]=md_position[1]=md_position[2]=0.0;
                }

        virtual ~Robot();

        ///Go forward with velocity v, for time t. Implicitly t=timing
        void Go(double v=0, double t=T);

        ///Turn to an angle a, implicitly a=0
        void Turn(double a=0);

        ///Go forward to reach the distance s, implicitly s=0
        void GoForward(double s=0); //drive forward to a distance s

        ///Go to mining spot, avoiding obstacles - high-level function
        void GoToMineSpot();

        ///Go to lunabin to unload the content of the cylinder
        void GoToLunabin();

        ///change the current position because of new conditions etc.
        void ChangePosition(double* newPosition);


        //gives the current position
        double* GivePosition(){return md_position;}

        void Obstacle(){
            bool a=true;
            if(rand()%30)
                throw a;
        }

        ///Seeing an obstacle - avoid it
        void AvoidObstacle();


    private:
        double* md_position; //x, y, a



};

#endif // ROBOT_H

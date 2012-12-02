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


class Robot : public IDiggingSystem, public IDrivingSystem
{
    public:
        ///Constructor: Robot ready to go in a position of (x,y,a)
        Robot(double x, double y, double a);


        void SetPosition(double da, double ds); //
        void SetPosition(double* p);
        void Drive(double v=0, double t=T); //
        void Turn(double angle=0, double t=T); //
        void GoForward(double s=0); //


        virtual ~Robot(){}

        void GoToMineSpot();
        ///Go to lunabin to unload the content of the cylinder
        void GoToLunabin();

        void Obstacle(){
            bool a=true;
            if(rand()%30)
                throw a;
        }

        ///Seeing an obstacle - avoid it
        void AvoidObstacle();




};

#endif // ROBOT_H

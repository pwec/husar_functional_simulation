/// |------------------------------------------------------------------------------------------------|
/// |                                                                                                |
/// |               Class IDrivingSystem - describes the driving system of the Lunabot: it contains: |
/// |           *4 wheels                                                                            |
/// -------------------------------------------------------------------------------------------------|
/// |               The DrivingSystem                                                                |
/// |           *go forward to a distance s                                                          |
/// |           *go forward with a given velocity for a time t                                       |
/// |           *get the material until full                                                         |
/// |           *turn to an angle                                                                    |
/// |------------------------------------------------------------------------------------------------|



/// ASSUMPTION: differential? driving system



#ifndef IDRIVINGSYSTEM_H
#define IDRIVINGSYSTEM_H

#include "Wheel.h"

#define PI 3.14

class IDrivingSystem
{
    public:
        IDrivingSystem();
        virtual ~IDrivingSystem();
        virtual void Drive(double v=0, double t=T); //
        virtual void Turn(double angle=0, double t=T); //
        virtual void GoForward(double s=0); //

        virtual void SetLinearVelocity(double v){IDrivingSystem::md_linearVelocity=v;}
        virtual void SetAngularVelocity(double w){IDrivingSystem::md_angularVelocity=w;};

        virtual void SetPosition(double da, double ds)=0; //
        virtual void SetPosition(double* p)=0; //

        double* GetPosition(){return md_position;}
        double GetLinearVelocity(){return md_linearVelocity;}
        double GetAngularVelocity(){return md_angularVelocity;}
        double GetWheelTrack(){return md_wheelTrack;}

    protected:
        ///assumption: driving wheels are  0 & 1 - 0 is left, 1 is right
        Wheel m_wheel[4];
        double md_linearVelocity;
        double md_angularVelocity;
        double md_wheelTrack;
        double* md_position;
};

#endif // IDRIVINGSYSTEM_H

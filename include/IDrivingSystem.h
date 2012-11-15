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







#ifndef IDRIVINGSYSTEM_H
#define IDRIVINGSYSTEM_H

#include "Wheel.h"

class IDrivingSystem
{
    public:
        IDrivingSystem();
        virtual ~IDrivingSystem()=0;
        virtual void Drive(double v=0, double t=T);
        virtual void Turn(double angle=0)=0;
        virtual void GoForward();



    protected:
    private:
        Wheel m_wheel[4];
};

#endif // IDRIVINGSYSTEM_H

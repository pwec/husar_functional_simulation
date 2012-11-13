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


    protected:
    private:
        Wheel m_wheel[4];
};

#endif // IDRIVINGSYSTEM_H

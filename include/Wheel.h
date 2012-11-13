#ifndef WHEEL_H
#define WHEEL_H

#include "Engine.h"

///Wheel's radius
#define R 0.3

class Wheel
{
    public:
        Wheel(double w=0) : md_angVelocity(w), m_engine(Engine()) {} ;
        virtual ~Wheel();
        double GetVelocity() {return md_angVelocity;}

        void SetVelocity(double val=0, double time=T) { md_angVelocity = val; m_engine.SetVoltageFromAnVelocity(val/R); } //loop it for t

    protected:
    private:
        double md_angVelocity;
        Engine m_engine;
};

#endif // WHEEL_H

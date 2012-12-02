/// |------------------------------------------------------------------------------------------------|
/// |                                                                                                |
/// |               Class Wheel - describes the driving wheel powered by the engine. It has:         |
/// |           *Radius                                                                              |
/// |           *Current angular velocity                                                            |
/// |           *its own engine                                                                      |
/// -------------------------------------------------------------------------------------------------|
/// |               The Wheel can:                                                                   |
/// |           *return the currrent values (described above)                                        |
/// |           *be set to turn with the given angular velocity                                      |
/// |           *Avoid obstacles on the way to and from lunabins and mining spot                     |
/// |------------------------------------------------------------------------------------------------|





#ifndef WHEEL_H
#define WHEEL_H

#include "Engine.h"

///Wheel's radius
#define R 0.3

class Wheel
{
    public:
        Wheel(double w=0, double r=0.3) : md_angVelocity(w), md_radius(r), m_engine(Engine()) {} ;
        virtual ~Wheel(){}
        double GetVelocity() {return md_angVelocity;}
        double GetRadius() {return md_radius;}


        void SetAngularVelocity(double val=0, double time=T) { md_angVelocity = val; m_engine.SetVoltageFromAnVelocity(val/md_radius);}
        double GetAngularVelocity(){return md_angVelocity;}


    protected:
    private:
        double md_angVelocity;
        double md_radius;
        Engine m_engine;
};

#endif // WHEEL_H

/// |-------------------------------------------------------------------------------------------|
/// |                                                                                           |
/// |               Class Engine - describes the typical DC engine: it contains:                |
/// |           *instantaneous values of voltage and angular velocity                           |
/// |           *the maximum voltage and angular velocity                                       |
/// |           *the angular position                                                           |
/// |           *direction to move clockwise or counter-clockwise                               |
/// --------------------------------------------------------------------------------------------|
/// |               The engine can:                                                             |
/// |           *be set to have a given voltage, velocity, position and direction               |
/// |           *transform given voltage to angular velocity and the opposite                   |
/// |           *turn to an angle depending on the current direction                            |
/// |-------------------------------------------------------------------------------------------|





#ifndef ENGINE_H
#define ENGINE_H

#define WINDOWS

#ifdef WINDOWS
#include <windows.h>
#define SLEEP(time) Sleep(time)
#endif

#ifndef WINDOWS
#define SLEEP(time) uSleep(1000*time)
#endif



#include <climits>
#include <iostream>
#include <cmath>

///Timing
#define T 0.5

///Maximum voltage on the engine
#define Umax 12

///Maximum angular velocity
#define Wmax 2600

///Transformation between angular velocity from engine to wheel
#define K 1




class Engine
{
    public:

        ///ctor: voltage, angular velocity, position and direction: 0 for cw
        Engine(double V=Umax, double W=Wmax, double v=0, double w=0, int pos=0, bool cw=0) : md_voltage(v), md_anvelocity(w), md_position(0), mb_direction(true) {};
        virtual ~Engine();

        double GetVoltage() { return md_voltage; }
        void SetVoltage(double val=0) { md_voltage = val; } //set voltage

        double GetAnVelocity() { return md_anvelocity; }
        ///Set the angular velocity of the engine
        void SetAnVelocity(double val=0, double time=T) { md_anvelocity = val; }


        int GetPosition() { return md_position; }
        void SetPosition(double a=0, double w=Wmax/10); //


        bool GetDirection() { return mb_direction; }
        ///Set the direction: 0 for CW, 1 for CCW
        void SetDirection(bool val=true) { mb_direction = val; }

        void SetVoltageFromAnVelocity(double w);
        void SetAnVelocityFromVoltage(double v);

        double GetMaxVoltage(){return md_maxvoltage;}
        double GetMaxAnVelocity(){return md_maxanvelocity;}

    private:
        double md_voltage;
        double md_maxvoltage;

        double md_anvelocity;
        double md_maxanvelocity;


        ///between 0 and 359
        double md_position;
        bool mb_direction;
};

#endif // ENGINE_H

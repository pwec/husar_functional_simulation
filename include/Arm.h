/// |-------------------------------------------------------------------------------------------|
/// |                                                                                           |
/// |               Class Arm - describes the typical DC engine: it contains:                |
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





#ifndef ARM_H
#define ARM_H

#include "Engine.h"

enum POSITION  {a=1,b,c,d};

class Arm
{
    public:
        Arm(POSITION pos = a) : m_position(), m_engine(Engine()) {} ;
        virtual ~Arm(){}

        POSITION GetPosition() { return m_position; }
        void SetPosition(POSITION val=a);

    protected:
    private:
        POSITION m_position;
        Engine m_engine;
};

#endif // ARM_H

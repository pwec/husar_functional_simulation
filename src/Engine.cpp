/*husar logo or watewa */

/// |---------------------------------------------------------------------------------------------------------------|
/// |                               Here are the functions of the engine:                                           |
/// |                   -Set the voltage from the given angular velocity                                            |
/// |                   -Do the opposite: voltage generates angular velocity                                        |
/// |                   -Move to an angular position, depending on the direction: clockwise or counter-clockwise    |
/// |---------------------------------------------------------------------------------------------------------------|

#include "Engine.h"


///Sets voltage on the engine depending on the angular velocity
void Engine::SetVoltageFromAnVelocity(double w){md_voltage= w*Engine::GetMaxVoltage()/Engine::GetMaxVoltage();}

///Sets angular velocity depending on the voltage
void Engine::SetAnVelocityFromVoltage(double v){md_anvelocity=v*Engine::GetMaxAnVelocity()/Engine::GetMaxVoltage();}

///Sets the position of the engine to an angle a
void Engine::SetPosition(double a, double w){
        if (w==0){
            std::cout<<"Wrong angular velocity!!!\n";
            std::cin>>w;
        }

        ///time to sleep
        double t=0;
        double da = a-GetPosition();

        if (GetDirection()){t = (da>0 ? da/w : (360-da)/w); }
        else { t=( da>0 ? (360-da)/w : da/w ); }


        md_position=a;
        SLEEP(t);
}


Engine::~Engine() {}

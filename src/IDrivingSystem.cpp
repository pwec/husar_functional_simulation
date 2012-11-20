#include "IDrivingSystem.h"


///drive with the given velocity at a time t
void IDrivingSystem::Drive(double v, double t){
    ///values needed to calculate teh new angular velocities of the wheels
    r0 = IDrivingSystem::m_wheel[0].GetRadius();
    r1 = IDrivingSystem::m_wheel[1].GetRadius();
    wl = IDrivingSystem::m_wheel[0].GetAngularVelocity();
    wr = IDrivingSystem::m_wheel[1].GetAngularVelocity();

    ///set the new values of the angular velocities on each wheel
    IDrivingSystem::m_wheel[0].SetAngularVelocity(v/(2*PI*r0));
    IDrivingSystem::m_wheel[1].SetAngularVelocity(v/(2*PI*r1)) ;

    ///sleep for given time t
    SLEEP(t);

    ///return to the previous values
    IDrivingSystem::m_wheel[0].SetAngularVelocity(wl);
    IDrivingSystem::m_wheel[0].SetAngularVelocity(wr);

    ///CHANGE THE COORDINATES!!!

    ///send the message what happened
    std::cout<<"I have driven with the velocity "<<v<<" for time "<<t<<std::endl;
}

///turns to an angle at time t. It uses the transformation formulas, described in "Nawigacja robotów mobilnych"
void IDrivingSystem::Turn(double angle, double t){
     ///values needed to calculate teh new angular velocities of the wheels
    double v = IDrivingSystem::GetLinearVelocity();
    double w = IDrivingSystem::GetAngularVelocity();
    double rl = IDrivingSystem::m_wheel[0].GetRadius();
    double rr = IDrivingSystem::m_wheel[1].GetRadius();
    double d = IDrivingSystem::GetWheelTrack();
    double wl = IDrivingSystem::m_wheel[0].GetAngularVelocity();
    double wr = IDrivingSystem::m_wheel[1].GetAngularVelocity();

    ///check the angle and then decide which angular velocity changes
   if (angle>0) {
       ///calculate the value
       IDrivingSystem::m_wheel[0].SetAngularVelocity(w*d/r+wr);
       SLEEP(t);
       ///set the value
       IDrivingSystem::m_wheel[0].SetAngularVelocity(wl);
   }
   else {
       ///calculate the value
       IDrivingSystem::m_wheel[1].SetAngularVelocity(-wl+wd/r);
       SLEEP(t);
        ///set the value
       IDrivingSystem::m_wheel[1].SetAngularVelocity(wr);
   }

    ///CHANGE THE COORDINATES!!!

    ///send a message
    std::cout<<"I have turned to an angle "<<alpha<<std::endl;

}

///drive to a given distance
void IDrivingSystem::GoForward(double s){
    ///check the current velocity
    double v = IDrivingSystem::GetLinearVelocity();

    ///check if it's not zero
    while ( v == 0){
        std::cout<<"My linear velocity equals 0!!! Set the linear velocity."<<std::endl;
        std::cin>>v;
        IDrivingSystem::GetLinearVelocity(v);
    }

    ///calculate time t to sleep
    double t = s/v;
    SLEEP(t);

    ///CHANGE THE COORDINATES!!!

    ///send a message
    std::cout<<"I have went forward to a distance "<<s<<std::endl;
}

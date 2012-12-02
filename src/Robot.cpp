#include "Robot.h"


 #include "IDrivingSystem.h"
#include <cmath>

Robot::Robot(double x, double y, double a){
            md_linearVelocity=md_angularVelocity=0;
            md_wheelTrack=1.0;
            for (int i=0; i<4; ++i)
                m_wheel[i] = Wheel();

            md_position = new double [3];
            md_position[0]=x;
            md_position[1]=y;
            md_position[2]=a;

            m_cylinder = Cylinder();
            m_arm = Arm();
        }


void Robot::SetPosition(double* p){
    md_position[0]=p[0];
    md_position[1]=p[1];
    md_position[2]=p[2];
    }


///calculate the position (odometry + differential drive robot)
void Robot::SetPosition(double ds, double da){
    ///get the old position
    double* p_old= new double[3];

    for (int i=0; i<3; ++i)
        p_old[i] = Robot::GetPosition()[i];

    double a = p_old[2];
    double dx= ds * cos(a+da/2);
    double dy= ds * sin(a+da/2);

    ///add the dx, dy, da to the old position to get the new one
    double* p_new = new double [3];
        p_new[0]=dx+ p_old[0];
        p_new[1]=dy+ p_old[1];
        p_new[2]=da+ p_old[2];

    Robot::SetPosition(p_new);

    std::cout<<"My new position is ["<<p_new[0]<<", "<<p_new[1]<<", "<<p_new[2]<<"]\n";
    delete [] p_old;
    delete [] p_new;
}

///drive with the given velocity at a time t
void Robot::Drive(double v, double t){
    ///values needed to calculate teh new angular velocities of the wheels
    double r0 = Robot::m_wheel[0].GetRadius();
    double r1 = Robot::m_wheel[1].GetRadius();
    double wl = Robot::m_wheel[0].GetAngularVelocity();
    double wr = Robot::m_wheel[1].GetAngularVelocity();

    ///set the new values of the angular velocities on each wheel
    Robot::m_wheel[0].SetAngularVelocity(v/(2*PI*r0));
    Robot::m_wheel[1].SetAngularVelocity(v/(2*PI*r1));
    Robot::SetLinearVelocity(v);

    ///sleep for given time t
    SLEEP(t);

    ///return to the previous values
    Robot::m_wheel[0].SetAngularVelocity(wl);
    Robot::m_wheel[0].SetAngularVelocity(wr);

    double ds = v*t;
    double da=0.0;

    ///send the message what happened
    Robot::SetPosition(ds,da);
    std::cout<<"I have driven with the velocity "<<v<<" for time "<<t<<std::endl;

}

///turns to an angle at time t. It uses the transformation formulas, described in "Nawigacja robotów mobilnych"
void Robot::Turn(double angle, double t){
     ///values needed to calculate teh new angular velocities of the wheels
    //double v =  Robot::GetLinearVelocity();
    double w = Robot::GetAngularVelocity();
    double rl = Robot::m_wheel[0].GetRadius();
    double rr = Robot::m_wheel[1].GetRadius();
    double d = Robot::GetWheelTrack();
    double wl = Robot::m_wheel[0].GetAngularVelocity();
    double wr = Robot::m_wheel[1].GetAngularVelocity();

    ///check the angle and then decide which angular velocity changes
   if (angle>0) {
       ///calculate the value
       Robot::m_wheel[0].SetAngularVelocity(w*d/rr+wr);
       SLEEP(t);
       ///set the value
       Robot::m_wheel[0].SetAngularVelocity(wl);
   }
   else {
       ///calculate the value
       Robot::m_wheel[1].SetAngularVelocity(-wl+w*d/rl);
       SLEEP(t);
        ///set the value
       Robot::m_wheel[1].SetAngularVelocity(wr);
   }

    ///temporary velocity while turning  - (v_left + v_right)/2
    double ds = (wl * rl + wr * rr)/2*t;
    double da=angle;

    ///change position
    Robot::SetPosition(ds,da);
    ///send a message
    std::cout<<"I have turned to an angle "<<angle<<std::endl;


}

///drive to a given distance
void Robot::GoForward(double s){
    ///check the current velocity
    double v =  Robot::GetLinearVelocity();

    ///check if it's not zero
    while ( v == 0){
        std::cout<<"My linear velocity equals 0!!! Set the linear velocity."<<std::endl;
        std::cin>>v;
        //IDrivingSystem::SetLinearVelocity(v);
    }

    ///calculate time t to sleep
    double t = s/v;
    SLEEP(t);

    ///change the coordinates - only the distance changed
    double ds = s;
    double da=0;
     Robot::SetPosition(ds,da);

    ///send a message
    std::cout<<"I have went forward to a distance "<<s<<std::endl;
}

        ///Go to mining spot, avoiding obstacles - high-level function
void Robot::GoToMineSpot(){


}

        ///Go to lunabin to unload the content of the cylinder
void Robot::GoToLunabin(){
    //double Lunabin=[20.0,10.0];

    try{
        Obstacle();
        }

    catch ( bool a ){
        AvoidObstacle();
    }
}


        ///Seeing an obstacle - avoid it
void Robot::AvoidObstacle(){


    } //if success- true

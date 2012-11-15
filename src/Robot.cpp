#include "Robot.h"

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

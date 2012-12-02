#include <iostream>
#include "Robot.h"


using namespace std;

int main()
{

    Robot Lunabot = Robot(0.0, 0.0, 0.5);
    Lunabot.Drive(5, 0.2);
    Lunabot.Turn(1.7, 2);
    Lunabot.Dig();
    Lunabot.Drive(5, 0.2);
    Lunabot.GoForward(3.0);
    Lunabot.Drop();

    return 0;
}

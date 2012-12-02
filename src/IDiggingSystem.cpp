#include "IDiggingSystem.h"


///assuming that a-for driving, angle=0, b-for dropping angle=45 , c-digging, angle=130

IDiggingSystem::IDiggingSystem(){m_arm = Arm(); m_cylinder = Cylinder();}
IDiggingSystem::~IDiggingSystem() {}

void IDiggingSystem::Dig(){
    ///set the needed arm position
    m_arm.SetPosition(c);
    ///start digging!
    m_cylinder.GetMaterial();
    ///after move the arm to go
    m_arm.SetPosition(a);
    std::cout<<"\nI have successfully dug the desired amount of the material\n";
    }

void IDiggingSystem::Drop(){
    ///set the arm to the needed position
    m_arm.SetPosition(c);
    ///unload the matherial
    m_cylinder.Unload();
    ///vibrate the cylinder
    m_cylinder.Vibrate();
    ///set arm to the previous position
    m_arm.SetPosition(a);
    std::cout<<"\nI have successfully unloaded the material to the lunabin\n";
}

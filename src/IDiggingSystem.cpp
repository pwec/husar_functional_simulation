#include "IDiggingSystem.h"

void IDiggingSystem::Dig(){
    //move the arm
    m_cylinder.GetMaterial();
    //move the arm
    SLEEP(1000);
    }

void IDiggingSystem::Drop(){
    //move the arm
    m_cylinder.Unload();
    m_cylinder.Vibrate();
    //move the arm
}

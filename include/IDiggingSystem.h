/// |------------------------------------------------------------------------------------------------|
/// |                                                                                                |
/// |               Class IDiggingSystem - describes the driving system of the Lunabot: it contains: |
/// |           *Cylinder                                                                            |
/// |           *Arm                                                                                 |
/// -------------------------------------------------------------------------------------------------|
/// |               The DiggingSystem can                                                            |
/// |           *Dig the material                                                                    |
/// |           *Drop the material to the lunabin                                                    |
/// |                                                                                                |
/// |------------------------------------------------------------------------------------------------|


#ifndef IDIGGINGSYSTEM_H
#define IDIGGINGSYSTEM_H

#include "Cylinder.h"
#include "Arm.h"

class IDiggingSystem
{
    public:
        IDiggingSystem();
        virtual ~IDiggingSystem();
        virtual void Dig()=0;
        virtual void Drop()=0;


    protected:
    private:
        Cylinder m_cylinder;
        Arm m_arm;
};

#endif // IDIGGINGSYSTEM_H

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

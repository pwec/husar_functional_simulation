#include "Cylinder.h"



 void Cylinder::Vibrate(){

    ///move the cylinder back and forth
    m_engine.Engine::SetPosition(m_engine.GetPosition()+30.0);
    m_engine.Engine::SetPosition(m_engine.GetPosition()-60.0);
 }

 void Cylinder::GetMaterial(double weight){

    if (weight> Cylinder::GetWeight()){
        std::cout<<"Too much to load!\n";
        std::cin>>weight;
    }

    ///How much time to get the weight (in miliseconds)
    double t = (weight/Cylinder::GetWeightAtOnce())*1000;

    ///Make the engine move
    double a = m_engine.Engine::GetAnVelocity();
    m_engine.SetPosition(a*t);
    //SetWeight(weight);

    ///Additional time
    SLEEP(1000);
 }

 void Cylinder::Unload(double weight){
        double t = GetWeight() / WEIGHTATONCE *1000;
        SLEEP(t);
        Cylinder::Empty();
        Vibrate();

    }

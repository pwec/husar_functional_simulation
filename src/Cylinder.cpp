#include "Cylinder.h"



 void Cylinder::Vibrate(){

    ///move the cylinder back and forth
    m_engine.SetPosition(m_engine.GetPosition()+30.0);
    m_engine.SetPosition(m_engine.GetPosition()-60.0);
    std::cout<<"\nI have got rid off the remaining material from the cylinder\n";
 }

 void Cylinder::GetMaterial(double weight){

    if (weight > Cylinder::GetMaxWeight()){
        std::cout<<"\nToo much to load!\n";
        std::cin>>weight;
    }

    ///How much time to get the weight (in seconds)
    double t = (weight/Cylinder::GetWeightAtOnce());

    ///Make the engine move
    double a = m_engine.Engine::GetAnVelocity();
    m_engine.SetPosition(a*t);
    //SetWeight(weight);

    ///Additional time
    SLEEP(1);
    std::cout<<"\nI have loaded "<<weight<<" of matherial\n";

 }

 void Cylinder::Unload(double weight){
     ///calculating the time t needen to drop the material
        double t = GetWeight() / WEIGHTATONCE;
        SLEEP(t);
        Cylinder::Empty();
        Vibrate();
        std::cout<<"\nI have unloaded the material\n";

    }

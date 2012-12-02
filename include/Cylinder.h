/// |-------------------------------------------------------------------------------------------|
/// |                                                                                           |
/// |               Class Cylinder - describes the cylinder of the Lunabot: it contains:        |
/// |           *instantaneous value of weight                                                  |
/// |           *the maximum weight of the material                                             |
/// |           *the single ?load? of the material                                              |
/// |           *flaps which are on/off to unload material                                      |
/// |           *electromagnet on/off to get rid off the remains of the moondust                |
/// |           *its own engine                                                                 |
/// --------------------------------------------------------------------------------------------|
/// |               The cylinder can:                                                           |
/// |           *be set to have a values described above                                        |
/// |           *get the material of the given weight                                           |
/// |           *get the material until full                                                    |
/// |           *unload the material                                                            |
/// |           *vibrate to get rid off the moondust with electromagnets on                     |
/// |-------------------------------------------------------------------------------------------|







#ifndef CYLINDER_H
#define CYLINDER_H

#include "Engine.h"

///maximum weight
#define WEIGHT 10

///maximum weight of the material for one full move of the cylinder
#define WEIGHTATONCE 0.5

class Cylinder
{
    public:
        Cylinder(double weight=0.0, double weightatonce=WEIGHTATONCE, double maxweight=WEIGHT, bool flap=false, bool electro=false) : md_weight(weight), md_weightatonce(weightatonce), md_maxweight(maxweight), mb_flap(flap), mb_electromagnet(electro) {};
        virtual ~Cylinder(){}

        double GetWeight() { return md_weight; }
        bool IsCylinderFull() {if (md_weight==md_maxweight) return true; else return false;};

        ///Returns true if the flaps are open
        bool IsFlapOn() { return mb_flap; }
        ///Sets the flaps to be : open-> true
        void SetFlap(bool val=true) { mb_flap = val; }

        ///Turns on/off the electromagnet
        void SetElectromagnet(bool val=false){mb_electromagnet = val;}
        ///Returns true if electromagnet is on
        bool IsElectroMagnetOn(){return mb_electromagnet;}

        double GetMaxWeight() {return md_maxweight;}
        double GetWeightAtOnce() {return md_weightatonce;}

        void Empty() {md_weight = 0;}
        ///Vibrates the cylinder to get rid off the moon sand
        void Vibrate(); //move cylinder cw and ccw for 0.5 s

        ///Starts digging until reaches the weight of the material - implicitly until full
        void GetMaterial(double weight=WEIGHT);

        ///unloads the material
        void Unload(double weight=WEIGHT);



    protected:
    private:
        double md_weight;
        double md_weightatonce;
        double md_maxweight;

        bool mb_flap;
        bool mb_electromagnet;
        Engine m_engine;

};

#endif // CYLINDER_H

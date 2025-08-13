#ifndef Card_H_
#define Card_H_
#include <iostream>
#include "definitions.h"
#include "Good_Card_def.h"

struct Conditions{
    bool Unblockable = false;
    bool Ready = true;
};

struct Attributes{
    int Movement_Speed = Default_Speed;
    int Attack = 0; 
    int Defence = 0;
};

class Card{

    public:

    Card(int card_type, int movement_speed = Default_Speed, int attack = 0, int defence = 0, int unblockable = false, bool ready = true);

    virtual int Unique_Effect();

    int get_attack();
    int get_defence();

    bool has_ability = true;

    int type;

    private:

    Attributes attributes;

    Conditions conditions;

    


    
    


};


#endif 

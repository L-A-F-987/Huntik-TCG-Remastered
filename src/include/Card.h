#ifndef Card_H_
#define Card_H_
#include <iostream>
#include <string>
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

    Card(int card_type,std::string name, int attack = 0, int defence = 0,int movement_speed = Default_Speed, int unblockable = false, bool ready = true);

    //virtual action functions to be overwritten when card created
    virtual int Exhaust_Action();
    virtual int Free_Action();
    virtual int Combat_Action();

    int get_attack();
    int get_defence();

    std::string get_name();

    bool has_ability = true;

    int type;

    private:

    std::string Name = "";

    Attributes attributes;

    Conditions conditions;


};


#endif

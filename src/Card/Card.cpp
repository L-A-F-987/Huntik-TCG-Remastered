#include "Card.h"

Card::Card(
    Type card_type,
    std::string card_name,
    bool card_allignment,
    int attack,
    int defence,
    int movement_speed,
    bool unblockable,
    bool ready)
{

    type = card_type;
    name = card_name;
    allignment = card_allignment;


    switch(type.primary_type){

        case(HERO):
            //setting attributes
            attributes.Movement_Speed = movement_speed;
            attributes.Attack = attack;
            attributes.Defence = defence;

            //setting conditions
            conditions.Unblockable = unblockable;
            conditions.Ready = ready;
            break;
    }


}

std::string Card::get_name(){

    if  (!name.empty())
    {
        return name;
    }
    else
    {
        throw std::invalid_argument("No Name");
    }
}

int Card::get_attack(){

    if  (type.primary_type == HERO)
    {
        return attributes.Attack;
    }

    else
    {
#ifdef ENABLE_ASSERTS
        throw std::invalid_argument("Non-Hero Card Has No Attribute: Attack");
#endif

        return -1;
    }
};

int Card::get_defence(){

    if  (type.primary_type == HERO)
    {
        return attributes.Defence;
    }

    else
    {

#ifdef ENABLE_ASSERTS
        throw std::invalid_argument("Non-Hero Card Has No Attribute: Defence");
#endif

        return -1;
    }
}

//Virtual Functions For possible Abilities
int Card::Exhaust_Action(){

    return -1;

};

int Card::Free_Action(){

    return -1;

};

int Card::Combat_Action(){

    return -1;

};





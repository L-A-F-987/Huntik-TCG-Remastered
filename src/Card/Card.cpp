#include "Card.h"

Card::Card(Type card_type, std::string card_name, bool card_allignment,
    int attack, int defence, int movement_speed, bool unblockable,
    bool ready)
{

    type = card_type;
    name = card_name;
    allignment = card_allignment;


    switch(type.primary_type){

        case(HERO):
            //setting base attributes
            attributes.Movement_Speed = movement_speed;
            attributes.Base_Attack = attack;
            attributes.Base_Defence = defence;

            // setting current values
            attributes.Attack = attack;
            attributes.Defence = defence;
            attributes.Movement_Speed = movement_speed;

            //setting conditions
            conditions.Unblockable = unblockable;
            conditions.Ready = ready;
            break;
    }


}

std::string Card::GetName(){

    if  (!name.empty())
    {
        return name;
    }
    else
    {
        throw std::invalid_argument("No Name");
    }
}

int Card::GetCurrentAttack(){

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

int Card::GetCurrentDefence(){

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

int Card::GetAttack(){

    if  (type.primary_type == HERO)
    {
        return attributes.Base_Attack;
    }

    else
    {
    #ifdef ENABLE_ASSERTS
        throw std::invalid_argument("Non-Hero Card Has No Attribute: Attack");
    #endif

        return -1;
    }
};

int Card::GetDefence(){

    if  (type.primary_type == HERO)
    {
        return attributes.Base_Defence;
    }

    else
    {
    #ifdef ENABLE_ASSERTS
        throw std::invalid_argument("Non-Hero Card Has No Attribute: Attack");
    #endif

        return -1;
    }
};

//Virtual Functions For possible Abilities
int Card::ExhaustAction(){

    return -1;

};

int Card::FreeAction(){

    return -1;

};

int Card::CombatAction(){

    return -1;

};





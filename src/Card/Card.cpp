#include "Card.h"

Card::Card(int h_type, int l_type, std::string name, int attack, int defence, int movement_speed, int unblockable, bool ready){

    Name = name;
    high_level_type = h_type;
    low_level_type = l_type;
    switch(high_level_type){

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


};

std::string Card::get_name(){

    if(!Name.empty()){
        return Name;
    }
    else{
        throw std::invalid_argument("No Name");
    }
};

int Card::get_attack(){

    if(high_level_type == HERO){
        return attributes.Attack;
    }

    else{
        throw std::invalid_argument("Action Card Has No Attribute: Attack");
    }
};

int Card::get_defence(){

    if(high_level_type == HERO){
        return attributes.Defence;
    }

    else{
        throw std::invalid_argument("Action Card Has No Attribute: Defence");
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






#include "Card.h"

Card::Card(int card_type,std::string name, int attack, int defence, int movement_speed, int unblockable, bool ready){

    if (card_type > 4 || card_type < 0){
        throw std::invalid_argument( "invalid type" );
    }

    type = card_type;

    Name = name;

    switch(type){

        case(Major_Hero):
        case(Minor_Hero):

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

    if(type == Major_Hero || type == Minor_Hero){
        return attributes.Attack;
    }

    else{
        throw std::invalid_argument("Action Card Has No Attribute: Attack");
    }
};

int Card::get_defence(){

    if(type == Major_Hero || type == Minor_Hero){
        return attributes.Defence ;
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





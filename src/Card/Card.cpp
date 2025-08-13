
#include "Card.h"

Card::Card(int card_type, int movement_speed, int attack, int defence, int unblockable, bool ready){

    if (card_type > 4 || card_type < 0){
        throw std::invalid_argument( "invalid type" );
    }

    type = card_type;

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

int Card::get_attack(){

    if(type == Major_Hero || type == Minor_Hero){
        return attributes.Attack;
    }

    else{
        return -1;
    }
};

int Card::get_defence(){

    if(type == Major_Hero || type == Minor_Hero){
        return attributes.Defence ;
    }

    else{
        return -1;
    }
}

int Card::Unique_Effect(){

    return -1;

};





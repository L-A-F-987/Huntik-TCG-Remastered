#ifndef Card_H_
#define Card_H_
#include <iostream>
#include "definitions.h"


struct Attributes{
    int Movement_Speed = Default_Speed;
    int Attack; 
    int Defence;
};

struct Conditions{
    bool Unblockable = false;
    bool Ready = true;
};

class Card{

    public:

    void print_test();

    void fill_attributes(int Inputted_Attack, int Inputted_Defence, int Inputted_Movement_Speed = Default_Speed);

    Attributes Attrabute;
        
    private:

    int x;

    Conditions Condition;
    


};


#endif 

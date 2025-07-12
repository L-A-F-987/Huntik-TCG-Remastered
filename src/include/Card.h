#ifndef Card_H_
#define Card_H_
#include <iostream>
#include "definitions.h"


struct Attributes{
    int Movement_Speed = Default_Speed
    int Attack; 
    int Defence;
};

struct Conditions{
    bool Unblockable = false;
    bool Ready = true;
};

class Card{

    public:

    Attributes Attrabute;

    Conditions Condition;

    void print_test();
        
    private:

    int x;
    


};


#endif 

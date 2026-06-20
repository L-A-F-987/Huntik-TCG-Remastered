#include "Card.h"

int main(){

    Card C(Type{HERO,MAJOR_HERO}, "demo", "ABC", "123", GOOD);
    std::cout<<"Attack & Defence: "<< C.GetAttack()<<C.GetDefence()<<std::endl;

}
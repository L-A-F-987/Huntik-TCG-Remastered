#include "Card.h"

int main(){

    Card C(Type{HERO,MAJOR_HERO}, "demo",GOOD);
    std::cout<<"Attack & Defence: "<< C.GetAttack()<<C.GetDefence()<<std::endl;

}
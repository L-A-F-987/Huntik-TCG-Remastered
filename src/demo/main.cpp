#include "Card.h"

int main(){

    Card C(HERO,MAJOR_HERO, "demo");
    std::cout<<"Attack & Defence: "<< C.get_attack()<<C.get_defence()<<std::endl;

}
#include "Card.h"

int main(){

    Card C(Action, "demo");
    std::cout<<"Attack & Defence: "<< C.get_attack()<<C.get_defence()<<std::endl;

}
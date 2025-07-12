#ifndef Board_H_
#define Board_H_
#include "Card.h"


class Board{

    public:
        int x;

        void Play_Hero_Card(Card* Played_Card, bool Player_Id);

    private:
        std::vector<Card> Row_1;
        std::vector<Card> Row_2;
        std::vector<Card> Row_3;
        std::vector<Card> Row_4;
        std::vector<Card> Row_5;

};



#endif
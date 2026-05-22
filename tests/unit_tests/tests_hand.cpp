#include <gtest/gtest.h>
#include "Hand.h"

TEST(HandTest, Test_Add_Card_Succeeds){
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", GOOD);
    Hand test_hand;
    EXPECT_NO_THROW(test_hand.AddCard(&card_1));

}

TEST(HandTest, Test_Add_Card_Increments_n_Cards_by_1){
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", GOOD);
    Hand test_hand;
    int initial_hand_size = test_hand.GetHandSize();
    test_hand.AddCard(&card_1);

    EXPECT_EQ(test_hand.GetHandSize(), initial_hand_size + 1);

}
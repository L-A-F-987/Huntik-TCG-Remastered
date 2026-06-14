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

TEST(HandTest, Test_Remove_Card_Succeeds){
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", GOOD);
    Hand test_hand;
    test_hand.AddCard(&card_1);
    EXPECT_NO_THROW(test_hand.RemoveCard(&card_1));
}

TEST(HandTest, Test_Remove_Card_Fails_For_Empty_Hand){
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", GOOD);
    Hand test_hand;
    EXPECT_THROW(
        test_hand.RemoveCard(&card_1),
        std::runtime_error
    );
}

TEST(HandTest, Test_Remove_Card_Increments_n_Cards_by_1){
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", GOOD);
    Hand test_hand;
    test_hand.AddCard(&card_1);
    int initial_hand_size = test_hand.GetHandSize();
    test_hand.RemoveCard(&card_1);

    EXPECT_EQ(test_hand.GetHandSize(), initial_hand_size - 1);
}

TEST(HandTest, Test_ListCurrentCards){
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", GOOD);
    Hand test_hand;
    test_hand.AddCard(&card_1);
    std::vector<Card*>  expected_cards_in_hand = {&card_1};
    EXPECT_EQ(test_hand.ListCurrentCards(), expected_cards_in_hand);
}

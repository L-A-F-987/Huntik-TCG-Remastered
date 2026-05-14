#include <gtest/gtest.h>
#include "Deck.h"

// Testing constructor storage

TEST(DeckTest,Testing_Name_Declaration){

    // variables for deck test
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", GOOD);
    std::deque<Card> test_cards_list = {card_1};
    std::string name = "test";

    // creating deck and testing
    Deck test_deck(test_cards_list, name);
    EXPECT_EQ(test_deck.name, name);

};


// Testing Draw Function Calls

TEST(DeckTest, Testing_Draw_Success) {
    Card card_1(Type{HERO, MINOR_HERO}, "test 1", GOOD);
    std::deque<Card> test_cards_list = {card_1};
    Deck test_deck(test_cards_list, "test");

    std::optional<Card> top_card = test_deck.DrawCard();

    EXPECT_TRUE(top_card == card_1);
}

TEST(DeckTest, Testing_Draw_Failure) {
    std::deque<Card> test_cards_list = {};
    Deck test_deck(test_cards_list, "test");

    EXPECT_FALSE(test_deck.DrawCard());
}

TEST(DeckTest, Testing_Draw_Decreases_Size) {
    Card card_1(Type{HERO, MINOR_HERO}, "test 1", GOOD);
    Card card_2(Type{HERO, MINOR_HERO}, "test 2", GOOD);
    std::deque<Card> test_cards_list = {card_1, card_2};
    Deck test_deck(test_cards_list, "test");

    test_deck.DrawCard();

    EXPECT_EQ(test_deck.GetDeckSize(), 1);
}

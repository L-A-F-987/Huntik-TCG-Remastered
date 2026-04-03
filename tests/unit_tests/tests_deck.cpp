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

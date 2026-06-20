#include <gtest/gtest.h>
#include "Deck.h"

// Testing constructor storage

TEST(DeckTest,Testing_Name_Declaration){

    // variables for deck test
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    std::deque<Card*> test_cards_list = {&card_1};
    std::string name = "test";

    // creating deck and testing
    Deck test_deck(test_cards_list, name);
    EXPECT_EQ(test_deck.GetDeckName(), name);

};


// Testing Draw Function Calls

TEST(DeckTest, Testing_Draw_Success) {
    Card card_1(Type{HERO, MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    std::deque<Card*> test_cards_list = {&card_1};
    Deck test_deck(test_cards_list, "test", false);

    std::optional<Card*> drawn = test_deck.DrawCard();
    Card* top_card = *drawn;

    EXPECT_EQ(top_card, &card_1);
    EXPECT_TRUE(*top_card == card_1);
}

TEST(DeckTest, Testing_Draw_Failure) {
    std::deque<Card*> test_cards_list = {};
    Deck test_deck(test_cards_list, "test", false);

    EXPECT_FALSE(test_deck.DrawCard());
}

TEST(DeckTest, Testing_Draw_Decreases_Size) {
    Card card_1(Type{HERO, MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    Card card_2(Type{HERO, MINOR_HERO}, "test 2", "ABC", "123", GOOD);
    std::deque<Card*> test_cards_list = {&card_1, &card_2};
    Deck test_deck(test_cards_list, "test", false);

    test_deck.DrawCard();

    EXPECT_EQ(test_deck.GetDeckSize(), 1);
}

// Testing Add Card Function
TEST(DeckTest, Testing_Add_Card_Default) {
    Card initial_card_1(Type{HERO, MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    Card inserted_card(Type{HERO, MINOR_HERO}, "test 2", "ABC", "123", GOOD);
    std::deque<Card*> test_card_list = {&initial_card_1};
    Deck test_deck(test_card_list, "test", false);

    test_deck.AddToDeck(&inserted_card);

    // Check the Top card is not the Inserted Card
    auto drawn_first = test_deck.DrawCard();
    Card* top_deck_ptr = *drawn_first;
    Card top_deck = *top_deck_ptr;
    EXPECT_NE(top_deck_ptr, &inserted_card);
    EXPECT_FALSE(top_deck == inserted_card);
    // Check the Top card is now the Inserted Card, as we are at the bottom
    // of deck
    auto drawn_second = test_deck.DrawCard();
    top_deck_ptr = *drawn_second;
    top_deck = *top_deck_ptr;
    EXPECT_EQ(top_deck_ptr, &inserted_card);
    EXPECT_TRUE(top_deck == inserted_card);
}

TEST(DeckTest, Testing_Add_Card_Bottom) {
    Card initial_card_1(Type{HERO, MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    Card inserted_card(Type{HERO, MINOR_HERO}, "test 2", "ABC", "123", GOOD);
    std::deque<Card*> test_card_list = {&initial_card_1};
    Deck test_deck(test_card_list, "test", false);

    test_deck.AddToDeck(&inserted_card, BOTTOM_DECK);

    // Check the Top card is not the Inserted Card
    auto drawn_first = test_deck.DrawCard();
    Card* top_deck_ptr = *drawn_first;
    Card top_deck = *top_deck_ptr;
    EXPECT_NE(top_deck_ptr, &inserted_card);
    EXPECT_FALSE(top_deck == inserted_card);
    // Check the Top card is now the Inserted Card, as we are at the bottom
    // of deck
    auto drawn_second = test_deck.DrawCard();
    top_deck_ptr = *drawn_second;
    top_deck = *top_deck_ptr;
    EXPECT_EQ(top_deck_ptr, &inserted_card);
    EXPECT_TRUE(top_deck == inserted_card);
}

TEST(DeckTest, Testing_Add_Card_Top) {
    Card initial_card_1(Type{HERO, MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    Card inserted_card(Type{HERO, MINOR_HERO}, "test 2", "ABC", "123", GOOD);
    std::deque<Card*> test_card_list = {&initial_card_1};
    Deck test_deck(test_card_list, "test", false);

    test_deck.AddToDeck(&inserted_card, TOP_DECK);

    // Check the Top card is is the Inserted Card
    auto drawn_first = test_deck.DrawCard();
    Card* top_deck_ptr = *drawn_first;
    Card top_deck = *top_deck_ptr;
    EXPECT_EQ(top_deck_ptr, &inserted_card);
    EXPECT_TRUE(top_deck == inserted_card);
    // Check the Top card is not the Inserted Card, as we are at the bottom
    // of deck
    auto drawn_second = test_deck.DrawCard();
    top_deck_ptr = *drawn_second;
    top_deck = *top_deck_ptr;
    EXPECT_NE(top_deck_ptr, &inserted_card);
    EXPECT_FALSE(top_deck == inserted_card);
}

TEST(DeckTest, Testing_Add_Card_Specified_Location) {
    Card initial_card_1(Type{HERO, MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    Card initial_card_2(Type{HERO, MINOR_HERO}, "test 2", "ABC", "123", GOOD);
    Card inserted_card(Type{HERO, MINOR_HERO}, "test 3", "ABC", "123", GOOD);
    std::deque<Card*> test_card_list = {&initial_card_1, &initial_card_2};
    Deck test_deck(test_card_list, "test", false);

    test_deck.AddToDeck(&inserted_card, 1);

    // Check the Top card is not the Inserted Card
    auto drawn_first = test_deck.DrawCard();
    Card* top_deck_ptr = *drawn_first;
    Card top_deck = *top_deck_ptr;
    EXPECT_NE(top_deck_ptr, &inserted_card);
    EXPECT_FALSE(top_deck == inserted_card);
    // Check the Middle card is now the Inserted Card, as we are at the index
    // of deck specified
    auto drawn_second = test_deck.DrawCard();
    top_deck_ptr = *drawn_second;
    top_deck = *top_deck_ptr;
    EXPECT_EQ(top_deck_ptr, &inserted_card);
    EXPECT_TRUE(top_deck == inserted_card);
    // Check Inserted Card is not at the Bottom of the Deck
    auto drawn_third = test_deck.DrawCard();
    top_deck_ptr = *drawn_third;
    top_deck = *top_deck_ptr;
    EXPECT_NE(top_deck_ptr, &inserted_card);
    EXPECT_FALSE(top_deck == inserted_card);
}

TEST(DeckTest, Testing_Add_Card_Throw_Too_High_Index){
    Card initial_card_1(Type{HERO, MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    Card inserted_card(Type{HERO, MINOR_HERO}, "test 2", "ABC", "123", GOOD);
    std::deque<Card*> test_card_list = {&initial_card_1};
    Deck test_deck(test_card_list, "test", false);

    EXPECT_THROW(
        test_deck.AddToDeck(&inserted_card, 100),
        std::invalid_argument
    );
}

TEST(DeckTest, Testing_Add_Card_Throw_Too_Low_Index){
    Card initial_card_1(Type{HERO, MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    Card inserted_card(Type{HERO, MINOR_HERO}, "test 2", "ABC", "123", GOOD);
    std::deque<Card*> test_card_list = {&initial_card_1};
    Deck test_deck(test_card_list, "test", false);

    EXPECT_THROW(
        test_deck.AddToDeck(&inserted_card, -2),
        std::invalid_argument
    );
}

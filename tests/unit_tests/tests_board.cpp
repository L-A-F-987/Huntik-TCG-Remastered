#include <gtest/gtest.h>
#include "Board.h"

TEST(BoardTest,Test_ListCardsInRow_empty_after_initialisation){
    Board board;
    std::vector<Card*> expected_row = {};
    int i = 0;
    do {
        EXPECT_EQ(expected_row,board.ListCardsInRow(i));
        i++;
    } while (i <= 4);
}

TEST(BoardTest,Test_ListCardsInRowByPlayerId){
    Board board;
    Card test_card_1(Type {ACTION,FREE_ACTION}, "test", "", "test_ID_1", GOOD);
    Card test_card_2(Type {ACTION,FREE_ACTION}, "test", "", "test_ID_2", GOOD);

    std::vector<Card*> expected_test_1_cards = {&test_card_1};
    std::vector<Card*> expected_test_2_cards = {&test_card_2};
    board.AddCardToRow(0, &test_card_1);
    board.AddCardToRow(0, &test_card_2);
    EXPECT_EQ(expected_test_1_cards, board.GetCardsInRowByPlayerID(0, "test_ID_1"));
    EXPECT_EQ(expected_test_2_cards, board.GetCardsInRowByPlayerID(0, "test_ID_2"));

}

TEST(BoardTest,Test_AddCardToRow_Succeeds){
    Board board;
    Card test_card(Type {HERO,HERO}, "test", "ABC", "123", GOOD);
    std::vector<Card*> expected_row = {&test_card};
    int i = 0;
    do {
        board.AddCardToRow(i, &test_card);
        EXPECT_EQ(expected_row,board.ListCardsInRow(i));
        i++;
    } while (i <= 4);
}

TEST(BoardTest,Test_RemoveCardFromRow_Succeeds){
    Board board;
    Card test_card(Type {HERO,HERO}, "test", "ABC", "123", GOOD);
    std::vector<Card*> expected_row_before_remove = {&test_card};
    std::vector<Card*> expected_row_after_remove = {};
    int i = 0;
    do {
        board.AddCardToRow(i, &test_card);
        EXPECT_EQ(expected_row_before_remove,board.ListCardsInRow(i));
        board.RemoveCardFromRow(i, &test_card);
        EXPECT_EQ(expected_row_after_remove,board.ListCardsInRow(i));
        i++;
    } while (i <= 4);
}

TEST(BoardTest,Test_RemoveCardFromRow_Throws_Error){
    Board board;
    Card test_card(Type {HERO,HERO}, "test", "ABC", "123", GOOD);
    int test_row = 0;

    EXPECT_THROW(
        board.RemoveCardFromRow(test_row, &test_card),
        std::runtime_error
    );
}
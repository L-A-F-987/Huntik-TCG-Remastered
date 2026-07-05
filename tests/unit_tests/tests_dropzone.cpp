#include <gtest/gtest.h>
#include "DropZone.h"

TEST(DropZoneTest, Test_Add_Card_Succeeds){
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    DropZone test_dropzone;
    EXPECT_NO_THROW(test_dropzone.AddCard(&card_1));
}

TEST(DropZoneTest, Test_Add_Card_Increments_n_Cards_by_1){
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    DropZone test_dropzone;
    int initial_dropzone_size = test_dropzone.GetDropZoneSize();
    test_dropzone.AddCard(&card_1);

    EXPECT_EQ(test_dropzone.GetDropZoneSize(), initial_dropzone_size + 1);
}

TEST(DropZoneTest, Test_Remove_Card_Succeeds){
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    DropZone test_dropzone;
    test_dropzone.AddCard(&card_1);
    EXPECT_NO_THROW(test_dropzone.RemoveCard(&card_1));
}

TEST(DropZoneTest, Test_Remove_Card_Fails_For_Empty_DropZone){
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    DropZone test_dropzone;
    EXPECT_THROW(
        test_dropzone.RemoveCard(&card_1),
        std::runtime_error
    );
}

TEST(DropZoneTest, Test_Remove_Card_Increments_n_Cards_by_1){
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    DropZone test_dropzone;
    test_dropzone.AddCard(&card_1);
    int initial_dropzone_size = test_dropzone.GetDropZoneSize();
    test_dropzone.RemoveCard(&card_1);

    EXPECT_EQ(test_dropzone.GetDropZoneSize(), initial_dropzone_size - 1);
}

TEST(DropZoneTest, Test_ListCurrentCards){
    Card card_1(Type {HERO,MINOR_HERO}, "test 1", "ABC", "123", GOOD);
    DropZone test_dropzone;
    test_dropzone.AddCard(&card_1);
    std::vector<Card*>  expected_cards_in_dropzone = {&card_1};
    EXPECT_EQ(test_dropzone.ListCurrentCards(), expected_cards_in_dropzone);
}

#include <gtest/gtest.h>
#include "Card_Manager.h"

TEST(CardManagerTest,Test_ID_Only_Contains_Valid_Chars){
    CardManager cardmanager;
    std::set<char> valid = {
    'A','B','C','D','E','F','G','H','I','J','K','L','M',
    'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
    '0','1','2','3','4','5','6','7','8','9'
    };

    std::string id = cardmanager.GenerateCardID();
    for (char c : id) {
        EXPECT_TRUE(valid.count(c));
    }
    ;
}

TEST(CardManagerTest,Testing_ID_Length){
    CardManager cardmanager;
    std::string id = cardmanager.GenerateCardID();
    EXPECT_EQ(id.size(), 8);
}

#include <gtest/gtest.h>
#include "Card.h"

TEST(CardTest,Attribute_Movement_inititalisation){
    Card c;
    EXPECT_EQ(c.Attrabute.Movement_Speed,2);
};


TEST(CardTest,Conditions_Unblockable_inititalisation){
    Card c;
    EXPECT_FALSE(c.Condition.Unblockable);
};

TEST(CardTest,Conditions_ready_inititalisation){
    Card c;
    EXPECT_TRUE(c.Condition.Ready);
};


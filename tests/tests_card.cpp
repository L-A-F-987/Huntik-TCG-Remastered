
#include <gtest/gtest.h>
#include "Card.h"


//Attrabute inititalisations
TEST(CardTest,Attribute_Movement_inititalisation){
    Attributes a;
    EXPECT_EQ(a.Movement_Speed,2);
};

//Condition inititalisations
TEST(CardTest,Conditions_Unblockable_inititalisation){
    Conditions c;
    EXPECT_FALSE(c.Unblockable);
};

TEST(CardTest,Conditions_ready_inititalisation){
    Conditions c;
    EXPECT_TRUE(c.Ready);
};

//Setting Functions
TEST(CardTest,Setting_Attrabutes){
    Card C;
    int attack = 4;
    int defence = 2;
    int movement_speed = 3;
    C.fill_attributes(attack,defence,movement_speed);
    EXPECT_EQ(C.Attrabute.Attack,attack);
    EXPECT_EQ(C.Attrabute.Defence,defence);
    EXPECT_EQ(C.Attrabute.Movement_Speed,movement_speed);
    
    C.fill_attributes(attack,defence);
    EXPECT_EQ(C.Attrabute.Attack,attack);
    EXPECT_EQ(C.Attrabute.Defence,defence);
    EXPECT_EQ(C.Attrabute.Movement_Speed,Default_Speed);
}


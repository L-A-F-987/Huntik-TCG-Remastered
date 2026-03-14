
#include <gtest/gtest.h>
#include "Card.h"


//Testing all type default constructors
TEST(CardTest,Testing_Constructor_MINOR_HERO){

    Card C(HERO, MINOR_HERO, "test");
    EXPECT_EQ(C.low_level_type,MINOR_HERO);

};

TEST(CardTest,Testing_Constructor_MAJOR_HERO){

    Card C(HERO, MAJOR_HERO, "test");
    EXPECT_EQ(C.low_level_type,MAJOR_HERO);

};

TEST(CardTest,Testing_Constructor_ACTION_Hero){

    Card C(ACTION,EXHAUST_ACTION, "test");
    EXPECT_EQ(C.low_level_type,EXHAUST_ACTION);

};

//Testing Name Setting
TEST(CardTest,Testing_Name_Constructor_MINOR_HERO){

    Card C(HERO, MINOR_HERO, "Test Name");
    EXPECT_EQ(C.get_name(),"Test Name");

};

TEST(CardTest,Testing_Name_Constructor_MAJOR_HERO){

    Card C(HERO,MAJOR_HERO, "Test Name");
    EXPECT_EQ(C.get_name(),"Test Name");

};

TEST(CardTest,Testing_Name_Constructor_ACTION){

    Card C(ACTION, EXHAUST_ACTION, "Test Name");
    EXPECT_EQ(C.get_name(),"Test Name");

};

//Testing Default Attack and Defence Major and Minor

TEST(CardTest,Testing_Default_Attack_Defence_MINOR_HERO){

    Card C(HERO,MINOR_HERO, "test");
    EXPECT_EQ(C.get_attack(),0);
    EXPECT_EQ(C.get_defence(),0);

};

TEST(CardTest,Testing_Constructor_Attack_Defence_MAJOR_HERO){

    Card C(HERO,MAJOR_HERO, "test");
    EXPECT_EQ(C.get_attack(),0);
    EXPECT_EQ(C.get_defence(),0);

};

//Testing Setting Attack and Defence

TEST(CardTest,Testing_Constructor_Setting_Attack_Defence_MAJOR_HERO){

    Card C(HERO,MAJOR_HERO,"test",5,4);
    EXPECT_EQ(C.get_attack(),5);
    EXPECT_EQ(C.get_defence(),4);

};

TEST(CardTest,Testing_Constructor_Setting_Attack_Defence_MINOR_HERO){

    Card C(HERO,MINOR_HERO,"test",5,4);
    EXPECT_EQ(C.get_attack(),5);
    EXPECT_EQ(C.get_defence(),4);

};




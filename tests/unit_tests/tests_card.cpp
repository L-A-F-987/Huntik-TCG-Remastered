
#include <gtest/gtest.h>
#include "Card.h"


//Testing all primary type default constructors

TEST(CardTest,Testing_Constructor_HERO){

    Card C(Type {HERO,MINOR_HERO}, "test",GOOD);
    EXPECT_EQ(C.type.primary_type,MINOR_HERO);

};

TEST(CardTest,Testing_Constructor_ACTION){

    Card C(Type {ACTION,FREE_ACTION}, "test",GOOD);
    EXPECT_EQ(C.type.primary_type,ACTION);

};

// Hero sub_type declaration tests
TEST(CardTest,Testing_Constructor_MINOR_HERO){

    Card C(Type {HERO,MINOR_HERO}, "test",GOOD);
    EXPECT_EQ(C.type.sub_type,MINOR_HERO);

};

TEST(CardTest,Testing_Constructor_MAJOR_HERO){

    Card C(Type {HERO, MAJOR_HERO}, "test",GOOD);
    EXPECT_EQ(C.type.sub_type,MAJOR_HERO);

};

// Action sub_type declaration tests
TEST(CardTest,Testing_Constructor_EXHAUST_ACTION){

    Card C(Type{ACTION,EXHAUST_ACTION}, "test",GOOD);
    EXPECT_EQ(C.type.sub_type,EXHAUST_ACTION);

};

TEST(CardTest,Testing_Constructor_FREE_ACTION){

    Card C(Type{ACTION,FREE_ACTION}, "test", GOOD);
    EXPECT_EQ(C.type.sub_type,FREE_ACTION);

};

TEST(CardTest,Testing_Constructor_COMBAT_ACTION){

    Card C(Type{ACTION,COMBAT_ACTION}, "test",GOOD);
    EXPECT_EQ(C.type.sub_type,COMBAT_ACTION);

};

//Testing Name Setting
TEST(CardTest,Testing_Name_Constructor_MINOR_HERO){

    Card C(Type{HERO, MINOR_HERO}, "Test Name",GOOD);
    EXPECT_EQ(C.get_name(),"Test Name");

};

TEST(CardTest,Testing_Name_Constructor_MAJOR_HERO){

    Card C(Type{HERO,MAJOR_HERO}, "Test Name",GOOD);
    EXPECT_EQ(C.get_name(),"Test Name");

};

TEST(CardTest,Testing_Name_Constructor_ACTION){

    Card C(Type{ACTION, EXHAUST_ACTION}, "Test Name",GOOD);
    EXPECT_EQ(C.get_name(),"Test Name");

};

//Testing Default Attack and Defence Major and Minor

TEST(CardTest,Testing_Default_Attack_Defence_MINOR_HERO){

    Card C(Type{HERO,MINOR_HERO}, "test",GOOD);
    EXPECT_EQ(C.get_attack(),0);
    EXPECT_EQ(C.get_defence(),0);

};

TEST(CardTest,Testing_Constructor_Attack_Defence_MAJOR_HERO){

    Card C(Type{HERO,MAJOR_HERO}, "test",GOOD);
    EXPECT_EQ(C.get_attack(),0);
    EXPECT_EQ(C.get_defence(),0);

};

//Testing Setting Attack and Defence

TEST(CardTest,Testing_Constructor_Setting_Attack_Defence_MAJOR_HERO){

    Card C(Type{HERO,MAJOR_HERO},"test",GOOD ,5,4);
    EXPECT_EQ(C.get_attack(),5);
    EXPECT_EQ(C.get_defence(),4);

};

TEST(CardTest,Testing_Constructor_Setting_Attack_Defence_MINOR_HERO){

    Card C(Type{HERO,MINOR_HERO},"test",GOOD ,5,4);
    EXPECT_EQ(C.get_attack(),5);
    EXPECT_EQ(C.get_defence(),4);

};




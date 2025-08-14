
#include <gtest/gtest.h>
#include "Card.h"


//Testing all type default constructors
TEST(CardTest,Testing_Constructor_Minor_Hero){
    
    Card C(Minor_Hero, "test");
    EXPECT_EQ(C.type,Minor_Hero);
    
};

TEST(CardTest,Testing_Constructor_Major_Hero){
    
    Card C(Major_Hero, "test");
    EXPECT_EQ(C.type,Major_Hero);
    
};

TEST(CardTest,Testing_Constructor_Action_Hero){
    
    Card C(Action, "test");
    EXPECT_EQ(C.type,Action);
    
};

//Testing Name Setting 
TEST(CardTest,Testing_Name_Constructor_Minor_Hero){
    
    Card C(Minor_Hero, "Test Name");
    EXPECT_EQ(C.get_name(),"Test Name");
    
};

TEST(CardTest,Testing_Name_Constructor_Major_Hero){
    
    Card C(Major_Hero, "Test Name");
    EXPECT_EQ(C.get_name(),"Test Name");
    
};

TEST(CardTest,Testing_Name_Constructor_Action){
    
    Card C(Action, "Test Name");
    EXPECT_EQ(C.get_name(),"Test Name");
    
};

//Testing Default Attack and Defence Major and Minor

TEST(CardTest,Testing_Default_Attack_Defence_Minor_Hero){
    
    Card C(Minor_Hero, "test");
    EXPECT_EQ(C.get_attack(),0);
    EXPECT_EQ(C.get_defence(),0);
    
};

TEST(CardTest,Testing_Constructor_Attack_Defence_Major_Hero){
    
    Card C(Major_Hero, "test");
    EXPECT_EQ(C.get_attack(),0);
    EXPECT_EQ(C.get_defence(),0);
    
};

//Testing Setting Attack and Defence

TEST(CardTest,Testing_Constructor_Setting_Attack_Defence_Major_Hero){
    
    Card C(Major_Hero,"test",5,4);
    EXPECT_EQ(C.get_attack(),5);
    EXPECT_EQ(C.get_defence(),4);
    
};

TEST(CardTest,Testing_Constructor_Setting_Attack_Defence_Minor_Hero){
    
    Card C(Minor_Hero,"test",5,4);
    EXPECT_EQ(C.get_attack(),5);
    EXPECT_EQ(C.get_defence(),4);
    
};




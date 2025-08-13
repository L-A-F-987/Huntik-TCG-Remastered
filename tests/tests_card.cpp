
#include <gtest/gtest.h>
#include "Card.h"


//Testing all type default constructors
TEST(CardTest,Testing_Constructor_Minor_Hero){
    
    Card C(Minor_Hero);
    EXPECT_EQ(C.type,Minor_Hero);
    
};

TEST(CardTest,Testing_Constructor_Major_Hero){
    
    Card C(Major_Hero);
    EXPECT_EQ(C.type,Major_Hero);
    
};

TEST(CardTest,Testing_Constructor_Exhaust_Action){
    
    Card C(Exhaust_Action);
    EXPECT_EQ(C.type,Exhaust_Action);
    
};

TEST(CardTest,Testing_Constructor_Free_Action){
    
    Card C(Free_Action);
    EXPECT_EQ(C.type,Free_Action);
    
};

TEST(CardTest,Testing_Constructor_Combat_Action){
    
    Card C(Combat_Action);
    EXPECT_EQ(C.type,Combat_Action);
    
};

//Testing Default Attack and Defence Major and Minor

TEST(CardTest,Testing_Default_Attack_Defence_Minor_Hero){
    
    Card C(Minor_Hero);
    EXPECT_EQ(C.get_attack(),0);
    EXPECT_EQ(C.get_defence(),0);
    
};

TEST(CardTest,Testing_Constructor_Attack_Defence_Major_Hero){
    
    Card C(Major_Hero);
    EXPECT_EQ(C.get_attack(),0);
    EXPECT_EQ(C.get_defence(),0);
    
};




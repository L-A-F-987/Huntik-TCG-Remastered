#include(AddGoogleTest)
FetchContent_MakeAvailable(googletest)

add_executable(tests_card tests_card.cpp)

target_link_libraries(tests_card
    PRIVATE
    LIB_Card
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests_card)

add_executable(tests_deck tests_deck.cpp)

target_link_libraries(tests_deck
    PRIVATE
    LIB_Deck
    GTest::gtest_main
)

gtest_discover_tests(tests_deck)

add_executable(tests_card_manager tests_card_manager.cpp)

target_link_libraries(tests_card_manager
    PRIVATE
    LIB_Card_Manager
    GTest::gtest_main
)
gtest_discover_tests(tests_card_manager)


add_executable(tests_hand tests_hand.cpp)

target_link_libraries(tests_hand
    PRIVATE
    LIB_Hand
    GTest::gtest_main
)
gtest_discover_tests(tests_hand)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
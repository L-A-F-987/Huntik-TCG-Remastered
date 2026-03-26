#include(AddGoogleTest)

add_executable(tests_card tests_card.cpp)

target_link_libraries(tests_card
    PRIVATE
    LIB_Card
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests_card)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
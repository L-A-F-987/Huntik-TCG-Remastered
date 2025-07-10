add_executable(tests_card tests_card.cpp)

target_link_libraries(tests_card
    PRIVATE
    LIB_Card
)
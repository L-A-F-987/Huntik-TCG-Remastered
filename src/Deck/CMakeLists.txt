add_library(LIB_Deck
  SHARED
  Deck.cpp
)

target_include_directories(LIB_Deck
    PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
)

target_link_libraries(LIB_Deck
    PUBLIC
    LIB_Card
)


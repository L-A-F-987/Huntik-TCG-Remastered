add_library(LIB_Game
  SHARED
  Game.cpp
)

target_include_directories(LIB_Game
    PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
)

target_link_libraries(LIB_Game
    PUBLIC
    LIB_Deck
    LIB_Card_Manager
)
add_library(LIB_Player
  SHARED
  Player.cpp
)

target_include_directories(LIB_Player
    PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
)


target_link_libraries(LIB_Player
    PUBLIC
    LIB_Deck
    LIB_Hand

)

add_library(LIB_Player
  SHARED
  Player.cpp
)

target_include_directories(LIB_Player
    PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
)


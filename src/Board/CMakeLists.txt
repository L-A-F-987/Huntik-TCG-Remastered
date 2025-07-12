add_library(LIB_Board
  SHARED
  Board.cpp
)

target_link_libraries(LIB_Board PRIVATE LIB_Card)

target_include_directories(LIB_Board
    PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
)



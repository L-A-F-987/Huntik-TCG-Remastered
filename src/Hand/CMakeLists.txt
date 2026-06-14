add_library(LIB_Hand
  SHARED
  Hand.cpp
)

target_include_directories(LIB_Hand
    PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
)

target_link_libraries(LIB_Hand
    PUBLIC
    LIB_Card
)


add_library(LIB_Hand
  SHARED
  Hand.cpp
)

target_include_directories(LIB_Hand
    PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
)


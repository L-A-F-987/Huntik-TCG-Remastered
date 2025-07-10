add_library(LIB_Card
  SHARED
  Card.cpp
)

target_include_directories(LIB_Card
    PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
)


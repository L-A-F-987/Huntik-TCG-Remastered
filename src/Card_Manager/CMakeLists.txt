add_library(LIB_Card_Manager
  SHARED
  Card_Manager.cpp
)

target_include_directories(LIB_Card_Manager
    PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
)


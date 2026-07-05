add_library(LIB_DropZone
  SHARED
  DropZone.cpp
)

target_include_directories(LIB_DropZone
    PUBLIC
    "${PROJECT_SOURCE_DIR}/src/include"
)

target_link_libraries(LIB_DropZone
    PUBLIC
    LIB_Card
)


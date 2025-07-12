
cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED On)


project(Huntik_Remastered VERSION 1.0.0 LANGUAGES CXX)

##compile options to check the code 
add_compile_options(-Wall -Wconversion -Wextra -pedantic)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.17.0 # release-1.17.0
)

add_subdirectory(${CMAKE_SOURCE_DIR}/src/Card)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Board)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/demo)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Hand)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Player)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/Deck)
add_subdirectory(${CMAKE_SOURCE_DIR}/tests)


cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 14)


project(Huntik_Remastered VERSION 1.0.0 LANGUAGES CXX)


add_subdirectory(${CMAKE_SOURCE_DIR}/src/Card)
add_subdirectory(${CMAKE_SOURCE_DIR}/src/demo)

enable_testing()

##compile options to check the code 
add_compile_options(-Wall -Wconversion -Wextra -pedantic)
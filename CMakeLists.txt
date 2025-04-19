cmake_minimum_required(VERSION 3.10)
project(between_the_trees)

set(SOURCE_FILES ${PROJECT_SOURCE_DIR})
add_executable(between_the_trees ${SOURCE_FILES})
target_include_directories(between_the_trees PUBLIC ${PROJECT_BINARY_DIR})


cmake_minimum_required(VERSION 3.14)

project(chat)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_LIST_DIR}/source/*)
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${sources})

add_executable(chat ${sources})
target_link_libraries(chat chatlib)

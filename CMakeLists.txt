cmake_minimum_required(VERSION 3.28...4.5)

project(chatlib LANGUAGES CXX)

file(GLOB_RECURSE bridge_headers CONFIGURE_DEPENDS "source/*.h")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "source/*")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${sources})

find_package(Scapix REQUIRED)

scapix_add_target(chatlib "com.example.chat" ${bridge_headers})
target_sources(chatlib PRIVATE ${sources})
target_include_directories(chatlib PUBLIC "source")

if(EXISTS "ui/${SCAPIX_BRIDGE}/CMakeLists.txt")
  add_subdirectory("ui/${SCAPIX_BRIDGE}")
endif()

cmake_minimum_required(VERSION 3.20...3.27)

project(chatlib)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v2.0.1.tar.gz"
  URL_HASH SHA256=a9477bbefb43b6fabdc2dc044207fe42cca63999c60b6baf06ba0c62fa116ec5
)
FetchContent_MakeAvailable(cmodule)

file(GLOB_RECURSE bridge_headers CONFIGURE_DEPENDS "source/*.h")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "source/*")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/source" PREFIX "source" FILES ${sources})

find_package(Scapix REQUIRED)

scapix_add_target(chatlib "com.example.chat" ${bridge_headers})
target_sources(chatlib PRIVATE ${sources})
target_include_directories(chatlib PUBLIC source)

if(EXISTS "ui/${SCAPIX_BRIDGE}/CMakeLists.txt")
  add_subdirectory("ui/${SCAPIX_BRIDGE}")
endif()

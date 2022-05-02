cmake_minimum_required(VERSION 3.14)

project(chatlib)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v1.0.33.tar.gz"
  URL_HASH SHA256=b56bf2f3b5acb979f1242757976eaf525caeea70714caa6e19571f65e0b60727
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

cmake_minimum_required(VERSION 3.20...3.27)

project(chatlib)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL https://github.com/scapix-com/cmodule/archive/refs/tags/v2.5.0.tar.gz
  URL_HASH SHA256=0b5cfb0d88e8a9b7801b8c423d6713785ddce65692f35d9081a56695a6cfaaea
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

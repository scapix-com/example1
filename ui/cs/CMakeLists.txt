cmake_minimum_required(VERSION 3.14)

project(chat CXX CSharp)

string(REGEX REPLACE " /langversion:[0-9]" "" CMAKE_CSharp_FLAGS ${CMAKE_CSharp_FLAGS})
set(CMAKE_CSharp_FLAGS "${CMAKE_CSharp_FLAGS} /langversion:7.3")
set(CMAKE_CSharp_FLAGS_RELEASE "${CMAKE_CSharp_FLAGS_RELEASE} /define:NDEBUG")

file(GLOB_RECURSE sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_LIST_DIR}/source/*)
source_group(TREE ${CMAKE_CURRENT_LIST_DIR}/source FILES ${sources})

add_executable(chat ${sources})

set_target_properties(chat PROPERTIES
  VS_DOTNET_REFERENCES "System;System.Windows.Forms;System.Data;System.Drawing;"
  VS_DOTNET_TARGET_FRAMEWORK_VERSION 4.7.2
)

target_link_libraries(chat PRIVATE chatlib)
scapix_fix_sources(chatlib)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT chat)

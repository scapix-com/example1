cmake_minimum_required(VERSION 3.14)

project(chatlib CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON) # not required, but speeds up compilation of SCAPIX_META_STRING with clang and gcc

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/v1.0.13.tar.gz"
  URL_HASH SHA256=0dd63350e809f3be736a62f33f89f92ac0780a0f051e5fb90ae5a3bf51070b48
)
FetchContent_MakeAvailable(cmodule)

set(SCAPIX_BRIDGE "java" CACHE STRING "cpp, java, objc, python, js, cs")
set(SCAPIX_PLATFORM "windows" CACHE STRING "one of the folders inside 'source/chat/platform': ios, android, macos, windows, linux, etc.")
set(SCAPIX_JAVA_API "android-28" CACHE STRING "one of the folders inside 'scapix/java_api': jdk-11.0.2, android-28, etc.")

find_package(Scapix REQUIRED)

scapix_add_target(
    chatlib
    "com.example.chat"
    "source/chat/contact.h"
    "source/chat/session.h"
    "source/chat/model.h"
    "source/chat/extended_contact.h"
    "source/chat/folder/abstruct_element.h"
    "source/chat/folder/element.h"
)

# demonstrate use of (optional) platform-dependent sources
file(GLOB_RECURSE chat_sources CONFIGURE_DEPENDS "source/chat/*")
list(FILTER chat_sources EXCLUDE REGEX "source/chat/platform/*")
file(GLOB_RECURSE platforms_sources CONFIGURE_DEPENDS "source/chat/platform/*")
list(FILTER platforms_sources EXCLUDE REGEX "source/chat/platform/${SCAPIX_PLATFORM}/*")
set_source_files_properties(${platforms_sources} PROPERTIES HEADER_FILE_ONLY TRUE)
file(GLOB_RECURSE platform_sources CONFIGURE_DEPENDS "source/chat/platform/${SCAPIX_PLATFORM}/*")
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}/source/chat" PREFIX "source" FILES ${chat_sources} ${platforms_sources} ${platform_sources})

target_sources(chatlib PRIVATE ${chat_sources} ${platforms_sources} ${platform_sources})
target_include_directories(chatlib PRIVATE source)

if(EXISTS "ui/${SCAPIX_BRIDGE}/CMakeLists.txt")
  add_subdirectory("ui/${SCAPIX_BRIDGE}")
endif()

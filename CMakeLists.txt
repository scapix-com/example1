cmake_minimum_required(VERSION 3.14)

project(chatlib CXX)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/v1.0.29.tar.gz"
  URL_HASH SHA256=b49019b355423aebacd927e99541b146c900ef416ae1da6a8343a2a274dd4876
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
target_include_directories(chatlib PUBLIC source)

if(EXISTS "ui/${SCAPIX_BRIDGE}/CMakeLists.txt")
  add_subdirectory("ui/${SCAPIX_BRIDGE}")
endif()

cmake_minimum_required(VERSION 3.14)

project(chatlib CXX)

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/refs/tags/v1.0.32.tar.gz"
  URL_HASH SHA256=e6937c95d73188a5add846b27cd00160fe4f6ea31af33be417d2ab7ac19bd8d2
)
FetchContent_MakeAvailable(cmodule)

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

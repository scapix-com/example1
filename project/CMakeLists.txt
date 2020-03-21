cmake_minimum_required(VERSION 3.14)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)
get_filename_component(PROJECT_ROOT ${PROJECT_ROOT} ABSOLUTE)

project(chatlib CXX)

set(CMODULE_CACHE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build/.cmodule CACHE PATH "")

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL "https://github.com/scapix-com/cmodule/archive/v1.0.4.tar.gz"
  URL_HASH SHA256=89171634a367cb580860c3cc2adbc93dda7c59fdcd03b2b8c92cc783eb5c5c92
)
FetchContent_MakeAvailable(cmodule)

set(SCAPIX_BRIDGE "java" CACHE STRING "cpp, java, objc, python")
set(SCAPIX_PLATFORM "windows" CACHE STRING "one of the folders inside 'source/chat/platform': ios, android, macos, windows, linux, etc.")
set(SCAPIX_JAVA_API "android-28" CACHE STRING "one of the folders inside 'scapix/java_api': jdk-11.0.2, android-28, etc.")

file(GLOB_RECURSE chat_sources CONFIGURE_DEPENDS ${PROJECT_ROOT}/source/chat/*.*)
list(FILTER chat_sources EXCLUDE REGEX "${PROJECT_ROOT}/source/chat/platform/*")
file(GLOB_RECURSE platforms_sources CONFIGURE_DEPENDS ${PROJECT_ROOT}/source/chat/platform/*.*)
list(FILTER platforms_sources EXCLUDE REGEX "${PROJECT_ROOT}/source/chat/platform/${SCAPIX_PLATFORM}/*")
set_source_files_properties(${platforms_sources} PROPERTIES HEADER_FILE_ONLY TRUE)
file(GLOB_RECURSE platform_sources CONFIGURE_DEPENDS ${PROJECT_ROOT}/source/chat/platform/${SCAPIX_PLATFORM}/*.*)
source_group(TREE ${PROJECT_ROOT}/source/chat PREFIX "source" FILES ${chat_sources} ${platforms_sources} ${platform_sources})

if(EMSCRIPTEN)
    add_executable(chatlib ${chat_sources} ${platforms_sources} ${platform_sources})
    target_link_options(chatlib PRIVATE --bind)
#   target_link_options(chatlib PRIVATE --emrun)
else()
    if(${SCAPIX_BRIDGE} STREQUAL java OR ${SCAPIX_BRIDGE} STREQUAL python)
        set(LIBRARY_TYPE MODULE)
        set(CMAKE_POSITION_INDEPENDENT_CODE ON)
    endif()
    add_library(chatlib ${LIBRARY_TYPE} ${chat_sources} ${platforms_sources} ${platform_sources})
endif()

find_package(Scapix REQUIRED)

scapix_bridge_headers(
    chatlib
    "com.scapix.chat"
    "${PROJECT_ROOT}/source/chat/contact.h"
    "${PROJECT_ROOT}/source/chat/session.h"
    "${PROJECT_ROOT}/source/chat/model.h"
    "${PROJECT_ROOT}/source/chat/extended_contact.h"
    "${PROJECT_ROOT}/source/chat/folder/abstruct_element.h"
    "${PROJECT_ROOT}/source/chat/folder/element.h"
)

# JVM on macOS looks for native libs with .dylib extension
if(APPLE AND ${SCAPIX_BRIDGE} STREQUAL java)
    set_target_properties(chatlib PROPERTIES SUFFIX ".dylib")
endif()

if(IOS)
    set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
endif()

set_target_properties(chatlib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON # not required, but speeds up compilation of SCAPIX_META_STRING with clang and gcc
)

target_include_directories(chatlib PRIVATE ${PROJECT_ROOT}/source)

find_package(Boost REQUIRED)
target_link_libraries(chatlib PUBLIC Boost::headers)

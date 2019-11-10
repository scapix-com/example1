cmake_minimum_required(VERSION 3.14)

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)
get_filename_component(PROJECT_ROOT ${PROJECT_ROOT} ABSOLUTE)

set(SCAPIX_ROOT ${PROJECT_ROOT}/../scapix CACHE STRING "scapix lib path")
get_filename_component(SCAPIX_ROOT ${SCAPIX_ROOT} ABSOLUTE)

if("$ENV{HUNTER_ROOT}" STREQUAL "")
    set(HUNTER_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/build/.hunter")
endif()

include("${SCAPIX_ROOT}/project/cmake/modules/HunterGate.cmake")

HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.214.tar.gz"
    SHA1 "e14bc153a7f16d6a5eeec845fb0283c8fad8c358"
)

project(chatlib CXX)

# hunter complains
if(EMSCRIPTEN)
    set(CMAKE_C_ABI_COMPILED TRUE)
    set(CMAKE_CXX_ABI_COMPILED TRUE)
endif()

set(SCAPIX_BRIDGE "java" CACHE STRING "cpp, java, objc, python")
set(SCAPIX_PLATFORM "windows" CACHE STRING "one of the folders inside 'source/chat/platform': ios, android, macos, windows, linux, etc.")
set(SCAPIX_JAVA_API "android-28" CACHE STRING "one of the folders inside 'scapix/java_api': jdk-11.0.2, android-28, etc.")

# chat_sources

file(GLOB_RECURSE chat_sources CONFIGURE_DEPENDS
	${PROJECT_ROOT}/source/chat/*.*
)

list(FILTER chat_sources EXCLUDE REGEX "${PROJECT_ROOT}/source/chat/platform/*")

# platforms_sources

file(GLOB_RECURSE platforms_sources CONFIGURE_DEPENDS
	${PROJECT_ROOT}/source/chat/platform/*.*
)

list(FILTER platforms_sources EXCLUDE REGEX "${PROJECT_ROOT}/source/chat/platform/${SCAPIX_PLATFORM}/*")

set_source_files_properties(${platforms_sources} PROPERTIES HEADER_FILE_ONLY TRUE)

# platform_sources

file(GLOB_RECURSE platform_sources CONFIGURE_DEPENDS
	${PROJECT_ROOT}/source/chat/platform/${SCAPIX_PLATFORM}/*.*
)

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

# https://github.com/ruslo/hunter/issues/542
set_target_properties(chatlib PROPERTIES DEBUG_POSTFIX "")

# JVM on MacOS looks for native libs with .dylib extension
if(APPLE AND ${SCAPIX_BRIDGE} STREQUAL java)
    set_target_properties(chatlib PROPERTIES SUFFIX ".dylib")
endif()

source_group(TREE ${PROJECT_ROOT}/source/chat PREFIX "source" FILES ${chat_sources} ${platforms_sources} ${platform_sources})

set_target_properties(chatlib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON # not required, but speeds up compilation of SCAPIX_META_STRING with clang and gcc
)

target_include_directories(chatlib PRIVATE ${PROJECT_ROOT}/source)

# Add third party libraries (https://www.scapix.com/documentation/cmake/dependencies/).

hunter_add_package(Boost)
find_package(Boost REQUIRED)
target_link_libraries(chatlib PUBLIC Boost::boost)

# Call scapix_bridge_headers() after all calls to target_include_directories() and target_link_libraries().

include(${SCAPIX_ROOT}/project/cmake/modules/scapix.cmake)

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

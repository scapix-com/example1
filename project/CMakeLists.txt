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
    URL "https://github.com/ruslo/hunter/archive/v0.23.171.tar.gz"
    SHA1 "5d68bcca78eee347239ca5f4d34f4b6c12683154"
)

project(chatlib CXX)

set(SCAPIX_BRIDGE "java" CACHE STRING "cpp, java, objc, python")
set(SCAPIX_PLATFORM "windows" CACHE STRING "one of the folders inside 'source/chat/platform': ios, android, macos, windows, linux, etc.")
set(SCAPIX_JAVA_API "android-28" CACHE STRING "one of the folders inside 'scapix/java_api': jdk-11.0.2, android-28, etc.")

include(${SCAPIX_ROOT}/project/cmake/modules/scapix.cmake)

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

if(${SCAPIX_BRIDGE} STREQUAL java OR ${SCAPIX_BRIDGE} STREQUAL python)
    set(LIBRARY_TYPE MODULE)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

add_library(chatlib ${LIBRARY_TYPE} ${chat_sources} ${platforms_sources} ${platform_sources})

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

# Add third party libraries here.
# Boost header-only libraries already added by scapix lib.

#hunter_add_package(Boost)
#find_package(Boost REQUIRED)
#target_link_libraries(chatlib PUBLIC Boost::boost)

# call scapix_bridge_headers() after all target_include_directories and target_link_libraries
add_subdirectory(${SCAPIX_ROOT}/project/cmake ${PROJECT_BINARY_DIR}/scapix)

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

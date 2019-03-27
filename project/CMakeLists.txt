cmake_minimum_required(VERSION 3.12)

project(chatlib)

set(scapix_bridge "java" CACHE STRING "cpp, java, objc, python")
set(scapix_platform "windows" CACHE STRING "one of the folders inside 'source/chat/platform': ios, android, macos, windows, linux, etc.")
set(scapix_java_api "android-28" CACHE STRING "one of the folders inside 'scapix/java_api': jdk-11.0.2, android-28, etc.")

set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/..)
get_filename_component(PROJECT_ROOT ${PROJECT_ROOT} ABSOLUTE)

set(SCAPIX_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../scapix)
get_filename_component(SCAPIX_ROOT ${SCAPIX_ROOT} ABSOLUTE)

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

list(FILTER platforms_sources EXCLUDE REGEX "${PROJECT_ROOT}/source/chat/platform/${scapix_platform}/*")

set_source_files_properties(${platforms_sources} PROPERTIES HEADER_FILE_ONLY TRUE)

# platform_sources

file(GLOB_RECURSE platform_sources CONFIGURE_DEPENDS
	${PROJECT_ROOT}/source/chat/platform/${scapix_platform}/*.*
)

if(${scapix_bridge} STREQUAL java OR ${scapix_bridge} STREQUAL python)
   set(LIBRARY_TYPE MODULE)
endif()

add_library(chatlib ${LIBRARY_TYPE} ${chat_sources} ${platforms_sources} ${platform_sources})

source_group(TREE ${PROJECT_ROOT}/source/chat PREFIX "source" FILES ${chat_sources} ${platforms_sources} ${platform_sources})

set_target_properties(chatlib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON # not required, but speeds up compilation of SCAPIX_META_STRING with clang and gcc
)

target_include_directories(chatlib PRIVATE ${PROJECT_ROOT}/source)
target_compile_definitions(chatlib PUBLIC SCAPIX_BRIDGE=${scapix_bridge} SCAPIX_PLATFORM=${scapix_platform})

add_subdirectory(${SCAPIX_ROOT}/project/cmake ${PROJECT_BINARY_DIR}/scapix)
target_link_libraries(chatlib PUBLIC scapix)

# allows to use host boost headers for android
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.67 REQUIRED)
target_include_directories(chatlib PUBLIC ${Boost_INCLUDE_DIRS})

# call after target_include_directories and target_link_libraries

scapix_bridge_headers(
    chatlib
    "com.scapix.chat"
    "${PROJECT_ROOT}/source/chat/contact.h"
    "${PROJECT_ROOT}/source/chat/session.h"
    "${PROJECT_ROOT}/source/chat/model.h"
)

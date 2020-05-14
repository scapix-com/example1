cmake_minimum_required(VERSION 3.14)

project(chat)

find_package(Java COMPONENTS Development)
include(UseJava)

scapix_fix_sources(chatlib)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS "*.java")
get_target_property(generated_sources chatlib INTERFACE_SOURCES)
get_target_property(scapix_sources scapix INTERFACE_SOURCES)

add_jar(chat
  SOURCES
    ${sources}
    ${generated_sources}
    ${scapix_sources}
  ENTRY_POINT
    com/example/chat/Chat
)

add_dependencies(chat chatlib)

add_custom_target(run ALL
  COMMAND ${Java_JAVA_EXECUTABLE} -cp "${CMAKE_CURRENT_BINARY_DIR}" -Djava.library.path="$<TARGET_FILE_DIR:chatlib>" -jar chat.jar
)

add_dependencies(run chat)

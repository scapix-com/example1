cmake_minimum_required(VERSION 3.14)

project(chat)

find_package(Java COMPONENTS Development)
include(UseJava)

scapix_fix_sources(chatlib)
get_target_property(generated_sources chatlib INTERFACE_SOURCES)

add_jar(chat
  SOURCES
    "com/scapix/chat/Chat.java"
    "../../generated/bridge/java/com/scapix/Bridge.java"
    "../../generated/bridge/java/com/scapix/NativeException.java"
    ${generated_sources}
  ENTRY_POINT
    com/scapix/chat/Chat
)

add_dependencies(chat chatlib)

add_custom_target(run ALL
  COMMAND ${Java_JAVA_EXECUTABLE} -cp "${CMAKE_CURRENT_BINARY_DIR}" -Djava.library.path="$<TARGET_FILE_DIR:chatlib>" -jar chat.jar
)

add_dependencies(run chat)

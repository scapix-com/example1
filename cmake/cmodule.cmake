# cmodule 3.0.1: builds dependencies from source as part of the build.
# https://www.scapix.com/cmodule
#
# Load via CMAKE_PROJECT_TOP_LEVEL_INCLUDES (e.g. in CMakePresets.json), or:
#   cmake -B build -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=cmake/cmodule.cmake
#
# Upgrade to the latest release:
#   curl -L -o cmake/cmodule.cmake https://github.com/scapix-com/cmodule/releases/latest/download/cmodule.cmake

include(FetchContent)
FetchContent_Declare(
  cmodule
  URL https://github.com/scapix-com/cmodule/releases/download/v3.0.1/cmodule-3.0.1.tar.gz
  URL_HASH SHA256=9a855e4d36f069fbf7568b2a0958f04558d6111908d4378d3b61b4ff0690a6ce
)
FetchContent_MakeAvailable(cmodule)

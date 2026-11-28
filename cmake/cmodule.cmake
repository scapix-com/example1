# cmodule 3.0.6: builds dependencies from source as part of the build.
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
  URL https://github.com/scapix-com/cmodule/releases/download/v3.0.6/cmodule-3.0.6.tar.gz
  URL_HASH SHA256=c297bcabaaa18e981294c15e8d5a7a9f1d62db67f2122cd93e7c2629e9af6487
)
FetchContent_MakeAvailable(cmodule)

# cmodule 3.0.4: builds dependencies from source as part of the build.
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
  URL https://github.com/scapix-com/cmodule/releases/download/v3.0.4/cmodule-3.0.4.tar.gz
  URL_HASH SHA256=9fbb109542d2f6581a9cdddd715790eeed09f85ca52ff224884738dd6c44d765
)
FetchContent_MakeAvailable(cmodule)

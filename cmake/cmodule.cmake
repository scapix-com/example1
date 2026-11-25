# cmodule 3.0.5: builds dependencies from source as part of the build.
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
  URL https://github.com/scapix-com/cmodule/releases/download/v3.0.5/cmodule-3.0.5.tar.gz
  URL_HASH SHA256=081f0e9fb8bda12c797852da9d604e82a286f192ddb5c41225ecfbb5b6048a21
)
FetchContent_MakeAvailable(cmodule)

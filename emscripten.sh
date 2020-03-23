# adjust path to emsdk
source ~/Source/emsdk/emsdk_env.sh
cmake -B build/emscripten -DSCAPIX_BRIDGE=js -DCMAKE_TOOLCHAIN_FILE=$EMSDK/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake
cmake --build build/emscripten

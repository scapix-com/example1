source ~/Source/emsdk/emsdk_env.sh
#cmake -B build/emscripten -DSCAPIX_BRIDGE=js -DCMAKE_TOOLCHAIN_FILE=~/Source/polly/emscripten-cxx17.cmake
cmake -B build/emscripten -DSCAPIX_BRIDGE=js -DCMAKE_TOOLCHAIN_FILE=$EMSDK/fastcomp/emscripten/cmake/Modules/Platform/Emscripten.cmake
cmake --build build/emscripten

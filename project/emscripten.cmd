call c:\library\dev\emsdk\emsdk_env.bat
rem cmake -B build/emscripten -DSCAPIX_BRIDGE=js -DCMAKE_TOOLCHAIN_FILE=c:/library/dev/polly/emscripten-cxx17.cmake
cmake -B build/emscripten -DSCAPIX_BRIDGE=js -DCMAKE_TOOLCHAIN_FILE=%EMSDK%/fastcomp/emscripten/cmake/Modules/Platform/Emscripten.cmake
cmake --build build/emscripten

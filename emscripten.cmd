@rem adjust path to emsdk
call c:\library\dev\emsdk\emsdk_env.bat
cmake -B build/emscripten -G Ninja -DSCAPIX_BRIDGE=js -DCMAKE_TOOLCHAIN_FILE=%EMSDK%/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake
cmake --build build/emscripten

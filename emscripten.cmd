@echo off

IF NOT DEFINED EMSDK (
  IF EXIST c:\library\dev\emsdk\emsdk_env.bat (
    setlocal
    call c:\library\dev\emsdk\emsdk_env.bat
  ) ELSE (
    echo "error: no EMSDK environment variable, run emsdk\emsdk_env.bat"
    exit /b 1
  )
)

cmake -B build/emscripten -G Ninja -DSCAPIX_BRIDGE=js -DCMAKE_TOOLCHAIN_FILE=%EMSDK%/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake
cmake --build build/emscripten

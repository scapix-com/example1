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

%EMSDK%\upstream\emscripten\emrun --serve_root ../.. test.html

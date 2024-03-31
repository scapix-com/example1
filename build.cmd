@echo off

IF "%1" == "" (
  cmake --list-presets
  exit /b 1
)

IF %1 == emscripten (
  IF NOT DEFINED EMSDK (
    IF EXIST c:\library\dev\emsdk\emsdk_env.bat (
      setlocal
      call c:\library\dev\emsdk\emsdk_env.bat
    ) ELSE (
      echo "error: no EMSDK environment variable, run emsdk\emsdk_env.bat"
      exit /b 1
    )
  )
)

cmake --preset %1 && cmake --build build/%1

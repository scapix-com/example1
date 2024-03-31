@echo off

IF "%1" == "" (
  cmake --list-presets
  exit /b 1
)

set str1=%1
IF NOT x%str1:js=%==x%str1% (
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

cmake --preset %1 && cmake --build build/%1 --parallel

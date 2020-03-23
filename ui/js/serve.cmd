@rem adjust path to emsdk
call c:\library\dev\emsdk\emsdk_env.bat
%EMSDK%\upstream\emscripten\emrun --serve_root ../.. test.html

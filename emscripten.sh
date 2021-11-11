if [ -z "$EMSDK" ]; then
  if [ -f ~/Source/emsdk/emsdk_env.sh ]; then
    source ~/Source/emsdk/emsdk_env.sh
  else
    echo "error: no EMSDK environment variable, run emsdk/emsdk_env.sh"
    exit 1
  fi
fi

cmake -B build/emscripten -DSCAPIX_BRIDGE=js -DCMAKE_TOOLCHAIN_FILE=$EMSDK/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake
cmake --build build/emscripten

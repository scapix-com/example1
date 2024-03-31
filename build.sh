if [ -z $1 ]; then
  cmake --list-presets
  exit 1
fi

if [[ $1 == *"emscripten"* ]]; then
  if [ -z "$EMSDK" ]; then
    if [ -f ~/Source/emsdk/emsdk_env.sh ]; then
      source ~/Source/emsdk/emsdk_env.sh
    else
      echo "error: no EMSDK environment variable, run emsdk/emsdk_env.sh"
      exit 1
    fi
  fi
fi

cmake --preset $1 && cmake --build build/$1 --parallel

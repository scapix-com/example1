if [ -z $1 ]; then
  cmake --list-presets
  exit 1
fi

if [[ $1 == *"js"* ]]; then
  if [ -z "$EMSDK" ]; then
    if [ -f ~/Source/emsdk/emsdk_env.sh ]; then
      export EMSDK_QUIET=1
      source ~/Source/emsdk/emsdk_env.sh
    else
      echo "error: no EMSDK environment variable, run emsdk/emsdk_env.sh"
      exit 1
    fi
  fi
fi

cmake --preset $1 || exit 1
cmake --build build/$1 --parallel || exit 1

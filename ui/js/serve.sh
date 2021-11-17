if [ -z "$EMSDK" ]; then
  if [ -f ~/Source/emsdk/emsdk_env.sh ]; then
    source ~/Source/emsdk/emsdk_env.sh
  else
    echo "error: no EMSDK environment variable, run emsdk/emsdk_env.sh"
    exit 1
  fi
fi

emrun --serve_root ../.. test.html

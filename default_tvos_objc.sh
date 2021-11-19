cmake -B build/default_tvos_objc -DCMAKE_SYSTEM_NAME=tvOS -DCMAKE_OSX_ARCHITECTURES=arm64 -DSCAPIX_BRIDGE=objc
cmake --build build/default_tvos_objc

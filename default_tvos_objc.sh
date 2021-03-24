cmake -B build/default_tvos_objc -DCMAKE_SYSTEM_NAME=tvOS -DCMAKE_OSX_ARCHITECTURES=arm64 -DSCAPIX_BRIDGE=objc -DSCAPIX_PLATFORM=apple
cmake --build build/default_tvos_objc

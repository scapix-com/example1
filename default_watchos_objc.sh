cmake -B build/default_watchos_objc -DCMAKE_SYSTEM_NAME=watchOS -DCMAKE_OSX_ARCHITECTURES=arm64 -DSCAPIX_BRIDGE=objc -DSCAPIX_PLATFORM=apple
cmake --build build/default_watchos_objc

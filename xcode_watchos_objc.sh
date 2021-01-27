cmake -B build/xcode_watchos_objc -G "Xcode" -DCMAKE_SYSTEM_NAME=watchOS -DSCAPIX_BRIDGE=objc -DSCAPIX_PLATFORM=apple
cmake --build build/xcode_watchos_objc

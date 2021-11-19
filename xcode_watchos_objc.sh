cmake -B build/xcode_watchos_objc -G "Xcode" -DCMAKE_SYSTEM_NAME=watchOS -DSCAPIX_BRIDGE=objc
cmake --build build/xcode_watchos_objc

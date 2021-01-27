cmake -B build/xcode_tvos_objc -G "Xcode" -DCMAKE_SYSTEM_NAME=tvOS -DSCAPIX_BRIDGE=objc -DSCAPIX_PLATFORM=apple
cmake --build build/xcode_tvos_objc

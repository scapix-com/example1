cmake -B build/xcode_ios_objc -G "Xcode" -DCMAKE_SYSTEM_NAME=iOS -DSCAPIX_BRIDGE=objc -DSCAPIX_PLATFORM=apple
cmake --build build/xcode_ios_objc

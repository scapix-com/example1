cmake -B build/xcode_ios_objc -G "Xcode" -DSCAPIX_BRIDGE=objc -DSCAPIX_PLATFORM=apple -DCMAKE_TOOLCHAIN_FILE=../../scapix/project/cmake/modules/ios.toolchain.cmake -DIOS_PLATFORM=SIMULATOR64
cmake --build build/xcode_ios_objc

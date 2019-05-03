cmake -B build/xcode_ios_objc -G "Xcode" -Dscapix_bridge=objc -Dscapix_platform=apple -DCMAKE_TOOLCHAIN_FILE=../../scapix/project/cmake/modules/ios.toolchain.cmake -DIOS_PLATFORM=SIMULATOR64
cmake --build build/xcode_ios_objc

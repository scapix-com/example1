cmake -B build/default_ios_objc -DCMAKE_SYSTEM_NAME=iOS -DCMAKE_OSX_ARCHITECTURES=arm64 -DSCAPIX_BRIDGE=objc
cmake --build build/default_ios_objc

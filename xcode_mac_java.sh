cmake -B build/xcode_mac_java -G "Xcode" -DSCAPIX_BRIDGE=java -DSCAPIX_PLATFORM=java -DSCAPIX_JAVA_API=jdk-11.0.2
cmake --build build/xcode_mac_java

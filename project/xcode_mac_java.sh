cmake -B build/xcode_mac_java -G "Xcode" -Dscapix_bridge=java -Dscapix_platform=java -Dscapix_java_api=jdk-11.0.2
cmake --build build/xcode_mac_java

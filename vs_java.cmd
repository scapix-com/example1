cmake -B build\vs_java -G "Visual Studio 16 2019" -T host=x64 -A x64 -DSCAPIX_BRIDGE=java -DSCAPIX_PLATFORM=java -DSCAPIX_JAVA_API=jdk-11.0.2
cmake --build build\vs_java

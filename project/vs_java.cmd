cmake -B build\vs_java -G "Visual Studio 16 2019" -T host=x64 -A x64 -Dscapix_bridge=java -Dscapix_platform=java -Dscapix_java_api=jdk-11.0.2
cmake --build build\vs_java

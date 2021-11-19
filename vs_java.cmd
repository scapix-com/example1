cmake -B build\vs_java -G "Visual Studio 16 2019" -T host=x64 -A x64 -DSCAPIX_BRIDGE=java
cmake --build build\vs_java

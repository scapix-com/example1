@cmd /c "mkdir build\vs_java & cd build\vs_java & cmake -Dscapix_bridge=java -Dscapix_platform=java -Dscapix_java_api=jdk-11.0.2 -G "Visual Studio 16 2019" -T host=x64 -A x64 ../.."

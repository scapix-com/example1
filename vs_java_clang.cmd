@rem  Required vs2019 components:
@rem    C++ Clang Compiler for Windows (8.0.0)
@rem    C++ Clang-cl for v142 build tools (x64/x86)

cmake -B build\vs_java_clang -G "Visual Studio 16 2019" -T clangcl,host=x64 -A x64 -DSCAPIX_BRIDGE=java -DSCAPIX_PLATFORM=java -DSCAPIX_JAVA_API=jdk-11.0.2
cmake --build build\vs_java_clang

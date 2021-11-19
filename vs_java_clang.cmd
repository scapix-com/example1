@rem  Required vs2019 components:
@rem    C++ Clang Compiler for Windows
@rem    C++ Clang-cl for v142 build tools (x64/x86)

cmake -B build\vs_java_clang -G "Visual Studio 16 2019" -T clangcl,host=x64 -A x64 -DSCAPIX_BRIDGE=java
cmake --build build\vs_java_clang

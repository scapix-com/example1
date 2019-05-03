cmake -B build\vs_cpp -G "Visual Studio 16 2019" -T host=x64 -A x64 -Dscapix_bridge=cpp -Dscapix_platform=windows
cmake --build build\vs_cpp

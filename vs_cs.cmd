cmake -B build\vs_cs -G "Visual Studio 16 2019" -T host=x64 -A x64 -DSCAPIX_BRIDGE=cs -DSCAPIX_PLATFORM=windows
cmake --build build\vs_cs

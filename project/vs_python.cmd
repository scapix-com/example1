cmake -B build\vs_python -G "Visual Studio 16 2019" -T host=x64 -A x64 -Dscapix_bridge=python -Dscapix_platform=windows
cmake --build build\vs_python

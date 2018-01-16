
:: g++: -w    - to ignore warnings

g++ %1 -c "src/Main.cpp" -std=c++11 -m32 -O3 -o "bin/Main.o"
g++ %1 -c "src/func/Debug.cpp" -std=c++11 -m32 -O3 -o "bin/Debug.o"
g++ %1 -c "src/mtd/NavMesh.cpp" -std=c++11 -m32 -O3 -o "bin/NavMesh.o"





:: g++: -w    - to ignore warnings

::g++ %1 -c "src/Main.cpp" -std=c++11 -m32 -O3 -o "bin/Main.o"
::g++ %1 -c "src/func/Debug.cpp" -std=c++11 -m32 -O3 -o "bin/Debug.o"
::g++ %1 -c "src/mtd/NavMesh.cpp" -std=c++11 -m32 -O3 -o "bin/NavMesh.o"

::g++ %1 -c "src/mtd/Actor.cpp" -std=c++11 -m32 -O3 -o "bin/Actor.o"
::g++ %1 -c "src/mtd/ActorDynamic.cpp" -std=c++11 -m32 -O3 -o "bin/ActorDynamic.o"
::g++ %1 -c "src/mtd/ActorOBB.cpp" -std=c++11 -m32 -O3 -o "bin/ActorOBB.o"

g++ %1 -c "src/mtd/Engine.cpp" -std=c++11 -m32 -O3 -o "bin/Engine.o"



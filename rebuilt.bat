
g++ -c "src/Main.cpp" -std=c++11 -m32 -O3 -o "bin/Main.o"
g++ -c "src/mtd/Collider.cpp" -std=c++11 -m32 -O3 -o "bin/Collider.o"
g++ -c "src/mtd/NavMesh.cpp" -std=c++11 -m32 -O3 -o "bin/NavMesh.o"

g++ -c "src/func/Debug.cpp" -std=c++11 -m32 -O3 -o "bin/Debug.o"

:: Marek Zalewski's libraries:
g++ -c "src/lib/MZ/SourceCode/GetSthFromString.cpp" -std=c++11 -m32 -O3 -o "bin/GetSthFromString.o"
g++ -c "src/lib/MZ/SourceCode/StandardManagerC.cpp" -std=c++11 -m32 -O3 -o "bin/StandardManagerC.o"
g++ -c "src/lib/MZ/SourceCode/Quadtree.cpp" -std=c++11 -m32 -O3 -o "bin/Quadtree.o"
g++ -c "src/lib/MZ/SourceCode/Triangle.cpp" -std=c++11 -m32 -O3 -o "bin/Triangle.o"
g++ -c "src/lib/MZ/SourceCode/VMatrix.cpp" -std=c++11 -m32 -O3 -o "bin/VMatrix.o"
g++ -c "src/lib/MZ/SourceCode/Octree.cpp" -std=c++11 -m32 -O3 -o "bin/Octree.o"
g++ -c "src/lib/MZ/SourceCode/Vector.cpp" -std=c++11 -m32 -O3 -o "bin/Vector.o"
g++ -c "src/lib/MZ/SourceCode/AABB.cpp" -std=c++11 -m32 -O3 -o "bin/AABB.o"
g++ -c "src/lib/MZ/SourceCode/Math.cpp" -std=c++11 -m32 -O3 -o "bin/Math.o"
g++ -c "src/lib/MZ/SourceCode/Quat.cpp" -std=c++11 -m32 -O3 -o "bin/Quat.o"

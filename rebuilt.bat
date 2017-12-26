
g++ -c "src/Main.cpp" -m32 -O3 -o "bin/Main.o"
g++ -c "src/mtd/Collider.cpp" -m32 -O3 -o "bin/Collider.o"
g++ -c "src/mtd/NavMesh.cpp" -m32 -O3 -o "bin/NavMesh.o"

g++ -c "src/func/Debug.cpp" -m32 -O3 -o "bin/Debug.o"

g++ -c "src/lib/MZ/SourceCode/AABB.cpp" "src/lib/MZ/SourceCode/GetSthFromString.cpp" "src/lib/MZ/SourceCode/Math.cpp" "src/lib/MZ/SourceCode/Octree.cpp" "src/lib/MZ/SourceCode/Quadtree.cpp" "src/lib/MZ/SourceCode/Quat.cpp" "src/lib/MZ/SourceCode/StandardManagerC.cpp" "src/lib/MZ/SourceCode/Triangle.cpp" "src/lib/MZ/SourceCode/Vector.cpp" "src/lib/MZ/SourceCode/VMatrix.cpp" -m32 -O3 -o "bin/LibMZ.o"

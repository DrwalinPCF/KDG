
::SOIL2 libfrary;

g++ %1 -c "Libraries\soil2\include\etc1_utils.c" -std=c++11 -m32 -Ofast -o "bin/etc1_utils.o"
g++ %1 -c "Libraries\soil2\include\image_DXT.c" -std=c++11 -m32 -Ofast -o "bin/image_DXT.o"
g++ %1 -c "Libraries\soil2\include\image_helper.c" -std=c++11 -m32 -Ofast -o "bin/image_helper.o"
g++ %1 -c "Libraries\soil2\include\SOIL2.c" -std=c++11 -m32 -Ofast -o "bin/SOIL2.o"


:: Marek Zalewski's libraries;
g++ %1 -c "src/lib/MZ/SourceCode/GetSthFromString.cpp" -std=c++11 -m32 -Ofast -o "bin/GetSthFromString.o"
g++ %1 -c "src/lib/MZ/SourceCode/Triangle.cpp" -std=c++11 -m32 -Ofast -o "bin/Triangle.o"
g++ %1 -c "src/lib/MZ/SourceCode/VMatrix.cpp" -std=c++11 -m32 -Ofast -o "bin/VMatrix.o"
g++ %1 -c "src/lib/MZ/SourceCode/Vector.cpp" -std=c++11 -m32 -Ofast -o "bin/Vector.o"
g++ %1 -c "src/lib/MZ/SourceCode/AABB.cpp" -std=c++11 -m32 -Ofast -o "bin/AABB.o"
g++ %1 -c "src/lib/MZ/SourceCode/Math.cpp" -std=c++11 -m32 -Ofast -o "bin/Math.o"
g++ %1 -c "src/lib/MZ/SourceCode/Quat.cpp" -std=c++11 -m32 -Ofast -o "bin/Quat.o"



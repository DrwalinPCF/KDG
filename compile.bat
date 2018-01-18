
g++ -Ofast -m32 -o "release/KDG.exe" -std=c++11 -static-libgcc "Libraries/glew/lib/Release/Win32/glew32s.lib" -lopengl32 -lglu32 "Libraries/glfw/lib-mingw/libglfw3.a" -lgdi32 -lwinmm "Libraries/sdl2/lib/libSDL2.a" "Libraries/sdl2/lib/libSDL2main.a"    "bin/etc1_utils.o" "bin/image_DXT.o" "bin/image_helper.o" "bin/SOIL2.o"    "bin/Main.o" "bin/Engine.c" "bin/NavMesh.o" "bin/Debug.o" "bin/GetSthFromString.o" "bin/Triangle.o" "bin/VMatrix.o" "bin/Math.o" "bin/Vector.o" "bin/AABB.o" "bin/Quat.o" "bin/Actor.o" "bin/ActorDynamic.o" "bin/ActorOBB.o" "bin/ActorStatic.o" "bin/Error.o"



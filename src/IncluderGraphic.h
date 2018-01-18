
/*
	Copyright (c) 2018 Marek Zalewski and Kacper Orzeszko
*/

#ifndef INCLUDER_GRAPHIC_H
#define INCLUDER_GRAPHIC_H

#define GLEW_STATIC

#ifndef USE_BUILD_IN_OPENGL
#  include <GL/glew.h>
#  include <glm/glm.hpp>
#  include <glm/gtc/matrix_transform.hpp>
#  include <glm/gtc/type_ptr.hpp>
#  include <GLFW/glfw3.h>
#  include <SOIL2/SOIL2.h>
#else
#  include "../Libraries/glew/include/GL/glew.h"
#  include "../Libraries/glm/include/glm.hpp"
#  include "../Libraries/glm/include/gtc/matrix_transform.hpp"
#  include "../Libraries/glm/include/gtc/type_ptr.hpp"
#  include "../Libraries/glfw/include/GLFW/glfw3.h"
#  include "../Libraries/soil2/SOIL2.h"
#endif

#endif


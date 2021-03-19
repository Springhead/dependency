/*
 *  Copyright (c) 2003-2006, Shoichi Hasegawa and Springhead development team 
 *  All rights reserved.
 *  This software is free software. You can freely use, distribute and modify this 
 *  software. Please deal with this software under one of the following licenses: 
 *  This license itself, Boost Software License, The MIT License, The BSD License.   
 */

#ifdef USE_FREEGLUT
#define NDEBUG
#  include <GL/freeglut.h>
#undef NDEBUG
#else
# ifdef _MSC_VER
#  define NDEBUG
#    include "win32/glut.h"
#    define GLUTCALLBACK
#  undef NDEBUG
# endif
# ifdef __CYGWIN__
#  include "cygwin/glut.h" 
# endif
# ifdef __linux__
#  include "linux/freeglut.h" 
# endif
# ifdef __APPLE__			// Mac OS X's OpenGL layer for Aqua.
#  include <GLUT/glut.h>
# endif
#endif

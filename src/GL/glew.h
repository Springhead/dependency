/*
 *  Copyright (c) 2003-2006, Shoichi Hasegawa and Springhead development team 
 *  All rights reserved.
 *  This software is free software. You can freely use, distribute and modify this 
 *  software. Please deal with this software under one of the following licenses: 
 *  This license itself, Boost Software License, The MIT License, The BSD License.   
 */
#ifdef _MSC_VER
	// To disable automatic library usage for GLEW, define GLEW_NO_LIB_PRAGMA
	#ifndef GLEW_NO_LIB_PRAGMA
	# pragma comment (lib, "glew32.lib")		// link with Win32 GLEW lib
	#endif
	#include "win32/glew.h"
#endif
#ifdef __CYGWIN__
#include "cygwin/glew.h" 
#endif
#ifdef __linux__
#include "linux/glew.h" 
#endif
#ifdef __APPLE__			// Mac OS X's OpenGL layer for Aqua.
#include "darwin/glew.h"
#endif

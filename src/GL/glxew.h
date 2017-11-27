/*
 *  Copyright (c) 2003-2006, Shoichi Hasegawa and Springhead development team 
 *  All rights reserved.
 *  This software is free software. You can freely use, distribute and modify this 
 *  software. Please deal with this software under one of the following licenses: 
 *  This license itself, Boost Software License, The MIT License, The BSD License.   
 */
#ifdef __CYGWIN__
#include "cygwin/glxew.h" 
#endif
#ifdef __linux__
#include "linux/glxew.h" 
#endif
#ifdef __APPLE__			// Mac OS X's OpenGL layer for Aqua.
#include "darwin/glxew.h"
#endif
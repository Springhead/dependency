/*
 *  Copyright (c) 2003-2006, Shoichi Hasegawa and Springhead development team 
 *  All rights reserved.
 *  This software is free software. You can freely use, distribute and modify this 
 *  software. Please deal with this software under one of the following licenses: 
 *  This license itself, Boost Software License, The MIT License, The BSD License.   
 */
#ifdef _MSC_VER
# include "win32/freeglut_std.h"
#elif __linux__
# include "linux/freeglut_std.h"
#else
# error "freeglut_std is not available on this platform."
#endif

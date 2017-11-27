// show_msc_version.cpp : メイン プロジェクト ファイルです。

#include "stdafx.h"
//#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string.h>

static char* names[] = {
	"VisualStudioVersion",
	"PlatformToolset",
	"PlatformToolsetVersion",
};
static char* tmpf = "PrintMacros.tmp";

int main()
{
	const int sz = 256;
	char buff[sz];
	char vars[3][sz];
	int ix = 0;
	std::ifstream ifs(tmpf);
	if (!ifs.fail()) {
		while (ifs.getline(buff, sz-1)) {
			strcpy_s(vars[ix++], sz, buff);
		}
	}
	else {
		std::cout << "Can't open file " << tmpf << std::endl;
	}

	std::cout << "_MSC_VER:\t\t\t" << _MSC_VER << std::endl;
	std::cout << "$(VisualStudioVersion):\t\t" << vars[0] << std::endl;
	std::cout << "$(PlatformToolset):\t\t" << vars[1] << std::endl;
	std::cout << "$(PlatformToolsetVersion):\t" << vars[2] << std::endl;
	std::cout << std::endl;

	std::cout << "BOOST_MSVC:\t\t" << _MSC_VER << std::endl;
	std::cout << "BOOST_LIB_MSVC:\t\tvc" << vars[2] << std::endl;
	std::cout << "VS:\t\t\t" << vars[0] << std::endl;
	std::cout << "VC:\t\t\tvc" << vars[2] << std::endl;

    std::cout << std::endl;
    std::cout << "hit any key to exit" << std::endl;
    getchar();
    return 0;
}
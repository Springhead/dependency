# copyright John Maddock 2006
# Distributed under the Boost Software License, Version 1.0. 
# (See accompanying file LICENSE_1_0.txt or copy at 
# http://www.boost.org/LICENSE_1_0.txt.
#
# auto generated makefile for VC6 compiler
#
# usage:
# make
#   brings libraries up to date
# make install
#   brings libraries up to date and copies binaries to your VC6 /lib and /bin directories (recomended)
#

# Reconstructed:    2014/03/13 by F.Kanehori
#
# To show the usage of this makefile, execute 'help' target.
#     C:dir> nmake -f VC.mak help
#
# Memo:
#   for configuration Debug		        $(LIBPREFIX)-mt-sgd-1_43.lib
#   for configuration DebugDll	        $(LIBPREFIX)-mt-gd-1_43.lib
#					                    $(BINPREFIX)-mt-gd-1_43.dll
#   for configuration Release		    $(LIBPREFIX)-mt-s-1_43.lib
#   for configuration ReleaseDll/Trace  $(LIBPREFIX)-mt-1_43.lib
#					                    $(BINPREFIX)-mt-1_43.dll
#

# Definition of default value.
#
VC = vc120
VS = 12.0
TARGET = x86
LIBDIR = ..\..\..\..\lib
BINDIR = ..\..\..\..\bin

COPTS  =
CC     = cl

VSINSDIR = C:\Program Files (x86)\Microsoft Visual Studio $(VS)
MSVCDIR  = $(VSINSDIR)\VC
TMPMAKEF = VC.tmp.mak

!IF "$(TARGET)" == "x86"
PLATFORM = Win32
!ELSE
PLATFORM = Win64
!ENDIF

!MESSAGE Using parameters ...
!MESSAGE 　VC: [$(VC)]
!MESSAGE 　VS: [$(VS)]
!MESSAGE 　TARGET: [$(TARGET)]
!MESSAGE 　PLATFORM: [$(PLATFORM)]
!MESSAGE 　LIBDIR: [$(LIBDIR)]
!MESSAGE 　BINDIR: [$(BINDIR)]
!MESSAGE 　VSINSDIR: [$(VSINSDIR)]
!MESSAGE 　MSVCDIR: [$(MSVCDIR)]
!MESSAGE 

#
# path to ICU library installation goes here:
#
ICU_PATH =
# Add additional compiler options here:
#
CXXFLAGS = $(COPTS) /wd""4005""

#
# Add additional include directories here:
#
INCLUDES = /I..\..\..\ 
#
#
# add additional linker flags here:
#
XLFLAGS =

LIBPREFIX = libboost_regex-$(VC)
BINPREFIX = boost_regex-$(VC)

SRCDIR = ..\src
OBJDIR = .\$(VC)\$(PLATFORM)

OPT_DBG	= /Zi /Od /fp:precise /D_DEBUG 
OPT_REL	= /Zi /O2 /Ob2 /Ot /fp:precise /DNDEBUG
!IF "$(VC)" == "vc100"
OPT_DBG	= $(OPT_DBG) /Ob0 /Oy- /Gd
OPT_REL	= $(OPT_REL) /Oy /Gr
!ELSEIF "$(VC)" == "vc110"
OPT_DBG	= $(OPT_DBG) /Ob0 /Oy-
OPT_REL	= $(OPT_REL) /Oy
!ENDIF

OPT_DBG_DLL  = /DUSRDLL 
OPT_REL_DLL  = /D_USRDLL 
OPT_STA_LINK = /DBOOST_REGEX_STATIC_LINK /D_WINDOWS
OPT_DYN_LINK = /DBOOST_REGEX_DYN_LINK /D_WINDOWS
OPT_STA_LIB  = /D_LIB
OPT_MT       = /D_MT

OPT_COMMON  = /c /nologo /W3 /EHsc /Y- /fp:except /openmp /FD /DWIN32 /D_WIN32 /D_MBCS $(INCLUDES) $(CXXFLAGS) $(ICU_COMPILE_OPTS)
!IF "$(VC)" == "vc100"
OPT_COMMON  = $(OPT_COMMON) /MP /GF- /Gm- /Gy- /Zc:wchar_t
!ELSEIF "$(VC)" == "vc110"
OPT_COMMON  = $(OPT_COMMON) /MP /GF- /Gm- /arch:AVX /Gy- /Zc:wchar_t
!ENDIF

MTLIB_DBG     = $(OPT_COMMON) /MTd $(OPT_DBG) $(OPT_STA_LIB) $(OPT_MT)
MTLIB_DBG_DLL = $(OPT_COMMON) /MDd $(OPT_DBG) $(OPT_DBG_DLL) $(OPT_STA_LINK)
MTLIB_REL     = $(OPT_COMMON) /MT  $(OPT_REL) $(OPT_STA_LIB) $(OPT_MT)
MTLIB_RnT_DLL = $(OPT_COMMON) /MD  $(OPT_REL) $(OPT_REL_DLL) $(OPT_STA_LINK)
MTDLL_DBG_DLL = $(OPT_COMMON) /MDd $(OPT_DBG) $(OPT_DBG_DLL) $(OPT_DYN_LINK)
MTDLL_RnT_DLL = $(OPT_COMMON) /MD  $(OPT_REL) $(OPT_REL_DLL) $(OPT_DYN_LINK)
SLIB_DBG      = $(OPT_COMMON) /MLd $(OPT_DBG) $(OPT_STA_LIB)
SLIB_REL      = $(OPT_COMMON) /ML  $(OPT_REL) $(OPT_STA_LIB)

!IF "$(TARGET)" == "x64"
XLFLAGS = $(XLFLAGS) /MACHINE:X64
!ELSE
XLFLAGS = $(XLFLAGS) /MACHINE:X86
!ENDIF

#
# add additional static-library creation flags here:
#
XSFLAGS	= $(XLFLAGS)

SYSLIBS	= kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib
DLLOPTS	= /nologo /dll /debug
LIBPATH	= \lib

!IF "$(OS)" == "Windows_NT"
NULL	=
!ELSE 
NULL	= nul
!ENDIF 

!IF "$(ICU_PATH)" == ""
ICU_COMPILE_OPTS=
ICU_LINK_OPTS=
!MESSAGE Building Boost.Regex without ICU / Unicode support:
!MESSAGE Hint: set ICU_PATH on the nmake command line to point 
!MESSAGE to your ICU installation if you have one.
!ELSE
ICU_COMPILE_OPTS= -DBOOST_HAS_ICU=1 -I"$(ICU_PATH)\include"
ICU_LINK_OPTS= /LIBPATH:"$(ICU_PATH)\lib" icuin.lib icuuc.lib
!MESSAGE Building Boost.Regex with ICU in $(ICU_PATH)
!ENDIF

FILES_DEF = \
	c_regex_traits.x\
	cpp_regex_traits.x\
	cregex.x\
	fileiter.x\
	icu.x\
	instances.x\
	posix_api.x\
	regex.x\
	regex_debug.x\
	regex_raw_buffer.x\
	regex_traits_defaults.x\
	static_mutex.x\
	usinstances.x\
	w32_regex_traits.x\
	wc_regex_traits.x\
	wide_posix_api.x\
	winstances.x

ALL_HEADER = \
	../../../boost/regex/config.hpp\
	../../../boost/regex/icu.hpp\
	../../../boost/regex/pattern_except.hpp\
	../../../boost/regex/regex_traits.hpp\
	../../../boost/regex/user.hpp\
	../../../boost/regex/v4/basic_regex.hpp\
	../../../boost/regex/v4/basic_regex_creator.hpp\
	../../../boost/regex/v4/basic_regex_parser.hpp\
	../../../boost/regex/v4/c_regex_traits.hpp\
	../../../boost/regex/v4/char_regex_traits.hpp\
	../../../boost/regex/v4/cpp_regex_traits.hpp\
	../../../boost/regex/v4/cregex.hpp\
	../../../boost/regex/v4/error_type.hpp\
	../../../boost/regex/v4/fileiter.hpp\
	../../../boost/regex/v4/instances.hpp\
	../../../boost/regex/v4/iterator_category.hpp\
	../../../boost/regex/v4/iterator_traits.hpp\
	../../../boost/regex/v4/match_flags.hpp\
	../../../boost/regex/v4/match_results.hpp\
	../../../boost/regex/v4/mem_block_cache.hpp\
	../../../boost/regex/v4/perl_matcher.hpp\
	../../../boost/regex/v4/perl_matcher_common.hpp\
	../../../boost/regex/v4/perl_matcher_non_recursive.hpp\
	../../../boost/regex/v4/perl_matcher_recursive.hpp\
	../../../boost/regex/v4/primary_transform.hpp\
	../../../boost/regex/v4/protected_call.hpp\
	../../../boost/regex/v4/regbase.hpp\
	../../../boost/regex/v4/regex.hpp\
	../../../boost/regex/v4/regex_format.hpp\
	../../../boost/regex/v4/regex_fwd.hpp\
	../../../boost/regex/v4/regex_grep.hpp\
	../../../boost/regex/v4/regex_iterator.hpp\
	../../../boost/regex/v4/regex_match.hpp\
	../../../boost/regex/v4/regex_merge.hpp\
	../../../boost/regex/v4/regex_raw_buffer.hpp\
	../../../boost/regex/v4/regex_replace.hpp\
	../../../boost/regex/v4/regex_search.hpp\
	../../../boost/regex/v4/regex_split.hpp\
	../../../boost/regex/v4/regex_token_iterator.hpp\
	../../../boost/regex/v4/regex_traits.hpp\
	../../../boost/regex/v4/regex_traits_defaults.hpp\
	../../../boost/regex/v4/regex_workaround.hpp\
	../../../boost/regex/v4/states.hpp\
	../../../boost/regex/v4/sub_match.hpp\
	../../../boost/regex/v4/syntax_type.hpp\
	../../../boost/regex/v4/u32regex_iterator.hpp\
	../../../boost/regex/v4/u32regex_token_iterator.hpp\
	../../../boost/regex/v4/w32_regex_traits.hpp\
	../../../boost/regex/config/borland.hpp\
	../../../boost/regex/config/cwchar.hpp

all: main_dir\
	$(LIBPREFIX)-mt-s-1_43_dir   $(OBJDIR)\$(LIBPREFIX)-mt-s-1_43.lib\
	$(LIBPREFIX)-mt-sgd-1_43_dir $(OBJDIR)\$(LIBPREFIX)-mt-sgd-1_43.lib\
	$(BINPREFIX)-mt-gd-1_43_dir  $(OBJDIR)\$(BINPREFIX)-mt-gd-1_43.lib\
	$(BINPREFIX)-mt-1_43_dir     $(OBJDIR)\$(BINPREFIX)-mt-1_43.lib\
	$(LIBPREFIX)-mt-1_43_dir     $(OBJDIR)\$(LIBPREFIX)-mt-1_43.lib\
	$(LIBPREFIX)-mt-gd-1_43_dir  $(OBJDIR)\$(LIBPREFIX)-mt-gd-1_43.lib

org_all: main_dir\
	$(LIBPREFIX)-s-1_43_dir      $(OBJDIR)\$(LIBPREFIX)-s-1_43.lib\
	$(LIBPREFIX)-mt-s-1_43_dir   $(OBJDIR)\$(LIBPREFIX)-mt-s-1_43.lib\
	$(LIBPREFIX)-sgd-1_43_dir    $(OBJDIR)\$(LIBPREFIX)-sgd-1_43.lib\
	$(LIBPREFIX)-mt-sgd-1_43_dir $(OBJDIR)\$(LIBPREFIX)-mt-sgd-1_43.lib\
	$(BINPREFIX)-mt-gd-1_43_dir  $(OBJDIR)\$(BINPREFIX)-mt-gd-1_43.lib\
	$(BINPREFIX)-mt-1_43_dir     $(OBJDIR)\$(BINPREFIX)-mt-1_43.lib\
	$(LIBPREFIX)-mt-1_43_dir     $(OBJDIR)\$(LIBPREFIX)-mt-1_43.lib\
	$(LIBPREFIX)-mt-gd-1_43_dir  $(OBJDIR)\$(LIBPREFIX)-mt-gd-1_43.lib

clean: \
	$(LIBPREFIX)-mt-s-1_43_clean\
	$(LIBPREFIX)-mt-sgd-1_43_clean\
	$(BINPREFIX)-mt-gd-1_43_clean\
	$(BINPREFIX)-mt-1_43_clean\
	$(LIBPREFIX)-mt-1_43_clean\
	$(LIBPREFIX)-mt-gd-1_43_clean

org_clean: \
	$(LIBPREFIX)-s-1_43_clean\
	$(LIBPREFIX)-mt-s-1_43_clean\
	$(LIBPREFIX)-sgd-1_43_clean\
	$(LIBPREFIX)-mt-sgd-1_43_clean\
	$(BINPREFIX)-mt-gd-1_43_clean\
	$(BINPREFIX)-mt-1_43_clean\
	$(LIBPREFIX)-mt-1_43_clean\
	$(LIBPREFIX)-mt-gd-1_43_clean

install:    
	copy /Y /V $(OBJDIR)\*.lib $(LIBDIR)\$(PLATFORM)
	copy /Y /V $(OBJDIR)\*.dll $(BINDIR)\$(PLATFORM)

install_pdb:
	copy /Y /V $(OBJDIR)\$(BINPREFIX)*.pdb $(BINDIR)\$(PLATFORM)
	copy /Y /V $(OBJDIR)\$(LIBPREFIX)*.pdb $(LIBDIR)\$(PLATFORM)

org_install: all
	copy $(OBJDIR)\$(LIBPREFIX)-s-1_43.lib      "$(MSVCDIR)\lib"
	copy $(OBJDIR)\$(LIBPREFIX)-mt-s-1_43.lib   "$(MSVCDIR)\lib"
	copy $(OBJDIR)\$(LIBPREFIX)-sgd-1_43.lib    "$(MSVCDIR)\lib"
	copy $(OBJDIR)\$(LIBPREFIX)-sgd-1_43.pdb    "$(MSVCDIR)\lib"
	copy $(OBJDIR)\$(LIBPREFIX)-mt-sgd-1_43.lib "$(MSVCDIR)\lib"
	copy $(OBJDIR)\$(LIBPREFIX)-mt-sgd-1_43.pdb "$(MSVCDIR)\lib"
	copy $(OBJDIR)\$(BINPREFIX)-mt-gd-1_43.lib  "$(MSVCDIR)\lib"
	copy $(OBJDIR)\$(BINPREFIX)-mt-gd-1_43.dll  "$(MSVCDIR)\bin"
	copy $(OBJDIR)\$(BINPREFIX)-mt-gd-1_43.pdb  "$(MSVCDIR)\lib"
	copy $(OBJDIR)\$(BINPREFIX)-mt-1_43.lib     "$(MSVCDIR)\lib"
	copy $(OBJDIR)\$(BINPREFIX)-mt-1_43.dll     "$(MSVCDIR)\bin"
	copy $(OBJDIR)\$(LIBPREFIX)-mt-1_43.lib     "$(MSVCDIR)\lib"
	copy $(OBJDIR)\$(LIBPREFIX)-mt-gd-1_43.lib  "$(MSVCDIR)\lib"
	copy $(OBJDIR)\$(LIBPREFIX)-mt-gd-1_43.pdb  "$(MSVCDIR)\lib"

help:
    @type VC.mak.help

main_dir :
	@if not exist "$(VC)\$(PLATFORM)\$(NULL)" mkdir $(VC)\$(PLATFORM)

########################################################
#
# section for libboost_regex-$(VC)-s-1_43.lib
#
########################################################
LIBKIND_SLIB_DBG = s-1_43
OBJSOUT_SLIB_DBG = $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)
LIBNAME_SLIB_DBG = $(LIBPREFIX)-$(LIBKIND_SLIB_DBG).lib

$(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG).lib: $(FILES_DEF:.x=.SLIB_DBG)
	cd $(OBJSOUT_SLIB_DBG)
	link -lib /nologo /out:..\$(LIBNAME_SLIB_DBG) $(XSFLAGS) $(FILES_DEF:.x=.obj)
	cd ..\..\..

$(FILES_DEF:.x=.SLIB_DBG):
	@nmake /C FILE=$* HDRS="$(ALL_HEADER)" COPT="$(SLIB_DBG) /Fo$(OBJSOUT_SLIB_DBG)\ /Fd$(OBJSOUT_SLIB_DBG).pdb" ODIR=$(OBJSOUT_SLIB_DBG) SDIR=$(SRCDIR) -f VC_sub.mak

$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)_dir:
	@echo processing: ./$(VC)/$(PLATFORM)/$(LIBNAME_SLIB_DBG) >&2
	@if not exist "$(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)\$(NULL)" mkdir $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)

$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)_clean:
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)\*.obj
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)\*.idb
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)\*.exp
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)\*.pch

########################################################
#
# section for libboost_regex-$(VC)-mt-s-1_43.lib
#
########################################################
LIBKIND_MTLIB_REL = mt-s-1_43
OBJSOUT_MTLIB_REL = $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_REL)
LIBNAME_MTLIB_REL = $(LIBPREFIX)-$(LIBKIND_MTLIB_REL).lib

$(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_REL).lib: $(FILES_DEF:.x=.MTLIB_REL)
	cd $(OBJSOUT_MTLIB_REL)
	link -lib /nologo /out:..\$(LIBNAME_MTLIB_REL) $(XSFLAGS) $(FILES_DEF:.x=.obj)
	cd ..\..\..

$(FILES_DEF:.x=.MTLIB_REL):
	@nmake /C FILE=$* HDRS="$(ALL_HEADER)" COPT="$(MTLIB_REL) /Fo$(OBJSOUT_MTLIB_REL)\ /Fd$(OBJSOUT_MTLIB_REL).pdb" ODIR=$(OBJSOUT_MTLIB_REL) SDIR=$(SRCDIR) -f VC_sub.mak

$(LIBPREFIX)-$(LIBKIND_MTLIB_REL)_dir:
	@echo processing: ./$(VC)/$(PLATFORM)/$(LIBNAME_MTLIB_REL) >&2
	@if not exist "$(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_REL)\$(NULL)" mkdir $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_REL)

$(LIBPREFIX)-$(LIBKIND_MTLIB_REL)_clean:
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_REL)\*.obj
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_REL)\*.idb
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_REL)\*.exp
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_REL)\*.pch

########################################################
#
# section for libboost_regex-$(VC)-sgd-1_43.lib
#
########################################################
LIBKIND_SLIB_DBG = sgd-1_43
OBJSOUT_SLIB_DBG = $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)
LIBNAME_SLIB_DBG = $(LIBPREFIX)-$(LIBKIND_SLIB_DBG).lib

$(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SREL).lib: $(FILES_DEF:.x=.SLIB_DBG)
	cd $(OBJSOUT_SLIB_DBG)
	link -lib /nologo /out:..\$(LIBNAME_SLIB_DBG) $(XSFLAGS) $(FILES_DEF:.x=.obj)
	cd ..\..\..

$(FILES_DEF:.x=.SLIB_DBG):
	@nmake /C FILE=$* HDRS="$(ALL_HEADER)" COPT="$(SLIB_DBG) /Fo$(OBJSOUT_SLIB_DBG)\ /Fd$(OBJSOUT_SLIB_DBG).pdb" ODIR=$(OBJSOUT_SLIB_DBG) SDIR=$(SRCDIR) -f VC_sub.mak

$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)_dir:
	@echo processing: ./$(VC)/$(PLATFORM)/$(LIBNAME_SLIB_DBG) >&2
	@if not exist "$(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)\$(NULL)" mkdir $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)

$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)_clean:
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)\*.obj
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)\*.idb
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)\*.exp
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_SLIB_DBG)\*.pch

########################################################
#
# section for libboost_regex-$(VC)-mt-sgd-1_43.lib
#
########################################################
LIBKIND_MTLIB_DBG = mt-sgd-1_43
OBJSOUT_MTLIB_DBG = $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG)
LIBNAME_MTLIB_DBG = $(LIBPREFIX)-$(LIBKIND_MTLIB_DBG).lib

$(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG).lib: $(FILES_DEF:.x=.MTLIB_DBG)
	cd $(OBJSOUT_MTLIB_DBG)
	link -lib /nologo /out:..\$(LIBNAME_MTLIB_DBG) $(XSFLAGS) $(FILES_DEF:.x=.obj)
	cd ..\..\..

$(FILES_DEF:.x=.MTLIB_DBG):
	@nmake /C FILE=$* HDRS="$(ALL_HEADER)" COPT="$(MTLIB_DBG) /Fo$(OBJSOUT_MTLIB_DBG)\ /Fd$(OBJSOUT_MTLIB_DBG).pdb" ODIR=$(OBJSOUT_MTLIB_DBG) SDIR=$(SRCDIR) -f VC_sub.mak

$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG)_dir:
	@echo processing: ./$(VC)/$(PLATFORM)/$(LIBNAME_MTLIB_DBG) >&2
	@if not exist "$(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG)\$(NULL)" mkdir $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG)

$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG)_clean:
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG)\*.obj
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG)\*.idb
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG)\*.exp
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG)\*.pch

########################################################
#
# section for boost_regex-$(VC)-mt-gd-1_43.lib
#
########################################################
DLLKIND_MTDLL_DBG_DLL = mt-gd-1_43
OBJSOUT_MTDLL_DBG_DLL = $(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL)
DLLNAME_MTDLL_DBG_DLL = $(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL).dll
PDBNAME_MTDLL_DBG_DLL = $(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL).pdb
IMPLIB_MTDLL_DBG_DLL  = $(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL).lib

$(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL).lib: $(FILES_DEF:.x=.MTDLL_DBG_DLL)
	cd $(OBJSOUT_MTDLL_DBG_DLL)
	link $(SYSLIBS) $(DLLOPTS) $(XSFLAGS) /OUT:..\$(DLLNAME_MTDLL_DBG_DLL) /PDB:..\$(PDBNAME_MTDLL_DBG_DLL) /IMPLIB:..\$(IMPLIB_MTDLL_DBG_DLL) /LIBPATH:"$(LIBPATH)" $(FILES_DEF:.x=.obj)
	cd ..\..\..

$(FILES_DEF:.x=.MTDLL_DBG_DLL):
	@nmake /C FILE=$* HDRS="$(ALL_HEADER)" COPT="$(MTDLL_DBG_DLL) /Fo$(OBJSOUT_MTDLL_DBG_DLL)\ /Fd$(OBJSOUT_MTDLL_DBG_DLL).pdb" ODIR=$(OBJSOUT_MTDLL_DBG_DLL) SDIR=$(SRCDIR) -f VC_sub.mak

$(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL)_dir:
	@echo processing: ./$(VC)/$(PLATFORM)/$(DLLNAME_MTDLL_DBG_DLL) >&2
	@if not exist "$(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL)\$(NULL)" mkdir $(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL)

$(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL)_clean:
	del $(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL)\*.obj
	del $(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL)\*.idb
	del $(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL)\*.exp
	del $(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_DBG_DLL)\*.pch

########################################################
#
# section for boost_regex-$(VC)-mt-1_43.lib
#
########################################################
DLLKIND_MTDLL_RnT_DLL = mt-1_43
OBJSOUT_MTDLL_RnT_DLL = $(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL)
DLLNAME_MTDLL_RnT_DLL = $(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL).dll
PDBNAME_MTDLL_RnT_DLL = $(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL).pdb
IMPLIB_MTDLL_RnT_DLL  = $(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL).lib

$(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL).lib: $(FILES_DEF:.x=.MTDLL_RnT_DLL)
	cd $(OBJSOUT_MTDLL_RnT_DLL)
	link $(SYSLIBS) $(DLLOPTS) $(XSFLAGS) /OUT:..\$(DLLNAME_MTDLL_RnT_DLL) /PDB:..\$(PDBNAME_MTDLL_RnT_DLL) /IMPLIB:..\$(IMPLIB_MTDLL_RnT_DLL) /LIBPATH:"$(LIBPATH)" $(FILES_DEF:.x=.obj)
	cd ..\..\..

$(FILES_DEF:.x=.MTDLL_RnT_DLL):
	@nmake /C FILE=$* HDRS="$(ALL_HEADER)" COPT="$(MTDLL_RnT_DLL) /Fo$(OBJSOUT_MTDLL_RnT_DLL)\ /Fd$(OBJSOUT_MTDLL_RnT_DLL).pdb" ODIR=$(OBJSOUT_MTDLL_RnT_DLL) SDIR=$(SRCDIR) -f VC_sub.mak

$(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL)_dir:
	@echo processing: ./$(VC)/$(PLATFORM)/$(DLLNAME_MTDLL_RnT_DLL) >&2
	@if not exist "$(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL)\$(NULL)" mkdir $(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL)

$(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL)_clean:
	del $(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL)\*.obj
	del $(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL)\*.idb
	del $(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL)\*.exp
	del $(OBJDIR)\$(BINPREFIX)-$(DLLKIND_MTDLL_RnT_DLL)\*.pch

########################################################
#
# section for libboost_regex-$(VC)-mt-1_43.lib
#
########################################################
LIBKIND_MTLIB_RnT_DLL = mt-1_43
OBJSOUT_MTLIB_RnT_DLL = $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_RnT_DLL)
LIBNAME_MTLIB_RnT_DLL = $(LIBPREFIX)-$(LIBKIND_MTLIB_RnT_DLL).lib

$(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_RnT_DLL).lib: $(FILES_DEF:.x=.MTLIB_RnT_DLL)
	cd $(OBJSOUT_MTLIB_RnT_DLL)
	link -lib /nologo /out:..\$(LIBNAME_MTLIB_RnT_DLL) $(XSFLAGS) $(FILES_DEF:.x=.obj)
	cd ..\..\..

$(FILES_DEF:.x=.MTLIB_RnT_DLL):
	@nmake /C FILE=$* HDRS="$(ALL_HEADER)" COPT="$(MTLIB_RnT_DLL) /Fo$(OBJSOUT_MTLIB_RnT_DLL)\ /Fd$(OBJSOUT_MTLIB_RnT_DLL).pdb" ODIR=$(OBJSOUT_MTLIB_RnT_DLL) SDIR=$(SRCDIR) -f VC_sub.mak

$(LIBPREFIX)-$(LIBKIND_MTLIB_RnT_DLL)_dir:
	@echo processing: ./$(VC)/$(PLATFORM)/$(LIBNAME_MTLIB_RnT_DLL) >&2
	@if not exist "$(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_RnT_DLL)\$(NULL)" mkdir $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_RnT_DLL)

$(LIBPREFIX)-$(LIBKIND_MTLIB_RnT_DLL)_clean:
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_RnT_DLL)\*.obj
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_RnT_DLL)\*.idb
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_RnT_DLL)\*.exp
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_RnT_DLL)\*.pch

########################################################
#
# section for libboost_regex-$(VC)-mt-gd-1_43.lib
#
########################################################
LIBKIND_MTLIB_DBG_DLL = mt-gd-1_43
OBJSOUT_MTLIB_DBG_DLL = $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG_DLL)
LIBNAME_MTLIB_DBG_DLL = $(LIBPREFIX)-$(LIBKIND_MTLIB_DBG_DLL).lib

$(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG_DLL).lib: $(FILES_DEF:.x=.MTLIB_DBG_DLL)
	cd $(OBJSOUT_MTLIB_DBG_DLL)
	link -lib /nologo /out:..\$(LIBNAME_MTLIB_DBG_DLL) $(XSFLAGS) $(FILES_DEF:.x=.obj)
	cd ..\..\..

$(FILES_DEF:.x=.MTLIB_DBG_DLL):
	@nmake /C FILE=$* HDRS="$(ALL_HEADER)" COPT="$(MTLIB_DBG_DLL) /Fo$(OBJSOUT_MTLIB_DBG_DLL)\ /Fd$(OBJSOUT_MTLIB_DBG_DLL).pdb" ODIR=$(OBJSOUT_MTLIB_DBG_DLL) SDIR=$(SRCDIR) -f VC_sub.mak

$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG_DLL)_dir:
	@echo processing: ./$(VC)/$(PLATFORM)/$(LIBNAME_MTLIB_DBG_DLL) >&2
	@if not exist "$(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG_DLL)\$(NULL)" mkdir $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG_DLL)

$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG_DLL)_clean:
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG_DLL)\*.obj
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG_DLL)\*.idb
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG_DLL)\*.exp
	del $(OBJDIR)\$(LIBPREFIX)-$(LIBKIND_MTLIB_DBG_DLL)\*.pch


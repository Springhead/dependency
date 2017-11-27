@echo off
setlocal enabledelayedexpansion
::=============================================================================
::  SYNOPSIS
::	make [-m host] [-t tool] [-l libdir] [-b bindir] arch target
::	make intro
::
::  DESCRIPTION
::	regex ���C�u����/DLL ���쐬����.
::	target �� build �̏ꍇ�͕⏕�o�b�`�t�@�C�����쐬���Ďg�p����.
::	
::  ARGUMENTS (argument enclosed by bracket is default)
::	-m host		�r���h�R���s���[�^�A�[�L�e�N�`�� { x86 | <x64> }
::	-t tool		�c�[���Z�b�g { vc90 | vc100 | vc110 | <vc120> | vc140 }
::	-l libdir	.lib ���C���X�g�[������f�B���N�g�� <../../../../lib>
::	-b bindir	.dll ���C���X�g�[������f�B���N�g�� <../../../../bin>
::	arch		�^�[�Q�b�g�R���s���[�^�A�[�L�e�N�`�� { x86 | x64 }
::	target		�^�[�Q�b�g { build | install | clean }
::  help        VC.mak �̎g������\��
::	intro		�c�[���Z�b�g�o�[�W�����A�b�v�ւ̑Ή��@��\��
::
::  VERSION
::	Ver 1.0  2014/02/18 F.Kanehori	�o�b�`�t�@�C���̍č\��
::	Ver 1.0a 2014/03/12 F.Kanehori	���O�t�@�C�����ύX
::	Ver 1.1  2014/09/03 F.Kanehori	Visual Studio 2013 (vc120)�ɑΉ�
::	Ver 1.1a 2014/12/04 F.Kanehori	�f�t�H���g�̕ύX (vc120 and x64)
::	Ver 1.2  2016/05/18 F.Kanehori	Visual Studio 2015 (vc140)�ɑΉ�
::	Ver 1.3  2017/07/19 F.Kanehori	install �� install_pdb �Ƃ𕪗�
::=============================================================================
set PROG=%~n0
set $status=0

::----------------------------------------------
:: �g�p����O���v���O����
::
set VCVARSALL=vcvarsall.bat
set MAKE=nmake

::----------------------------------------------
:: �g�p����t�@�C��
::
set MAKEFILE=VC.mak
set TMPBATCH=%PROG%.tmp.bat
set LOG_HEAD=%PROG%

::----------------------------------------------
:: �����̏���
::
set HOST=x64
set TOOL=vc140
set LDIR=..\..\..\..\lib
set BDIR=..\..\..\..\bin
set KEEP=0

:next_arg
set ARG=%1
       if    "%1" == "-m" ( set HOST=%2&& shift && shift && goto :next_arg
) else if    "%1" == "-t" ( set TOOL=%2&& shift && shift && goto :next_arg
) else if    "%1" == "-l" ( set LDIR=%2&& shift && shift && goto :next_arg
) else if    "%1" == "-b" ( set BDIR=%2&& shift && shift && goto :next_arg
) else if    "%1" == "-k" ( set KEEP=1 && shift && goto :next_arg
) else if /i "%1" == "-h" ( call :usage && goto :exit
) else if /i "%1" == "/h" ( call :usage && goto :exit
) else if    "%1" == "?"  ( call :usage && goto :exit
) else if "!ARG:~0,1!" == "-" (
    echo %PROG%: bad arg [!ARG!]
    call :usage && goto :exit
)
set ARCH=%1
set TARGET=%2

call :one_of %HOST% x86 x64
if %$result% equ 0  ( call :message bad arg [%HOST%] && goto :exit )
call :one_of %TOOL% vc90 vc100 vc110 vc120 vc140
if %$result% equ 0  ( call :message bad arg [%TOOL%] && goto :exit )

if "%ARCH%" == ""   ( call :message missing arg ARCH && goto :exit )
call :one_of %ARCH% x86 x64 intro
if %$result% equ 0  ( call :message bad arg [%ARCH%] && goto :exit )
if "%ARCH%" == "intro" set TARGET=intro

if "%TARGET%" == "" ( call :message missing arg TARGET && goto :exit )
call :one_of %TARGET% build install install_pdb clean intro help
if %$result% equ 0  ( call :message bad arg [%TARGET%] && goto :exit )

rem echo HOST=[%HOST%]
rem echo TOOL={%TOOL%]
rem echo ARCH=[%ARCH%]
rem echo TARGET={%TARGET%]

::----------------------------------------------
:: �p�����[�^�̐ݒ�
::
:: Visual Studio 2008
if "%TOOL%" == "vc90" (
    call :and %HOST% x86 %ARCH% x86 && if !$result! equ 1 (set VCVARS=x86)
    call :and %HOST% x86 %ARCH% x64 && if !$result! equ 1 (set VCVARS=x86_amd64)
    call :and %HOST% x64 %ARCH% x86 && if !$result! equ 1 (set VCVARS=x86)
    call :and %HOST% x64 %ARCH% x64 && if !$result! equ 1 (set VCVARS=amd64)
    set VC=vc90
    set VS=9.0
)
:: Visual Studio 2010
if "%TOOL%" == "vc100" (
    call :and %HOST% x86 %ARCH% x86 && if !$result! equ 1 (set VCVARS=x86)
    call :and %HOST% x86 %ARCH% x64 && if !$result! equ 1 (set VCVARS=x86_amd64)
    call :and %HOST% x64 %ARCH% x86 && if !$result! equ 1 (set VCVARS=x86)
    call :and %HOST% x64 %ARCH% x64 && if !$result! equ 1 (set VCVARS=amd64)
    set VC=vc100
    set VS=10.0
)
:: Visual Studio 2012
if "%TOOL%" == "vc110" (
    call :and %HOST% x86 %ARCH% x86 && if !$result! equ 1 (set VCVARS=x86)
    call :and %HOST% x86 %ARCH% x64 && if !$result! equ 1 (set VCVARS=x86_amd64)
    call :and %HOST% x64 %ARCH% x86 && if !$result! equ 1 (set VCVARS=x86)
    call :and %HOST% x64 %ARCH% x64 && if !$result! equ 1 (set VCVARS=amd64)
    set VC=vc110
    set VS=11.0
)
:: Visual Studio 2013
if "%TOOL%" == "vc120" (
    call :and %HOST% x86 %ARCH% x86 && if !$result! equ 1 (set VCVARS=x86)
    call :and %HOST% x86 %ARCH% x64 && if !$result! equ 1 (set VCVARS=x86_amd64)
    call :and %HOST% x64 %ARCH% x86 && if !$result! equ 1 (set VCVARS=amd64_x86)
    call :and %HOST% x64 %ARCH% x64 && if !$result! equ 1 (set VCVARS=amd64)
    set VC=vc120
    set VS=12.0
)
:: Visual Studio 2015
if "%TOOL%" == "vc140" (
    call :and %HOST% x86 %ARCH% x86 && if !$result! equ 1 (set VCVARS=x86)
    call :and %HOST% x86 %ARCH% x64 && if !$result! equ 1 (set VCVARS=x86_amd64)
    call :and %HOST% x64 %ARCH% x86 && if !$result! equ 1 (set VCVARS=amd64_x86)
    call :and %HOST% x64 %ARCH% x64 && if !$result! equ 1 (set VCVARS=amd64)
    set VC=vc140
    set VS=14.0
)

rem echo VCVARS=[%VCVARS%]
rem echo VC=[%VC%]
rem echo VS=[%VS%]
rem echo BATPATH=[%BATPATH%]

if not "%TARGET%" == "intro" (
    echo using parameters..
    echo     build computer architecture: %HOST%
    echo     target computer architecture: %ARCH%
    echo     toolset version: %TOOL%
    echo target is %TARGET%
    echo.
)

::----------------------------------------------
:: �r���h���̐ݒ�
::
if "%TARGET%" == "build" (
    if exist C:\"Program Files (x86)\Microsoft Visual Studio %VS%"\VC\%VCVARSALL% (
	    set BATPATH=C:\"Program Files (x86)\Microsoft Visual Studio %VS%"\VC
    ) else (
	    set BATPATH=C:\"Program Files\Microsoft Visual Studio %VS%"\VC
    )
    if exist %TMPBATCH% del %TMPBATCH%
    echo @echo off> %TMPBATCH%
    echo call !BATPATH!\%VCVARSALL% %VCVARS%>> %TMPBATCH%
)

::----------------------------------------------
:: TARGET �̎��s
::
if "%ARCH%" == "x64" (set SUBDIR=win64) else (set SUBDIR=win32)
if "%ARCH%" == "x64" (set CHKDIR=win32) else (set CHKDIR=win64)

if "%TARGET%" == "build" (
    set OPTS=VC=%VC% VS=%VS% TARGET=%ARCH%
    set TARGET=all
    set LOGFILE=%LOG_HEAD%.%TOOL%-%HOST%-%ARCH%.log
    echo %MAKE% !OPTS! -f %MAKEFILE% !TARGET!>> %TMPBATCH%
    echo exit /b>> %TMPBATCH%
    call %TMPBATCH% > !LOGFILE!
)

call :one_of %TARGET% install install_pdb
if %$result% equ 1 (
    set OPTS=VC=%VC% VS=%VS% TARGET=%ARCH%
    if "%TARGET%" == "install" (
	set OPTS=!OPTS! LIBDIR=%LDIR% BINDIR=%BDIR%
	echo install .lib to [%LDIR%\%SUBDIR%]
	echo install .dll to [%BDIR%\%SUBDIR%]
	%MAKE% !OPTS! -f %MAKEFILE% %TARGET%
    ) else (
	set OPTS=!OPTS! LIBDIR=%LDIR% BINDIR=%BDIR%
	echo install .pdb to [%BDIR%\%SUBDIR%]
	%MAKE% !OPTS! -f %MAKEFILE% %TARGET%
    )
)
if "%TARGET%" == "clean" (
    if exist %TOOL% (
	if exist %TOOL%\%SUBDIR% rd /S /Q %TOOL%\%SUBDIR%
	if not exist %TOOL%\%CHKDIR% rd /S /Q %TOOL%
    )
)
if "%TARGET%" == "intro" (
    type introduction.help | more
)
if "%TARGET%" == "help" (
	echo OPTS=!OPTS!
	%MAKE% !OPTS! -f %MAKEFILE% help
)

::----------------------------------------------
:: �I��
::
    set $status=0
:exit
    if %KEEP% equ 0 (
	    if exist %TMPBATCH% del %TMPBATCH%
    )
    endlocal && set $status=%$status%
exit /b

::=============================================================================

::----------------------------------------------
:: ���̂ǂꂩ   true: $result=1, false: $result=0
::
:one_of
    rem echo OR [%1] [%2]
    if /i "%1" == "%2" ( set $result=1 && exit /b )
    shift /2
    if not "%2" == "" goto :one_of
    set $result=0
exit /b

::----------------------------------------------
:: �_����   true: $result=1, false: $result=0
::
:and
    rem echo AND [%1] [%2]
    if not "%1" == "%2" ( set $result=0 && exit /b )
    shift && shift
    if not "%1" == "" goto :and
    set $result=1
exit /b

::----------------------------------------------
:: ���b�Z�[�W
::
:message
    echo %PROG%: %*
    call :usage
exit /b

::----------------------------------------------
:: �g�p���@�̕\��
::
:usage
    echo Usage: %~n0 [options] arch target
    echo   options:
    echo     -m host      �r���h�R���s���[�^�A�[�L�e�N�`�� { x86 ^| ^<x64^> }
    echo     -t tool      �c�[���Z�b�g { vc90 ^| vc100 ^| vc110 ^| vc120 ^| ^<vc140^> }
    echo     -l libdir    .lib ���C���X�g�[������f�B���N�g�� ^<../../../../lib^>
    echo     -b bindir    .dll ���C���X�g�[������f�B���N�g�� ^<../../../../bin^>
    echo   arguments:
    echo     arch         �^�[�Q�b�g�R���s���[�^�A�[�L�e�N�`�� { x86 ^| x64 }
    echo     target       make �̃^�[�Q�b�g�� { build ^| install ^| clean ^| help ^| intro }
    echo                  �� intro �͐V�����c�[���Z�b�g�̓������@�̕\��
exit /b

:: end build.bat

@echo off
setlocal enabledelayedexpansion

rem ----------------------------------------------------------------------------
rem ���L��Clapack�֘A�̃t�@�C��������̃f�B���N�g���ɃR�s�[����B
rem 	blas<Ver><Config><Platform>.<suffix>
rem 	libf2c<Ver><Config><Platform>.<suffix>
rem 	clapack<Ver><Config><Platform>.<suffix>
rem 
rem     <Ver>		Visual Studio�̃c�[���Z�b�g�o�[�W����
rem			��1�����Ŏw��i�ȗ��A�f�t�H���g�� 14.0�j
rem	<Config>	'D', '', 'T' �̂��ꂼ��
rem	<Platform>	'Win32', 'x64' �̂��ꂼ��
rem	<suffix>	'lib', 'pdb' �̂��ꂼ��
rem ----------------------------------------------------------------------------

set VERSION=14.0
if "%1" neq "" (
    set VERSION=%1
)
set FILES=blas libf2c clapack
set CONFIG=D b T
set PLATFORM=Win32 x64
set SUFFIX=lib pdb

for %%p in (%PLATFORM%) do (
    set T=%%p
    if "!T!" equ "x64" set T=win64
    set SRCDIR=LIB\%%p
    set INSDIR=..\..\lib\!T!
    for %%f in (%FILES%) do (
	for %%v in (%VERSION%) do (
	    for %%c in (%CONFIG%) do (
		set C=%%c
		rem --------------------------------------------------
		rem  C �̒l�� 'b' �Ȃ�� '' �ɒu��������
		rem  �ϐ� CONFIG �̒��ɋ󔒕������w�肷�邽�߂̎d�g��
		rem --------------------------------------------------
		if "!C!" equ "b" set C=
		for %%s in (%SUFFIX%) do (
		    set FILE=%%f%%v!C!%%p.%%s
		    echo copying !FILE! to !INSDIR:\=/!
		    copy !SRCDIR!\!FILE! !INSDIR! > NUL 2>&1
		)
	    )
	)
    )
)

endlocal
exit /b  

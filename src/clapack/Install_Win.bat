@echo off
setlocal enabledelayedexpansion

rem ----------------------------------------------------------------------------
rem 下記のClapack関連のファイルを所定のディレクトリにコピーする。
rem 	blas<Ver><Config><Platform>.<suffix>
rem 	libf2c<Ver><Config><Platform>.<suffix>
rem 	clapack<Ver><Config><Platform>.<suffix>
rem 
rem     <Ver>		Visual Studioのツールセットバージョン
rem			第1引数で指定（省略可、デフォルトは 14.0）
rem	<Config>	'D', '', 'T' のそれぞれ
rem	<Platform>	'Win32', 'x64' のそれぞれ
rem	<suffix>	'lib', 'pdb' のそれぞれ
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
		rem  C の値が 'b' ならば '' に置き換える
		rem  変数 CONFIG の中に空白文字を指定するための仕組み
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

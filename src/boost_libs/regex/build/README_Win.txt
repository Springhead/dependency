Windows:
	このディレクトリで make.bat を実行する。

	Usage: make [options] arch target
	  options:
	    -m host      ビルドコンピュータアーキテクチャ { x86 | <x64> }
	    -t tool      ツールセット { vc90 | vc100 | vc110 | vc120 | <vc140> }
	    -l libdir    .lib をインストールするディレクトリ <../../../../lib>
	    -b bindir    .dll をインストールするディレクトリ <../../../../bin>
	  arguments:
	    arch         ターゲットコンピュータアーキテクチャ { x86 | x64 }
	    target       make のターゲット名 { build | install | clean | help | intro }
	                 ※ intro は新しいツールセットの導入方法の表示

	【例】64ビットマシン上で、32ビット用のlib/dllを作成しインストールする。
	      Visual Studio 2015
		  make [-m x64] [-t vc140] x86 build
		  make [-m x64] [-t vc140] x86 install
		  make [-m x64] [-t vc140] x86 install_pdb　（必要に応じて）
		  make [-m x64] [-t vc140] x86 clean
	      ※ [] 内は省略可。ターゲットは1回に1個のみ（build install などは不可）

	【註】ツールセット（vc140など）の調べ方は
		  make intro
	      に従う。

unix:
	

Windows:
	���̃f�B���N�g���� make.bat �����s����B

	Usage: make [options] arch target
	  options:
	    -m host      �r���h�R���s���[�^�A�[�L�e�N�`�� { x86 | <x64> }
	    -t tool      �c�[���Z�b�g { vc90 | vc100 | vc110 | vc120 | <vc140> }
	    -l libdir    .lib ���C���X�g�[������f�B���N�g�� <../../../../lib>
	    -b bindir    .dll ���C���X�g�[������f�B���N�g�� <../../../../bin>
	  arguments:
	    arch         �^�[�Q�b�g�R���s���[�^�A�[�L�e�N�`�� { x86 | x64 }
	    target       make �̃^�[�Q�b�g�� { build | install | clean | help | intro }
	                 �� intro �͐V�����c�[���Z�b�g�̓������@�̕\��

	�y��z64�r�b�g�}�V����ŁA32�r�b�g�p��lib/dll���쐬���C���X�g�[������B
	      Visual Studio 2015
		  make [-m x64] [-t vc140] x86 build
		  make [-m x64] [-t vc140] x86 install
		  make [-m x64] [-t vc140] x86 install_pdb�@�i�K�v�ɉ����āj
		  make [-m x64] [-t vc140] x86 clean
	      �� [] ���͏ȗ��B�^�[�Q�b�g��1���1�̂݁ibuild install �Ȃǂ͕s�j

	�y���z�c�[���Z�b�g�ivc140�Ȃǁj�̒��ו���
		  make intro
	      �ɏ]���B

unix:
	

#include "DxLib.h"
#include "game.h"

#include "SceneStart.h"
#include "SceneMain.h"
#include "SceneEnd.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// window���[�h�ݒ�
	ChangeWindowMode(Game::kWindowMode);
	// �E�C���h�E���ݒ�
	SetMainWindowText(Game::kTitleText);
	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);

	SceneStart scene_start;
	scene_start.init();
	SceneMain scene_main;
	scene_main.init();
	SceneEnd scene_end;
	scene_end.init();

	int sceneNum = 0;
	int space = 0;

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// ��ʂ̃N���A
		ClearDrawScreen();

		switch (sceneNum)
		{
		case 0:
			scene_start.update();
			scene_start.draw();
			if (CheckHitKey(KEY_INPUT_SPACE) == 0)
			{
				if (space > 0)
				{
					space = -1;
					sceneNum++;
				}
				else
				{
					space = 0;
				}
			}
			else
			{
				space++;
			}

			break;
		case 1:
			scene_main.update();
			scene_main.draw();
			if (CheckHitKey(KEY_INPUT_SPACE) == 0)
			{
				if (space > 0)
				{
					space = -1;
					sceneNum++;
				}
				else
				{
					space = 0;
				}
			}
			else
			{
				space++;
			}
			break;
		case 2:
			scene_end.update();
			scene_end.draw();
			break;
		}
		


		
		// ����ʂ�\��ʂɓ���ւ���
		ScreenFlip();

		// esc�L�[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// fps���U�O�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}

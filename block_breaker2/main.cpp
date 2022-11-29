#include "DxLib.h"
#include "game.h"

#include "SceneStart.h"
#include "SceneMain.h"
#include "SceneEnd.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// windowモード設定
	ChangeWindowMode(Game::kWindowMode);
	// ウインドウ名設定
	SetMainWindowText(Game::kTitleText);
	// 画面サイズの設定
	SetGraphMode(Game::kScreenWidth, Game::kScreenHeight, Game::kColorDepth);

	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	// ダブルバッファモード
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
		// 画面のクリア
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
		


		
		// 裏画面を表画面に入れ替える
		ScreenFlip();

		// escキーを押したら終了する
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// fpsを６０に固定
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

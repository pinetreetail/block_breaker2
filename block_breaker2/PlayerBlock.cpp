#include "PlayerBlock.h"

PlayerBlock::PlayerBlock()	:
	posX(0),
	posY(0),
	sizeX(0),
	sizeY(0),
	Color(0),
	SpeedMax(0),
	Acc(0),
	CurrSpeed(0)
{
}

PlayerBlock::~PlayerBlock()
{
}

void PlayerBlock::init()
{
	posX = 325;
	posY = 600;
	sizeX = 150;
	sizeY = 20;

	SpeedMax = 8;
	Acc = 4;

	Color = GetColor(255, 255, 0);
}

void PlayerBlock::update()
{
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (posX < 0) posX = 0;
	if (posX > Game::kScreenWidth - sizeX) posX = Game::kScreenWidth - sizeX;

	if (padState & PAD_INPUT_LEFT)
	{
		CurrSpeed -= Acc;
		if (CurrSpeed < -SpeedMax)	CurrSpeed = -SpeedMax;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		CurrSpeed += Acc;
		if (CurrSpeed > SpeedMax)	CurrSpeed = SpeedMax;
	}
	else
	{
		CurrSpeed *= 0.9f;
	}

	posX += CurrSpeed;
}

void PlayerBlock::draw()
{
	DrawBox(posX, posY, posX + sizeX, posY + sizeY, Color, false);
}
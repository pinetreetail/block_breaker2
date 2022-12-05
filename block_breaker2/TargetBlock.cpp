#include "TargetBlock.h"

TargetBlock::TargetBlock()	:
	posX(0),
	posY(0),
	sizeX(0),
	sizeY(0),
	Color(0),
	CurrDead(true)
{
}

TargetBlock::~TargetBlock()
{
}

void TargetBlock::init()
{
	posX = 0;	//140
	posY = 0;	//60
	sizeX = Game::kScreenWidth;
	sizeY = 50; //30

	CurrDead = false;

	Color = GetColor(0, 255, 255);
}

void TargetBlock::update()
{
}

void TargetBlock::draw()
{
	if (CurrDead)	return;

	DrawBox(posX, posY, posX + sizeX, posY + sizeY, Color, false);
}

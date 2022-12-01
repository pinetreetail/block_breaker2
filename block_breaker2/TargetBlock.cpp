#include "TargetBlock.h"

TargetBlock::TargetBlock()	:
	posX(0),
	posY(0),
	sizeX(0),
	sizeY(0),
	Color(0),
	CurrDead(false)
{
}

TargetBlock::~TargetBlock()
{
}

void TargetBlock::init()
{
	posX = 140;
	posY = 60;
	sizeX = 150;
	sizeY = 30;

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

#include "BouncingBall.h"

BouncingBall::BouncingBall() :
	posX(0),
	posY(0),
	width(0),
	Color(0),
	Speed(0),
	CurrSpeedX(0),
	CurrSpeedY(0),
	CurrDead(false)
{
}

BouncingBall::~BouncingBall()
{
}

void BouncingBall::init()
{
	posX = 100;
	posY = 100;
	width = 25;

	Speed = 8;
	CurrSpeedX = Speed;
	CurrSpeedY = Speed;

	Color = GetColor(0, 255, 0);
}

void BouncingBall::update()
{
	if (CurrDead)	return;

	if ((posX - width) < 0)
	{
		posX = width;
		CurrSpeedX = Speed;
	}
	else if (posX > Game::kScreenWidth - width)
	{
		posX = Game::kScreenWidth - width;
		CurrSpeedX = -Speed;
	}
	if ((posY - width) < 0)
	{
		posY = width;
		CurrSpeedY = Speed;
	}
	else if (posY > Game::kScreenHeight - width)
	{
		posY = Game::kScreenHeight - width;
		CurrSpeedY = -Speed;

//		m_isDead = true;
	}

	posX += CurrSpeedX;
	posY += CurrSpeedY;

}

void BouncingBall::draw()
{
	if (CurrDead)	return;

	DrawCircle(posX, posY, width, Color, false);
}
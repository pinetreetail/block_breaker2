#include "BlockPlayer.h"

BlockPlayer::BlockPlayer() :
	m_color(0),
	m_isFill(false)
{
}

BlockPlayer::~BlockPlayer()
{
}

void init()
{

}

void BlockPlayer::setPos(float x, float y)
{
	m_pos.x = x;
	m_pos.y = y;
}

void BlockPlayer::setPos(Vec2 pos)
{
	m_pos = pos;
}

void BlockPlayer::setSize(float x, float y)
{
	m_size.x = x;
	m_size.y = y;
}

void BlockPlayer::update()
{

}

void BlockPlayer::draw()
{
	DrawBox(m_pos.x, m_pos.y, m_pos.x + m_size.x, m_pos.y + m_size.y, m_color, m_isFill);
}
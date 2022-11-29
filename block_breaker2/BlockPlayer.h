#pragma once

#include "Vec2.h"
#include "DxLib.h"

class BlockPlayer
{
public:
	BlockPlayer();
	virtual~BlockPlayer();

	void init();

	void setPos(float x, float y);
	void setPos(Vec2 pos);

	void setSize(float x, float y);
	void setColor(unsigned int color) { m_color = color; }
	void setFill(bool fill) { m_isFill = fill; }

	void update();
	void draw();

	// ���̎擾
	Vec2 getPos() const { return m_pos; }
	Vec2 getSize() const { return m_size; }
	
private:
	Vec2 m_pos;
	Vec2 m_size;


	// �J���[
	unsigned int m_color;
	// �h��Ԃ�
	bool m_isFill;


};


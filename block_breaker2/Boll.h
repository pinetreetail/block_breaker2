#pragma once

#include "Vec2.h"

class Ball
{
public:
	Ball();
	virtual ~Ball();

	void init();

	// �f�[�^�̐ݒ�
	void setPos(float x, float y);
	void setPos(Vec2 pos);

	void setSize(float x);
	void setColor(unsigned int color) { m_color = color; }
	void setFill(bool fill) { m_isFill = fill; }

	void update();
	void draw();

	// ���̎擾
	Vec2 getPos() const { return m_pos; }
	bool isDead() const { return m_isDead; }

	bool collision();

private:

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;

	// �~�̔��a
	float m_radius;

	float m_vecX;		// X���W
	float m_vecY;		// Y���W

	unsigned int m_color;
	bool m_isFill;
	bool m_isDead;
};
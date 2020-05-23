#pragma once
#include "CGraphicObject.h"

class CBomb : public CGraphicObject
{
	bool Explosion;
	bool BombOnMap;
	float TimePassed;
public:
	// ���������� ������ -��; -���
	bool BombTick();
	// ��������� ��������
	void SetBombOnMap(bool info);
	// ���������� ��������
	bool BombIsOnMap();
	//���������� �� ���������
	CBomb();
	// ���������
	void Simulate(float Time);
	// ������� ������� ������
	bool Explode();
	// ���������� ������� ������
	void SetExplode(bool info);
	// ���������� ��������� �����
	float Percentage();
};

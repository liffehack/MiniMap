#pragma once
#include "CGraphicObject.h"

class CBomb : public CGraphicObject
{
	bool Explosion;
	bool BombOnMap;
	float TimePassed;
public:
	// происходит отсчет -да; -нет
	bool BombTick();
	// установка признака
	void SetBombOnMap(bool info);
	// считывание признака
	bool BombIsOnMap();
	//констрктор по умолчанию
	CBomb();
	// симуляция
	void Simulate(float Time);
	// считать признак взрыва
	bool Explode();
	// установить признак взрыва
	void SetExplode(bool info);
	// процентное состояние бомбы
	float Percentage();
};

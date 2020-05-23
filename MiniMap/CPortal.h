#pragma once
#include "CGameObject.h"

class CPortal :public CGameObject
{
	int Teleport_X, Teleport_Y;
	float TimePassed;
	CPortal *From;
	bool Teleported;
	bool TeleportPosSet;
public:
	CPortal(void);
	void SetTeleportTo(int X, int Y);
	void Simulate(float sec);
	void SetFrom(CPortal &From);
};
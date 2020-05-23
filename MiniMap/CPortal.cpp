#include "CPortal.h"
#include "Data.h"

const float TimeNeed = 1.0f;

CPortal::CPortal()
{
	Teleported = false;
	TeleportPosSet = false;
}

void CPortal::SetTeleportTo(int X, int Y)
{
	TeleportPosSet = true;
	Teleport_X = X;
	Teleport_Y = Y;
}

void CPortal::Simulate(float sec)
{
	if (!TeleportPosSet) return;
	int x, y,xp,yp;
	Player.GetLogicPosition(x, y);
	GetLogicPosition(xp, yp);
	if ((x == xp)&(y == yp))
	{
		if (!(From->Teleported))
		{
			TimePassed = TimePassed + sec;
			if (TimePassed >= TimeNeed)
			{
				Player.SetLogicPosition(Teleport_X, Teleport_Y);
				Player.SetPosition(Teleport_X - 10.0f, 0.5f, Teleport_Y - 10.0f);
				TimePassed = 0.0f;
				Teleported = true;
				From->Teleported = false;
			}
		}
	}
	else
	{
		if (From->Teleported)
			From->Teleported = false;
		TimePassed = 0.0f;
	}
}

void CPortal::SetFrom(CPortal &From)
{
	this->From = &From;
}
#include "CBomb.h"

const float TimeLeft = 2.0f;

CBomb::CBomb()
{
	TimePassed = 0.0f;
	BombOnMap = false;
	Explosion = false;
}

bool CBomb::BombIsOnMap()
{
	if(BombOnMap)
	return true;
	else return false;
}

void CBomb::SetBombOnMap(bool info)
{
	BombOnMap = info;
}

void CBomb::Simulate(float Time)
{
	TimePassed =TimePassed + Time;
	if (TimePassed >= TimeLeft)
	{
		TimePassed = 0.0f;
		Explosion = true;
		BombOnMap = false;
	}
}

bool CBomb::BombTick()
{
	if (TimePassed != 0.0f)
		return true;
	else 
		return false;
}

bool CBomb::Explode()
{
	if (Explosion)
		return true;
	else return false;
}

void CBomb::SetExplode(bool info)
{
	Explosion = info;
}

float CBomb::Percentage()
{
	return (TimePassed/TimeLeft);
}
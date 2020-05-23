#include "Simulation.h"
void Simulation(void)
{
	// Считывание клавиш перемещения КАМЕРЫ
	ReadKeysForCamera();
	//считывание клавиш перемещения объекта
	if (!Player.IsMoving())
	{
		BombProcessing();
		if (GameObjects[IND_X][IND_Z].HasMove())
		{
			GameObjectsProcessing();
		}
		ReadKeysForPlayer();
		//запуск обработки движения, если была нажата хоть 1 клавиша
		PlayerProcessing();
	}
	//получение вермени между запусками simulate
	QueryPerformanceCounter(&newvalue);
	QueryPerformanceFrequency(&freq);
	sec = GLfloat(newvalue.QuadPart - oldvalue.QuadPart) / freq.QuadPart;
	//получение fps
	GetFps();
	oldvalue = newvalue;
	SimulateBomb();
	//запуск преобразования координат с учетом прошедшего времени
	if (!Left & !Right & !Forward & !Backward)
	{
		for (int i = 0; i < PortalCount; i++)
			Portal[i].Simulate(sec);
	}
	Player.Simulate(sec);
	GameObjects[IND_X][IND_Z].Simulate(sec);
	Camera.Simulate(sec);
	glutPostRedisplay();
};

float MinimapX()
{
	return 45 * cos(89 * M_PI / 180.0f)*(cos(Camera.GetYaw() * M_PI / 180.0f));
}

float MinimapZ()
{
	return 45 * cos(89 * M_PI / 180.0f)*(sin(Camera.GetYaw()* M_PI / 180.0f));
}

void GetMove(bool &left, bool &right, bool &forward, bool &backward)
{
	int x, y;
	Player.GetLogicPosition(x, y);
	if (x + 2 <= 20)
	{
		if ((PassabilityMap[x + 1][y] == 3) || ((PassabilityMap[x + 1][y] == 1) & (PassabilityMap[x + 2][y] != 0)))
			right = false;
	}
	else right = false;
	if (x - 2 >= 0)
	{
		if ((PassabilityMap[x - 1][y] == 3) || ((PassabilityMap[x - 1][y] == 1) & (PassabilityMap[x - 2][y] != 0)))
			left = false;
	}
	else left = false;
	if (y + 2 <= 20)
	{
		if ((PassabilityMap[x][y + 1] == 3) || ((PassabilityMap[x][y + 1] == 1) & (PassabilityMap[x][y + 2] != 0)))
			backward = false;
	}
	else backward = false;
	if (y - 2 >= 0)
	{
		if ((PassabilityMap[x][y - 1] == 3) || ((PassabilityMap[x][y - 1] == 1) & (PassabilityMap[x][y - 2] != 0)))
			forward = false;
	}
	else forward = false;
	if (left)
	{
		right = forward = backward = false;
		if (x - 2 >= 0)
		{
			if ((PassabilityMap[x - 1][y] == 1) & (PassabilityMap[x - 2][y] == 0))
			{
				GameObjects[x - 1][y].SetKey(left, right, forward, backward);
				IND_X = x - 1;
				IND_Z = y;
				ML = true;
			}
		}
	}
	if (right)
	{
		left = forward = backward = false;
		if (x + 2 <= 20)
		{
			if ((PassabilityMap[x + 1][y] == 1) & (PassabilityMap[x + 2][y] == 0))
			{
				GameObjects[x + 1][y].SetKey(left, right, forward, backward);
				IND_X = x + 1;
				IND_Z = y;
				MR = true;
			}
		}
	}
	if (forward)
	{
		left = right = backward = false;
		if (y - 2 >= 0)
		{
			if ((PassabilityMap[x][y - 1] == 1) & (PassabilityMap[x][y - 2] == 0))
			{
				GameObjects[x][y - 1].SetKey(left, right, forward, backward);
				IND_X = x;
				IND_Z = y - 1;
				MF = true;
			}
		}
	}
	if (backward)
	{
		forward = left = right = false;
		if (y + 2 <= 20)
		{
			if ((PassabilityMap[x][y + 1] == 1) & (PassabilityMap[x][y + 2] == 0))
			{
				GameObjects[x][y + 1].SetKey(left, right, forward, backward);
				IND_X = x;
				IND_Z = y + 1;
				MB = true;
			}
		}
	}
}

void ReadKeyForBomb()
{
	if (GetAsyncKeyState(' ') & 1)
		Bomb.SetBombOnMap(true);
	else Bomb.SetBombOnMap(false);
}

void SimulateBomb()
{
	if (Bomb.BombIsOnMap())
	{
		Bomb.Simulate(sec);
	}
}

void ExplodeGameObjectsAround()
{
	//x
	if (PassabilityMap[CUR_POSX + 1][CUR_POSY] == 1)
	{
		GameObjects[CUR_POSX + 1][CUR_POSY] = CGameObject();
		PassabilityMap[CUR_POSX + 1][CUR_POSY] = 0;
	}
	if (PassabilityMap[CUR_POSX - 1][CUR_POSY] == 1)
	{
		GameObjects[CUR_POSX - 1][CUR_POSY] = CGameObject();
		PassabilityMap[CUR_POSX - 1][CUR_POSY] = 0;
	}
	//x&y
	if (PassabilityMap[CUR_POSX + 1][CUR_POSY + 1] == 1)
	{
		GameObjects[CUR_POSX + 1][CUR_POSY + 1] = CGameObject();
		PassabilityMap[CUR_POSX + 1][CUR_POSY + 1] = 0;
	}
	if (PassabilityMap[CUR_POSX - 1][CUR_POSY - 1] == 1)
	{
		GameObjects[CUR_POSX - 1][CUR_POSY - 1] = CGameObject();
		PassabilityMap[CUR_POSX - 1][CUR_POSY - 1] = 0;
	}
	if (PassabilityMap[CUR_POSX + 1][CUR_POSY - 1] == 1)
	{
		GameObjects[CUR_POSX + 1][CUR_POSY - 1] = CGameObject();
		PassabilityMap[CUR_POSX + 1][CUR_POSY - 1] = 0;
	}
	if (PassabilityMap[CUR_POSX - 1][CUR_POSY + 1] == 1)
	{
		GameObjects[CUR_POSX - 1][CUR_POSY + 1] = CGameObject();
		PassabilityMap[CUR_POSX - 1][CUR_POSY + 1] = 0;
	}
	//y
	if (PassabilityMap[CUR_POSX][CUR_POSY - 1] == 1)
	{
		GameObjects[CUR_POSX][CUR_POSY - 1] = CGameObject();
		PassabilityMap[CUR_POSX][CUR_POSY - 1] = 0;
	}
	if (PassabilityMap[CUR_POSX][CUR_POSY + 1] == 1)
	{
		GameObjects[CUR_POSX][CUR_POSY + 1] = CGameObject();
		PassabilityMap[CUR_POSX][CUR_POSY + 1] = 0;
	}
}

void BombProcessing()
{
	if (!Bomb.BombTick())
		ReadKeyForBomb();
	if (Bomb.Explode())
	{
		PassabilityMap[CUR_POSX][CUR_POSY] = 0;
		ExplodeGameObjectsAround();
		Bomb.SetExplode(false);
	}
	if (Bomb.BombIsOnMap() & !Bomb.BombTick())
	{
		Player.GetLogicPosition(CUR_POSX, CUR_POSY);
		Bomb.SetPosition(Player.RetX(), Player.RetY(), Player.RetZ());
		PassabilityMap[CUR_POSX][CUR_POSY] = 3;
	}
}

void GetFps()
{
	fps++;
	summ_sec = summ_sec + sec;
	if (summ_sec >= 1)
	{
		sprintf(OutTitle, "Gl lab #5 %d", fps);
		glutSetWindowTitle(OutTitle);
		summ_sec = 0.0;
		fps = 0;
	}
}

void GameObjectsProcessing()
{
	if (ML)
	{
		GameObjects[IND_X][IND_Z].CopyTo(GameObjects[IND_X - 1][IND_Z]);
		PassabilityMap[IND_X][IND_Z] = 0;
		PassabilityMap[IND_X - 1][IND_Z] = 1;
		GameObjects[IND_X][IND_Z] = CGameObject();
		MF = MR = MB = false;
	}
	if (MR)
	{
		GameObjects[IND_X][IND_Z].CopyTo(GameObjects[IND_X + 1][IND_Z]);
		PassabilityMap[IND_X][IND_Z] = 0;
		PassabilityMap[IND_X + 1][IND_Z] = 1;
		GameObjects[IND_X][IND_Z] = CGameObject();
		MF = ML = MB = false;
	}
	if (MB)
	{
		GameObjects[IND_X][IND_Z].CopyTo(GameObjects[IND_X][IND_Z + 1]);
		PassabilityMap[IND_X][IND_Z] = 0;
		PassabilityMap[IND_X][IND_Z + 1] = 1;
		GameObjects[IND_X][IND_Z] = CGameObject();
		MF = ML = MR = false;
	}
	if (MF)
	{
		GameObjects[IND_X][IND_Z].CopyTo(GameObjects[IND_X][IND_Z - 1]);
		PassabilityMap[IND_X][IND_Z] = 0;
		PassabilityMap[IND_X][IND_Z - 1] = 1;
		GameObjects[IND_X][IND_Z] = CGameObject();
		MR = ML = MB = false;
	}
	GameObjects[IND_X][IND_Z].SetHas(false);
	MB = ML = MF = MR = false;
}

void ReadKeysForCamera()
{
	Camera.SetKey(GetAsyncKeyState(VK_LEFT), GetAsyncKeyState(VK_RIGHT), GetAsyncKeyState(VK_UP),
		GetAsyncKeyState(VK_DOWN), GetAsyncKeyState(VK_ADD), GetAsyncKeyState(VK_SUBTRACT));
	Camera.SetShift(GetAsyncKeyState(VK_RSHIFT) | GetAsyncKeyState(VK_LSHIFT));
}

void ReadKeysForPlayer()
{
	Left = GetAsyncKeyState('A');
	Right = GetAsyncKeyState('D');
	Forward = GetAsyncKeyState('W');
	Backward = GetAsyncKeyState('S');
}

void PlayerProcessing()
{
	if (Left || Right || Forward || Backward)
	{
		if (Camera.GetYaw() > 315 || Camera.GetYaw() <= 45)
		{
			GetMove(Forward, Backward, Right, Left);
			Player.SetKey(Forward, Backward, Right, Left);
		}
		if (Camera.GetYaw() > 45 && Camera.GetYaw() <= 135)
		{
			GetMove(Left, Right, Forward, Backward);
			Player.SetKey(Left, Right, Forward, Backward);
		}
		if (Camera.GetYaw() > 135 && Camera.GetYaw() <= 225)
		{
			GetMove(Backward, Forward, Left, Right);
			Player.SetKey(Backward, Forward, Left, Right);
		}
		if (Camera.GetYaw() > 225 && Camera.GetYaw() <= 315)
		{
			GetMove(Right, Left, Backward, Forward);
			Player.SetKey(Right, Left, Backward, Forward);
		}
	}
}

void CountBombSprites()
{
	if ((Bomb.Percentage()>0.0f) & (Bomb.Percentage() < 0.25f))
	{
		BombSpriteCount = 4;
		return;
	}
	if ((Bomb.Percentage() < 0.5f) & (Bomb.Percentage() > 0.25f))
	{
		BombSpriteCount = 3;
		return;
	}
	if ((Bomb.Percentage() > 0.5f) & (Bomb.Percentage() < 0.75))
	{
		BombSpriteCount = 2;
		return;
	}
	if ((Bomb.Percentage() > 0.75f) & (Bomb.Percentage() < 1.0f))
	{
		BombSpriteCount = 1;
		return;
	}
	if (Bomb.Percentage() == 0.0f)
	{
		BombSpriteCount = 0;
		return;
	}
}
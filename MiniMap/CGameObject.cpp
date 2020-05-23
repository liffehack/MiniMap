#include "CGameObject.h"
#include "Camera.h"
#include <iostream>

const GLfloat MOVEMENT_SPEED = 5.0;
GLfloat CALCULATED_SPEED;


CGameObject::CGameObject(): CGraphicObject()
{
	X = 0;
	Z = 0;
	direction = 0;
	progress = 0;
	moving = false;
	MoveEnded = false;
}

CGameObject::CGameObject(GLint X_, GLint Z_)
{
	X = X_;
	Z = Z_;
	direction = 0;
	progress = 0;
	moving = false;
	SetModel(NULL);
}

bool CGameObject::HasMove()
{
	return MoveEnded;
}

void CGameObject::SetHas(bool idk)
{
	MoveEnded = idk;
}

void CGameObject::CopyTo(CGameObject &obj)
{
	obj.X = X;
	obj.Z = Z;
	obj.direction = direction;
	obj.progress = progress;
	obj.moving = moving;
	obj.SetMaterial(&GetMaterial());
	obj.SetModel(&GetModel());
	obj.SetPosition(RetX(), 0.5, RetZ());
}

void CGameObject::SetLogicPosition(int x_, int z_)
{
	X = x_;
	Z = z_;
}

void CGameObject::GetLogicPosition(int &x, int &z)
{
	x=X;
	z=Z;
}

bool CGameObject::IsMoving()
{
	if (moving)
		return true;
	else return false;
}

void CGameObject::Left()
{
	moving = true;
	progress = progress + CALCULATED_SPEED;
	Position[0] = Position[0] - CALCULATED_SPEED;
	if (progress >= 1)
	{
		X = X - 1;
		Position[0] = OldPosition[0]-1;
		OldPosition[0] = Position[0];
		progress = 0;
		moving = false;
		MoveRight = MoveLeft = MoveBackward = MoveForward = false;
		SetHas(true);
	}
	SetMatrixModel();
}

void CGameObject::Right()
{
	moving = true;
	progress = progress + CALCULATED_SPEED;
	Position[0] = Position[0] + CALCULATED_SPEED;
	if (progress >= 1)
	{
		X = X + 1;
		Position[0] = OldPosition[0]+1;
		OldPosition[0] = Position[0];
		progress = 0;
		moving = false;
		MoveRight = MoveLeft = MoveBackward = MoveForward = false;
		SetHas(true);
	}
	SetMatrixModel();
}

void CGameObject::Backward()
{
	moving = true;
	progress = progress + CALCULATED_SPEED;
	Position[2] = Position[2] + CALCULATED_SPEED;
	if (progress >= 1)
	{
		Z = Z + 1;
		Position[2] = OldPosition[2] + 1;
		OldPosition[2] = Position[2];
		progress = 0;
		moving = false;
		MoveRight = MoveLeft = MoveBackward = MoveForward = false;
		SetHas(true);
	}
	SetMatrixModel();
}

void CGameObject::Forward()
{
	moving = true;
	progress = progress + CALCULATED_SPEED;
	Position[2] = Position[2] - CALCULATED_SPEED;
	if (progress >= 1)
	{
		Z = Z - 1;
		Position[2] = OldPosition[2] - 1;
		OldPosition[2] = Position[2];
		progress = 0;
		moving = false;
		MoveRight = MoveLeft = MoveBackward = MoveForward = false;
		SetHas(true);
	}
	SetMatrixModel();
}

void CGameObject::Simulate(GLfloat &sec_)
{
	CALCULATED_SPEED = sec_*MOVEMENT_SPEED;
	if (MoveBackward)
	{
		MoveForward = MoveRight = MoveLeft = false;
		Backward();
	}
	if (MoveForward)
	{
		MoveBackward = MoveRight = MoveLeft = false;
		Forward();
	}
	if (MoveRight)
	{
		MoveBackward = MoveForward = MoveLeft = false;
		Right();
	}
	if (MoveLeft)
	{
		MoveBackward = MoveForward = MoveRight = false;
		Left();
	}
}

void CGameObject::SetKey(GLboolean Left, GLboolean Right, GLboolean Forward, GLboolean Backward)
{
	MoveRight = Right;
	MoveLeft = Left;
	MoveBackward = Backward;
	MoveForward = Forward;
}

float CGameObject::GetProgress()
{
	return progress;
}

void CGameObject::SetDirection(GLint dir)
{
	direction = dir;
}
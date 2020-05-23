#pragma once
#include "CGraphicObject.h"



// ������� ������
class CGameObject : public CGraphicObject
{
	// ���������� ������� �������� �������
	int X, Z;
	// ����������� ����������� �������� �������
	int direction;
	// �������� � ����������� (�� 0 �� 1)
	float progress;
	GLboolean moving;
	GLboolean MoveEnded;
	GLboolean MoveForward, MoveBackward, MoveLeft, MoveRight;
public:
	// �����������
	CGameObject();
	//
	CGameObject(GLint X_, GLint Z_);
	// ���������� ��������� ������� �������� �������
	void SetLogicPosition(int x, int z);
	// �������� ������� �������� �������
	void GetLogicPosition(int &x, int &z);
	// ����������, ��������� �� ������� ������ � �������� ��������
	bool IsMoving();
	// ������ �������� �����
	void Left(void);
	// ������ �������� ������
	void Right(void);
	// ������ �������� ������
	void Forward(void);
	// ������ �������� �����
	void Backward(void);
	//set key
	void SetKey(GLboolean Left, GLboolean Right, GLboolean Forward, GLboolean Backward);
	//simulate the movement
	void Simulate(GLfloat &sec_);
	//get progress
	float GetProgress();
	//set direction
	void SetDirection(GLint dir);
	//copy
	void CopyTo(CGameObject &obj);
	//
	bool HasMove();
	void SetHas(bool idk);
};
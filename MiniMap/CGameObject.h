#pragma once
#include "CGraphicObject.h"



// ИГРОВОЙ ОБЪЕКТ
class CGameObject : public CGraphicObject
{
	// логическая позиция игрового объекта
	int X, Z;
	// направление перемещение игрового объекта
	int direction;
	// прогресс в перемещении (от 0 до 1)
	float progress;
	GLboolean moving;
	GLboolean MoveEnded;
	GLboolean MoveForward, MoveBackward, MoveLeft, MoveRight;
public:
	// КОНСТРУКТОР
	CGameObject();
	//
	CGameObject(GLint X_, GLint Z_);
	// УСТАНОВИТЬ НАЧАЛЬНУЮ ПОЗИЦИЮ ИГРОВОГО ОБЪЕКТА
	void SetLogicPosition(int x, int z);
	// ПОЛУЧИТЬ ПОЗИЦИЮ ИГРОВОГО ОБЪЕКТА
	void GetLogicPosition(int &x, int &z);
	// ОПРЕДЕЛИТЬ, НАХОДИТСЯ ЛИ ИГРОВОЙ ОБЪЕКТ В ПРОЦЕССЕ ДВИЖЕНИЯ
	bool IsMoving();
	// НАЧАТЬ ДВИЖЕНИЕ ВЛЕВО
	void Left(void);
	// НАЧАТЬ ДВИЖЕНИЕ ВПРАВО
	void Right(void);
	// НАЧАТЬ ДВИЖЕНИЕ ВПЕРЕД
	void Forward(void);
	// НАЧАТЬ ДВИЖЕНИЕ НАЗАД
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
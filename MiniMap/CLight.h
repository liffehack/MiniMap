#pragma once
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"

class CLight
{
	// позиция источника света
	GLfloat Position[4];
	// фоновая составляющая источника света
	GLfloat Ambient[4];
	// диффузная составляющая
	GLfloat Diffuse[4];
	// зеркальная составляющая
	GLfloat Specular[4];
	//matrix
	GLfloat Matrix[16];
public:
	// конструктор по умолчанию
	CLight(void);
	// задание различных параметров источника света
	void SetPosition(float x, float y, float z);
	void SetAmbient(float r, float g, float b);
	void SetDiffuse(float r, float g, float b);
	void SetSpecular(float r, float g, float b);
	// установка всех параметров источника света с заданным номером
	// данная функция должна вызываться после установки камеры,
	// т.к. здесь устанавливается позиция источника света
	void Apply(GLenum LightNumber);
	// вывод источника света в виде маленького шарика для отладки
	void Draw(void);
};
#pragma once
#include <Windows.h>
#include <glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "CMaterial.h"

class CPhongMaterial:public CMaterial
{
protected:
	// фонова€ составл€юща€
	GLfloat Ambient[4];
	// диффузна€ составл€юща€
	GLfloat Diffuse[4];
	// зеркальна€ составл€юща€
	GLfloat Specular[4];
	// самосвечение
	GLfloat Emission[4];
	// степень отполированности
	GLfloat Shininess;
public:
	static CPhongMaterial Default;
	// режим вывод материала:
	// [только фонова€, только диффузна€, только зеркальна€ или все составл€ющие]
	// конструктор по умолчанию
	CPhongMaterial(void);
	CPhongMaterial(bool def);
	// задание параметров материала
	void SetDiffuse(float r, float g, float b, float a = 1.0f);
	void SetAmbient(float r, float g, float b);
	void SetSpecular(float r, float g, float b);
	void SetEmission(float r, float g, float b);
	void SetShininess(float p);
	void SetAmbient(float k);
	void SetSpecular(float k);
	void SetEmission(float k);
	// установка всех параметров материала
	void Apply(void);
	bool IsTransparent(void);
};
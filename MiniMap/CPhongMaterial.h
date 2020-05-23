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
	// ������� ������������
	GLfloat Ambient[4];
	// ��������� ������������
	GLfloat Diffuse[4];
	// ���������� ������������
	GLfloat Specular[4];
	// ������������
	GLfloat Emission[4];
	// ������� ����������������
	GLfloat Shininess;
public:
	static CPhongMaterial Default;
	// ����� ����� ���������:
	// [������ �������, ������ ���������, ������ ���������� ��� ��� ������������]
	// ����������� �� ���������
	CPhongMaterial(void);
	CPhongMaterial(bool def);
	// ������� ���������� ���������
	void SetDiffuse(float r, float g, float b, float a = 1.0f);
	void SetAmbient(float r, float g, float b);
	void SetSpecular(float r, float g, float b);
	void SetEmission(float r, float g, float b);
	void SetShininess(float p);
	void SetAmbient(float k);
	void SetSpecular(float k);
	void SetEmission(float k);
	// ��������� ���� ���������� ���������
	void Apply(void);
	bool IsTransparent(void);
};
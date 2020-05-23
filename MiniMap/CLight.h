#pragma once
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"

class CLight
{
	// ������� ��������� �����
	GLfloat Position[4];
	// ������� ������������ ��������� �����
	GLfloat Ambient[4];
	// ��������� ������������
	GLfloat Diffuse[4];
	// ���������� ������������
	GLfloat Specular[4];
	//matrix
	GLfloat Matrix[16];
public:
	// ����������� �� ���������
	CLight(void);
	// ������� ��������� ���������� ��������� �����
	void SetPosition(float x, float y, float z);
	void SetAmbient(float r, float g, float b);
	void SetDiffuse(float r, float g, float b);
	void SetSpecular(float r, float g, float b);
	// ��������� ���� ���������� ��������� ����� � �������� �������
	// ������ ������� ������ ���������� ����� ��������� ������,
	// �.�. ����� ��������������� ������� ��������� �����
	void Apply(GLenum LightNumber);
	// ����� ��������� ����� � ���� ���������� ������ ��� �������
	void Draw(void);
};
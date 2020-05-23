#pragma once
#include "glew.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "IL/il.h"
#include "IL/ilu.h"
#include "IL/ilut.h"
#include <iostream>

// ����� ��� ������ � ���������
class CTexture
{
	// ������ ����������� �������
	GLuint TexIndex;
public:
	// ����� ���������� (��������, ����������, ��������� ������, ����������� � �.�.)
	static int TexFilterMode;
	// �������� �������� �� �������� �����
	void Load(char *filename);
	// ���������� ��������
	void Apply(void);
	// ���������� ��������������� �� ���� ���������� ������
	static void Disable(void);
};
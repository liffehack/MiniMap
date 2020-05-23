#pragma once
#include "glew.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "IL/il.h"
#include "IL/ilu.h"
#include "IL/ilut.h"
#include <iostream>

// ����� ��� ������ �� ��������
class CSprite {
	// ������������� ������� DevIL
	ILuint ImageId;
	// ������ �������� ������������ �����������
	// ������ ������ GL_RGBA, GL_UNSIGNED_BYTE
	ILubyte *Data;
	// ������ �����������
	int width;
	// ������ �����������
	int height;
	// ����� OpenGL ��� �������� ������� ��������
	GLuint bufferID;
public:
	// ������� ���� (������ � ������)
	static int ScreenWidth;
	static int ScreenHeight;
	// �����������
	CSprite(void);
	// �������� ����������� �� �������� �����
	void Load(char *fileName, bool flip = false);
	// ����� ������� ������������ �������� ������ ���� ����
	void DrawFromLeftUp(int x, int y);
	// ����� ������� ������������ �������� ������� ���� ����
	void DrawFromRightUp(int x, int y);
	// ��������� ������ �������
	int GetSpriteWidth(void);
};
#pragma once
#include <Windows.h>
#include <glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <fstream>
#include <iostream>
#include <iomanip>

//��������� �����
#pragma pack(push, 1)
struct t_chunc_header
{
	WORD id;//������������� �����
	DWORD len;//����� �����
};
#pragma pack(pop)

// ���������, ����������� ���� �������
// ������ ������� ����� �������������� ���������� � ����
struct ModelPoint
{
	// �������������� ����������
	GLfloat Coord[3];
	// ����
	GLubyte Color[3];
	//�������
	GLfloat Normal[3];
	//���������� ���������� �������� �����
	GLfloat TexCoord[2];
};

class CModel
{
	// ������ ������ ������
	ModelPoint *Points;
	// ������ �������� ������
	GLushort *Indeces;
	// ���������� ��������
	int IndexCount;
	// ���������� �����
	int PointCount;
	// �������� � ���������� ������� VBO �� ����� ��������� ��������� ��������
	void FillVBO(void);
	GLuint VBO_Index[2];
public:
	static bool USING_NORMALS;
	// ������� ������������� ������������ ����� VBO
	//static bool VBO_Use;
	// �����������
	CModel(void);
	//����������
	~CModel();
	// ������� ����� ������� �������
	void CreateBox(GLfloat w, GLfloat d, GLfloat h);
	// ������� ��������� ������� ������� (width)
	void CreatePlane(GLfloat Size,GLuint Width, GLuint SegCount);
	// ����� ������
	void Draw(void);
	// ��������� �������
	void CalcNormals(ModelPoint *a, ModelPoint *b, ModelPoint *c);
	//�������� ������
	void LoadModel(char* FileName);
	//���������� ���������� ���������
	void saveTexCoords(std::ifstream *file, short count, ModelPoint *pointArray);
};
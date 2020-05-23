#pragma once
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"

// ����� ��� ������ � ������� 
class CCamera
{
	// properties  ...
	GLdouble r;
	GLdouble sec;

	GLboolean left, right, up, down, forward, backward, shift;

	GLdouble Position[3];
	GLfloat pitch, yaw;

public:
	// default - load from file
	CCamera(char* ch = "");
	// ��������� ��������� ������� ������ 
	//read keys
	void SetKey(bool left_, bool right_, bool up_, bool down_, bool forward_, bool backward_);
	//shift speed
	void SetShift(bool shift);
	// sec - ���������� ������ ��������� � ������� ���������� ������ 
	void Simulate(GLfloat &sec_);
	// ������� ��� ��������� ������� ������  
	void Apply();
	//get yaw
	GLfloat GetYaw();
	//������ �� �����
	bool read_file(char*);
	//������ � ����
	bool write_file(char* ch = "outfile");
};
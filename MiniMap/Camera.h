#pragma once
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"

// КЛАСС ДЛЯ РАБОТЫ С КАМЕРОЙ 
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
	// установка признаков нажатых клавиш 
	//read keys
	void SetKey(bool left_, bool right_, bool up_, bool down_, bool forward_, bool backward_);
	//shift speed
	void SetShift(bool shift);
	// sec - количество секунд прошедших с момента последнего вызова 
	void Simulate(GLfloat &sec_);
	// функция для установки матрицы камеры  
	void Apply();
	//get yaw
	GLfloat GetYaw();
	//Чтение из файла
	bool read_file(char*);
	//Запись в файл
	bool write_file(char* ch = "outfile");
};
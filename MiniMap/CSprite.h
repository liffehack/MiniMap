#pragma once
#include "glew.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "IL/il.h"
#include "IL/ilu.h"
#include "IL/ilut.h"
#include <iostream>

// КЛАСС ДЛЯ РАБОТЫ СО СПРАЙТОМ
class CSprite {
	// идентификатор объекта DevIL
	ILuint ImageId;
	// массив пикселей загруженного изображения
	// формат всегда GL_RGBA, GL_UNSIGNED_BYTE
	ILubyte *Data;
	// ширина изображения
	int width;
	// высота изображения
	int height;
	// буфер OpenGL для хранения массива текселей
	GLuint bufferID;
public:
	// размеры окна (ширина и высота)
	static int ScreenWidth;
	static int ScreenHeight;
	// конструктор
	CSprite(void);
	// загрузка изображения из внешнего файла
	void Load(char *fileName, bool flip = false);
	// вывод спрайта относительно верхнего левого угла окна
	void DrawFromLeftUp(int x, int y);
	// вывод спрайта относительно верхнего правого угла окна
	void DrawFromRightUp(int x, int y);
	// получение ширины спрайта
	int GetSpriteWidth(void);
};
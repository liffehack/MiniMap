#pragma once
#include "glew.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "IL/il.h"
#include "IL/ilu.h"
#include "IL/ilut.h"
#include <iostream>

// КЛАСС ДЛЯ РАБОТЫ С ТЕКСТУРОЙ
class CTexture
{
	// индекс текстурного объекта
	GLuint TexIndex;
public:
	// режим фильтрации (точечная, билинейная, ближайший мипмап, трилинейная и т.д.)
	static int TexFilterMode;
	// загрузка текстуры из внешнего файла
	void Load(char *filename);
	// применение текстуры
	void Apply(void);
	// Отключение текстурирования во всех текстурных блоках
	static void Disable(void);
};
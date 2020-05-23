#pragma once
#include <Windows.h>
#include <glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <fstream>
#include <iostream>
#include <iomanip>

//заголовок чанка
#pragma pack(push, 1)
struct t_chunc_header
{
	WORD id;//идентификатор чанка
	DWORD len;//длина чанка
};
#pragma pack(pop)

// Структура, описывающая одну вершину
// каждая вершина имеет геометрические координаты и цвет
struct ModelPoint
{
	// геометрические координаты
	GLfloat Coord[3];
	// цвет
	GLubyte Color[3];
	//нормаль
	GLfloat Normal[3];
	//текстурные координаты нулевого блока
	GLfloat TexCoord[2];
};

class CModel
{
	// массив вершин модели
	ModelPoint *Points;
	// массив индексов модели
	GLushort *Indeces;
	// количество индексов
	int IndexCount;
	// количество точек
	int PointCount;
	// создание и заполнение буферов VBO из ранее созданных вершинных массивов
	void FillVBO(void);
	GLuint VBO_Index[2];
public:
	static bool USING_NORMALS;
	// признак необходимости использовать буфер VBO
	//static bool VBO_Use;
	// конструктор
	CModel(void);
	//деструктор
	~CModel();
	// создаем кубик нужного размера
	void CreateBox(GLfloat w, GLfloat d, GLfloat h);
	// создаем плоскость нужного размера (width)
	void CreatePlane(GLfloat Size,GLuint Width, GLuint SegCount);
	// вывод модели
	void Draw(void);
	// высчитать нормали
	void CalcNormals(ModelPoint *a, ModelPoint *b, ModelPoint *c);
	//загрузка модели
	void LoadModel(char* FileName);
	//считывание текстурных координат
	void saveTexCoords(std::ifstream *file, short count, ModelPoint *pointArray);
};
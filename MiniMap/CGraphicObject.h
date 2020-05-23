#pragma once
#include <Windows.h>
#include "CModel.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "math.h"
#include "CMaterial.h"


class CGraphicObject
{
protected:
	//position and angle
	GLfloat OldPosition[3];
	GLfloat Position[3];
	GLfloat Angle;
	//matrix model
	GLfloat ModelMatrix[16];
	GLfloat a;
	CModel *Model;
	CMaterial *Material;
public:
	//construct
	CGraphicObject(float x = 0, float y = 0, float z = 0, float a = 0);
	//set object position
	void SetPosition(GLfloat x, GLfloat y, GLfloat z);
	//set angle by OY
	void SetAngle(float a);
	//draw the object
	void Draw(void);
	//set matrix model
	void SetMatrixModel();
	//rotate on the circe
	void Rotate_Around(float x, float y, float z, float r);
	//init a
	void CopyAngle();
	//return X
	GLfloat RetX();
	//return Y
	GLfloat RetY();
	//return Z
	GLfloat RetZ();
	//set model
	void SetModel(CModel *Model);
	//get model
	CModel& GetModel();
	void SetMaterial(CMaterial *Material);
	CMaterial& GetMaterial();
	bool IsTransparent(void);
};
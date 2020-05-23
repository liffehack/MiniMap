#include "CGraphicObject.h"
#include "windows.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"
#include "Data.h"
#include <cmath>
#define _USE_MATH_DEFINES
#include <iostream>

//construct
CGraphicObject::CGraphicObject(float x,float y, float z, float A)
{
	Angle = A;
	Position[0] = x;
	Position[1] = y;
	Position[2] = z;
	a = A;
	Model = nullptr;
	Material = nullptr;
}

//set object position
void CGraphicObject::SetPosition(GLfloat x,GLfloat y,GLfloat z)
{
	Position[0] = x;
	Position[1] = y;
	Position[2] = z;
	OldPosition[0] = Position[0];
	OldPosition[1] = Position[1];
	OldPosition[2] = Position[2];
	SetMatrixModel();
}
void CGraphicObject::CopyAngle()
{
	a = Angle;
}
//set the angle by OY
void CGraphicObject::SetAngle(float a)
{
	Angle = a;
}

void CGraphicObject::SetModel(CModel *Model)
{
	this->Model = Model;
}

//draw object
void CGraphicObject::Draw(void)
{
	
	if (Model == nullptr)
	{
		return;
	}
	Material->Apply();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(ModelMatrix);
	Model->Draw();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
}

//set matrix model
void CGraphicObject::SetMatrixModel()
{
	ModelMatrix[0] = cos(Angle * 3.14 / 180.0f);
	ModelMatrix[1] = 0;
	ModelMatrix[2] = -sin(Angle * 1.14 / 180.0f);
	ModelMatrix[3] = 0;

	ModelMatrix[4] = 0;
	ModelMatrix[5] = 1;
	ModelMatrix[6] = 0;
	ModelMatrix[7] = 0;

	ModelMatrix[8] = sin(Angle * 3.14 / 180.0f);
	ModelMatrix[9] = 0;
	ModelMatrix[10] = cos(Angle * 3.14 / 180.0f);
	ModelMatrix[11] = 0;

	ModelMatrix[12] = Position[0];
	ModelMatrix[13] = Position[1];
	ModelMatrix[14] = Position[2];
	ModelMatrix[15] = 1;
}

void CGraphicObject::Rotate_Around(float x, float y, float z, float r)
{
	x = r*cos(a * 3.14 / 180.0f);
	z = r*sin(a * 3.14 / 180.0f);
	a += 0.5;
	this->SetPosition( x, y, z);
	this->SetAngle(180-a);
}

GLfloat CGraphicObject::RetX()
{
	return Position[0];
}

GLfloat CGraphicObject::RetY()
{
	return Position[1];
}

GLfloat CGraphicObject::RetZ()
{
	return Position[2];
}

CModel& CGraphicObject::GetModel()
{
	return *Model;
}

void CGraphicObject::SetMaterial(CMaterial *Material)
{
	this->Material = Material;
}

CMaterial& CGraphicObject::GetMaterial()
{
	return *Material;
}

bool CGraphicObject::IsTransparent(void)
{
	if(Material!=NULL)
	return Material->IsTransparent();
	else return false;
}
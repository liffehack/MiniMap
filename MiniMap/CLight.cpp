#include "CLight.h"

CLight::CLight(void)
{
	for (int i = 0; i < 4; i++)
	{
		Position[i] = 0;
		Ambient[i] = 0;
		Diffuse[i] = 0;
		Specular[i] = 0;
	}
	for (int i = 0; i < 16; i++)
	{
		//задаем стандартные значения матрицы модели
		if ((i == 0) || (i == 5) || (i == 10) || (i == 15))
			Matrix[i] = 1;
		else
			Matrix[i] = 0;
	}
}



void CLight::SetPosition(float x, float y, float z)
{
	Position[0] = x;
	Position[1] = y;
	Position[2] = z;
	Position[3] = 1;
	Matrix[12] = x;
	Matrix[13] = y;
	Matrix[14] = z;
}

void CLight::SetAmbient(float r, float g, float b)
{
	Ambient[0] = r;
	Ambient[1] = g;
	Ambient[2] = b;
	Ambient[3] = 1.0f;
}

void CLight::SetDiffuse(float r, float g, float b)
{
	Diffuse[0] = r;
	Diffuse[1] = g;
	Diffuse[2] = b;
	Diffuse[3] = 1.0f;
}

void CLight::SetSpecular(float r, float g, float b)
{
	Specular[0] = r;
	Specular[1] = g;
	Specular[2] = b;
	Specular[3] = 1.0f;
}

void CLight::Apply(GLenum LightNumber)
{
	glEnable(LightNumber);
	glLightfv(LightNumber, GL_AMBIENT, Ambient);
	glLightfv(LightNumber, GL_DIFFUSE, Diffuse);
	glLightfv(LightNumber, GL_SPECULAR, Specular);
	glLightfv(LightNumber, GL_POSITION, Position);
}

void CLight::Draw(void)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(Matrix);
	glutSolidSphere(0.5, 18, 18);
	glPopMatrix();
}
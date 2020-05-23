#include "CPhongMaterial.h"
CPhongMaterial CPhongMaterial::Default = CPhongMaterial(true);
CPhongMaterial::CPhongMaterial(void)
{
	for (int i = 0; i < 3; i++)
	{
		Emission[i]=Specular[i]=Diffuse[i]=Ambient[i] = 0;
	}
	Emission[3] = Specular[3] = Diffuse[3] = Ambient[3] = 1;
	Shininess = 0;
}

CPhongMaterial::CPhongMaterial(bool def)
{
	SetDiffuse(1.0f, 0.5f, 0.1f);
	SetAmbient(0.85f);
	SetSpecular(0.65f);
	SetShininess(5.0f);
}

int CPhongMaterial::MaterialMode = 0;

void CPhongMaterial::SetAmbient(float r, float g, float b)
{
	Ambient[0] = r;
	Ambient[1] = g;
	Ambient[2] = b;
	Ambient[3] = Diffuse[3];
}

void CPhongMaterial::SetDiffuse(float r, float g, float b, float a)
{
	Diffuse[0] = r;
	Diffuse[1] = g;
	Diffuse[2] = b;
	Diffuse[3] = a;
}

void CPhongMaterial::SetEmission(float r, float g, float b)
{
	Emission[0] = r;
	Emission[1] = g;
	Emission[2] = b;
	Emission[3] = Diffuse[3];
}

void CPhongMaterial::SetSpecular(float r, float g, float b)
{
	Specular[0] = r;
	Specular[1] = g;
	Specular[2] = b;
	Specular[3] = Diffuse[3];
}

void CPhongMaterial::SetShininess(float p)
{
	Shininess = p;
}

void CPhongMaterial::SetAmbient(float k)
{
	for (int i = 0; i < 3; i++)
	{
		Ambient[i] = k*Diffuse[i];
	}
	Ambient[3] = Diffuse[3];
}

void CPhongMaterial::SetSpecular(float k)
{
	for (int i = 0; i < 3; i++)
	{
		Specular[i] = k*Diffuse[i];
	}
	Specular[3] = Diffuse[3];
}

void CPhongMaterial::SetEmission(float k)
{
	for (int i = 0; i < 3; i++)
	{
		Emission[i] = k*Diffuse[i];
	}
	Emission[3] = Diffuse[3];
}

void CPhongMaterial::Apply(void)
{
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, Emission);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, Shininess);
}

bool CPhongMaterial::IsTransparent(void)
{
	if (Diffuse[3] == 1.0f)
		return false;
	else return true;
}
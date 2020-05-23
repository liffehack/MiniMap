#include "Data.h"

int GameObjectCount = 0;
GLint fps = 0;
CCamera Camera("text.txt");
CGameObject GameObjects[21][21];
CGraphicObject Plane;
CGameObject Player;
CModel Model[4];
CModel Test;
CPortal Portal[2];
CPhongMaterialWithTexture PortalMat;
CBomb Bomb;
CLight LightSphere;
CPhongMaterialWithTexture Material[5];
CPhongMaterial BombMaterial;
CPhongMaterial Def;
CSprite Sprites[3];
CTexture PlaneTextures, Edges, Boxes,PortalTex;
float MinimapX(); 
float MinimapZ();

int PassabilityMap[21][21];
CCamera CAM1;
GLfloat sec, summ_sec;
GLchar OutTitle[120];

bool CameraLeft;
bool CameraRight;
bool CameraUp;
bool CameraDown;
bool CameraForward;
bool CameraBackward;
bool CameraShift;
bool Left, Right, Backward, Forward;
LARGE_INTEGER oldvalue, newvalue, freq;
bool ML, MR, MF, MB;
int IND_X, IND_Z, CUR_POSX, CUR_POSY;
int BombSpriteCount;
const int PortalCount = 2;
bool UseMultisample = true;

void SetModels()
{
	ScanMap("map.txt");
	PlaneTextures.Load("sand_38.jpg");
	Edges.Load("sandstone_smooth.png");
	Boxes.Load("sandstone_smooth.png");
	PortalTex.Load("glass_orange.png");
	//Sprites[0].Load("images/tabl.tiff",true);
	Sprites[1].Load("images/Bomb.ico");
	Sprites[2].Load("images/Bar.bmp");
	Material[0].SetDiffuse(0.8f, 0.79f, 0.67f);  //легкие объекты
	Material[0].SetAmbient(0.85f);
	Material[0].SetTexture(&Boxes);
	Material[1].SetDiffuse(0.3f, 0.3f, 0.3f);  //т¤желые объекты
	Material[1].SetAmbient(0.85f);
	Material[1].SetSpecular(1.0f);
	Material[1].SetShininess(20.0f);
	Material[2].SetDiffuse(0.1f, 0.1f, 0.1f);  // грани лабиринта
	Material[2].SetAmbient(0.85f);
	Material[2].SetTexture(&Edges);
	Material[3].SetDiffuse(0.35f, 0.8f, 0.9f);  // шар
	Material[3].SetAmbient(0.85f);
	Material[3].SetSpecular(0.65f);
	Material[3].SetShininess(5.0f);
	Material[3].SetEmission(0.8f);
	Material[4].SetDiffuse(0.2f, 0.2f, 0.2f);  // пол
	Material[4].SetAmbient(0.85f);
	Material[4].SetTexture(&PlaneTextures);
	BombMaterial.SetDiffuse(0.0f, 0.0f, 0.0f);
	BombMaterial.SetSpecular(1.0f, 1.0f, 1.0f);
	BombMaterial.SetShininess(100.0f);
	BombMaterial.SetAmbient(0.85f);
	Def.SetDiffuse(1.0f, 0.1f, 0.1f);  // шар
	Def.SetAmbient(0.85f);
	Def.SetSpecular(0.65f);
	Def.SetShininess(5.0f);
	LightSphere.SetDiffuse(0.9f, 0.9f, 0.9f);
	LightSphere.SetAmbient(0.6f, 0.6f, 0.6f);
	LightSphere.SetSpecular(0.4f, 0.4f, 0.4f);
	LightSphere.SetPosition(-15.0f, 15.0f, -15.0f);
	Model[0].CreatePlane(21, 1, 1);
	Model[1].LoadModel("models/ChamferBox.3DS");
	Model[2].LoadModel("models/Box.3DS");
	Model[3].LoadModel("models/Sphere.3DS");
	Bomb.SetModel(&Model[3]);
	Bomb.SetMaterial(&BombMaterial);
	Plane.SetModel(&Model[0]);
	Plane.SetMaterial(&Material[4]);
	Plane.SetPosition(0, 0, 0);
	Player.SetModel(&Model[3]);
	Player.SetMaterial(&Material[3]);
	Player.SetLogicPosition(2, 1);
	Player.SetPosition(-8, 0.5, -9);
	PortalMat.SetDiffuse(0.35f, 0.8f, 0.9f,1.0f);
	PortalMat.SetAmbient(0.85f);
	PortalMat.SetSpecular(0.65f);
	PortalMat.SetShininess(5.0f);
	PortalMat.SetTexture(&PortalTex);
	Portal[0].SetModel(&Model[2]);
	Portal[0].SetMaterial(&PortalMat);
	Portal[0].SetPosition(-9, 0.5, -9);
	Portal[0].SetLogicPosition(1, 1);
	Portal[0].SetTeleportTo(19, 19);
	Portal[1].SetModel(&Model[2]);
	Portal[1].SetMaterial(&PortalMat);
	Portal[1].SetLogicPosition(19,19);
	Portal[1].SetPosition(9, 0.5, 9);
	Portal[1].SetTeleportTo(1, 1);
	Portal[1].SetFrom(Portal[0]);
	Portal[0].SetFrom(Portal[1]);
	int k = 0;
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (PassabilityMap[i][j] == 2)
			{
				GameObjects[i][j].SetModel(&Model[2]);
				GameObjects[i][j].SetPosition(GLfloat(-10 + i), GLfloat(0.5), GLfloat(-10 + j));
				GameObjects[i][j].SetLogicPosition(i, j);
				GameObjects[i][j].SetMaterial(&Material[2]);
				k++;
			}
			if (PassabilityMap[i][j] == 1)
			{
				GameObjects[i][j].SetModel(&Model[2]);
				GameObjects[i][j].SetPosition(GLfloat(-10 + i), GLfloat(0.5), GLfloat(-10 + j));
				GameObjects[i][j].SetLogicPosition(i, j);
				GameObjects[i][j].SetMaterial(&Material[0]);
				k++;
			}
			if (PassabilityMap[i][j] == 3)
			{
				GameObjects[i][j].SetModel(&Model[1]);
				GameObjects[i][j].SetPosition(GLfloat(-10 + i), GLfloat(0.5), GLfloat(-10 + j));
				GameObjects[i][j].SetLogicPosition(i, j);
				GameObjects[i][j].SetMaterial(&Material[1]);
				k++;
			}
		}
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		Camera.write_file("text.txt");
		exit(0);
	}
}

void ScanMap(char *FILE)
{
	std::ifstream file(FILE);
	char buffer[22];
	for (int i = 0; i < 21; i++)
	{
		file.getline(buffer, 22);
		for (int j = 0; j < 21; j++)
		{
			if (buffer[j] == '2')
			{
				PassabilityMap[i][j] = 2;
				GameObjectCount++;
				continue;
			}
			if (buffer[j] == '3')
			{
				PassabilityMap[i][j] = 3;
				GameObjectCount++;
				continue;
			}
			if (buffer[j] == '1')
			{
				PassabilityMap[i][j] = 1;
				GameObjectCount++;
				continue;
			}
			else if (buffer[j] == '0')
			{
				PassabilityMap[i][j] = 0;
				GameObjectCount++;
				continue;
			}
		}
	}
	file.close();
}
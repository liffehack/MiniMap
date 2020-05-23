#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <glew.h>
#include <Windows.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "GL/freeglut.h"
#include "CGraphicObject.h"
#include "Camera.h"
#include "CGameObject.h"
#include "CBomb.h"
#include "CPortal.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "CLight.h"
#include "CMaterial.h"
#include "CSprite.h"
#include "IL/il.h"
#include "IL/ilu.h"
#include "IL/ilut.h"
#include "CTexture.h"
#include "CPhongMaterial.h"
#include "CPhongMaterialWithTex.h"


extern CCamera Camera;
extern CCamera MinimapView;
extern int  GameObjectCount;
extern CGameObject GameObjects[21][21];
extern CGraphicObject Plane;
extern CGameObject Player;
extern CModel Model[4];
extern CPortal Portal[2];
extern CPhongMaterialWithTexture PortalMat;
extern CBomb Bomb;
extern CLight LightSphere;
extern CPhongMaterialWithTexture Material[5];
extern CPhongMaterial BombMaterial;
extern CPhongMaterial Def;
extern CSprite Sprites[3];
extern CTexture PlaneTextures;

extern int PassabilityMap[21][21];
extern GLfloat sec, summ_sec;
extern GLint fps;
extern GLchar OutTitle[120];

extern bool CameraLeft;
extern bool CameraRight;
extern bool CameraUp;
extern bool CameraDown;
extern bool CameraForward;
extern bool CameraBackward;
extern bool CameraShift;
extern bool Left, Right, Backward, Forward;
extern LARGE_INTEGER oldvalue, newvalue, freq;
extern bool ML, MR, MF, MB;
extern int IND_X, IND_Z, CUR_POSX, CUR_POSY;
extern int BombSpriteCount;
extern const int PortalCount;
extern bool UseMultisample;

//kb keys
void keyboard(unsigned char key, int x, int y);
//set the models
void SetModels();
//calling when size is changed
void Reshape(int, int);
//scan map
void ScanMap(char *File);
//
void GetMove(bool &left, bool &right, bool &forward, bool &backward);
void SimulateBomb();
void ReadKeyForBomb();
void ExplodeGameObjectsAround();
void BombProcessing();
void GetFps();
void GameObjectsProcessing();
void ReadKeysForCamera();
void ReadKeysForPlayer();
void PlayerProcessing();
void CountBombSprites();
void SetViewPort(int x,int y,int w, int h);
void DrawMinimap();
float MinimapX();
float MinimapZ();
#include "Display.h"

void Display(void)
{
	//erasing color buffer
	SetViewPort(0, 0, CSprite::ScreenWidth, CSprite::ScreenHeight);
	glClearColor(0, 0, 0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//turning on depth test
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	//setting the cam
	Camera.Apply();
	LightSphere.Apply(GL_LIGHT0);
	//режим вывода наших моделей
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_MULTISAMPLE);
	//output the model
	Plane.Draw();
	glDisable(GL_TEXTURE_2D);
	Player.Draw();
	LightSphere.Draw();
	for (int i = 0; i <21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if(!GameObjects[i][j].IsTransparent())
			GameObjects[i][j].Draw();
		}
	}
	Sprites[0].DrawFromRightUp(1, 1);
	glDepthMask(GL_FALSE);
	glCullFace(GL_FRONT);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//draw all transporated models
	for (int i = 0; i <21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (GameObjects[i][j].IsTransparent())
				GameObjects[i][j].Draw();
		}
	}
	Portal[0].Draw();
	Portal[1].Draw();
	glCullFace(GL_BACK);
	//draw all transporated models
	for (int i = 0; i <21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (GameObjects[i][j].IsTransparent())
				GameObjects[i][j].Draw();
		}
	}
	Portal[0].Draw();
	Portal[1].Draw();
	//вывод спрайтов
	Sprites[1].DrawFromLeftUp(1, 1);
	if (Bomb.BombIsOnMap())
	{
		Bomb.Draw();
		CountBombSprites();
		for (int i = 0; i < BombSpriteCount; i++)
			Sprites[2].DrawFromLeftUp(Sprites[1].GetSpriteWidth() + (Sprites[2].GetSpriteWidth() + 5)*(i + 1), 1);
	}
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glDepthMask(GL_TRUE);
	glDisable(GL_MULTISAMPLE);
	// minimap
	DrawMinimap();
	//minimap end
	glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);
	//swap buffers
	glutSwapBuffers();
}

void Reshape(int w, int h)
{
	CSprite::ScreenWidth = w;
	CSprite::ScreenHeight = h;
	SetViewPort(0, 0, w, h);
}

void SetViewPort(int x, int y, int w, int h)
{
	//set the new point of view
	glViewport(x, y, (GLsizei)w, (GLsizei)h);
	//set matrix with right aspects
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0, (float)w / h, 0.2, 200.0);
}

void DrawMinimap()
{
	glEnable(GL_SCISSOR_TEST);
	glScissor(0, 0, 300, 300);
	SetViewPort(0, 0, 300, 300);
	glClearColor(0, 0, 0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//apply minimap view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 45, 0, 0, 0, 0, 0, 0, -1);
	//apply light & draw models for minimap
	LightSphere.Apply(GL_LIGHT0);
	Plane.Draw();
	Player.Draw();
	LightSphere.Draw();
	for (int i = 0; i <21; i++)
	{
		for (int j = 0; j < 21; j++)
			GameObjects[i][j].Draw();
	}
	if (Bomb.BombIsOnMap())
		Bomb.Draw();
	//portals
	glDepthMask(GL_FALSE);
	glCullFace(GL_FRONT);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//draw all transporated models
	Portal[0].Draw();
	Portal[1].Draw();
	glCullFace(GL_BACK);
	//draw all transporated models
	Portal[0].Draw();
	Portal[1].Draw();
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glDepthMask(GL_TRUE);
	glDisable(GL_SCISSOR_TEST);
}
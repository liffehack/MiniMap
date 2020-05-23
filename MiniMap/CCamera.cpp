#include "Camera.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include "GL/freeglut.h"

#include <fstream>
#include <iostream>

#include <Windows.h>

#define _USE_MATH_DEFINES
#include <cmath>

const float M_PI = 3.14;
const float ANGULAR_SPEED_ROTATION = 90;
float ANGULAR_SPEED_ROTATION_koef = 1;
//extern int number_of_frames;

CCamera::CCamera(char* namefile)
{
	if (read_file(namefile) != 0)
	{
		r = 15;
		yaw = 45.0f; pitch = 45.0f;
	}
	sec = 0.0f;

	Position[0] = r;
	Position[1] = r;
	Position[2] = r;
}

bool CCamera::read_file(char*namefile)
{

	if (!strcmp(namefile, ""))
		return -1;
	std::ifstream in;
	in.open(namefile);
	if (in.is_open())
	{
		in >> r >> yaw >> pitch;
		in.close();

		return 0;
	}
	else return -1;
}

bool CCamera::write_file(char* namefile)
{
	std::ofstream out(namefile);
	out << r << std::endl << yaw << std::endl << pitch;
	out.close();
	return 0;
}

void CCamera::SetKey(bool left_, bool right_, bool up_, bool down_, bool forward_, bool backward_)
{
	left = left_;
	right = right_;
	up = up_;
	down = down_;
	forward = forward_;
	backward = backward_;
}

void CCamera::SetShift(bool shift)
{
	if (shift)
		ANGULAR_SPEED_ROTATION_koef = 2;
}
void CCamera::Simulate(GLfloat &sec_)
{
	sec_;
	if (left)
	{
		if (yaw > 360)
			yaw = ANGULAR_SPEED_ROTATION * sec_* ANGULAR_SPEED_ROTATION_koef;
		else yaw = yaw + ANGULAR_SPEED_ROTATION * sec_* ANGULAR_SPEED_ROTATION_koef;
	}
	if (right)
	{
		if (yaw < 0)
			yaw = 360 - ANGULAR_SPEED_ROTATION * sec_* ANGULAR_SPEED_ROTATION_koef;
		else  yaw = yaw - ANGULAR_SPEED_ROTATION * sec_* ANGULAR_SPEED_ROTATION_koef;
	}
	if (up)
	{
		pitch = pitch + ANGULAR_SPEED_ROTATION * sec_* ANGULAR_SPEED_ROTATION_koef;
		if (pitch > 89)
			pitch = 89;
	}
	if (down)
	{
		pitch = pitch - ANGULAR_SPEED_ROTATION * sec_* ANGULAR_SPEED_ROTATION_koef;
		if(pitch < 0)
			pitch = 0;
	}
	ANGULAR_SPEED_ROTATION_koef = 1;


	if (forward)
	{
		r -= sec_ * 10;
		if (r < 10)
		{
			r = 10;
		}
	}
	if (backward)
	{
		r += sec_ * 10;
		if (r>90)
		{
			r = 90;
		}
	}
	Position[0] = r* cos(pitch* M_PI / 180.0f)*(cos(yaw* M_PI / 180.0f));
	Position[1] = r*sin(pitch* M_PI / 180.0f);
	Position[2] = r*cos(pitch* M_PI / 180.0f)*(sin(yaw* M_PI / 180.0f));
}

void CCamera::Apply()
{
    // устанавливаем камеру
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(Position[0], Position[1], Position[2],
		0, 0, 0,
		0, 1, 0);

}

GLfloat CCamera::GetYaw()
{
	return yaw;
}
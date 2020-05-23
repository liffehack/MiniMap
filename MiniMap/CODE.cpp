#pragma once

#include "Data.h"
#include "Simulation.h"
#include "Display.h"



int main(int argc,char **argv)
{
	//initalizing library
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH|GLUT_MULTISAMPLE);
	//// инициализация библиотеки DevIL для загрузки изображений
	ilInit();
	iluInit();
	ilutInit();
	//create the window
	//set the upper left corner
	glutInitWindowPosition(0, 0);
	//size of window
	glutInitWindowSize(1024, 768);
	//creating the window
	glutCreateWindow(OutTitle);
	sprintf(OutTitle, "Gl lab #5  %d", fps);
	//init glew
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
	// проверка поддержки расширения для работы с буфером VBO
	if (GLEW_ARB_vertex_buffer_object) {
		printf("VBO is supported");
	};
	//initialize the models
	SetModels();
	//redraw the window
	glutDisplayFunc(Display);
	//reshape func
	glutReshapeFunc(Reshape);
	//timer
	glutIdleFunc(Simulation);
	//считывание key
	glutKeyboardFunc(keyboard);
	//loop all main in cicle
	glutMainLoop();
	return 0;
}
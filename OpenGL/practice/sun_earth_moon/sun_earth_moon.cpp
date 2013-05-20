// sun_earth_moon.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <GL/glut.h>
#include <dos.h>

static int day = 200;

void display()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75, 1, 1, 400000000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);
	
	// 红色太阳
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(69600000, 100, 100);
	// 蓝色地球
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(day * 1.0f, 0.0f, 0.0f, -1.0f);
	glTranslatef(150000000, 0.0f, 0.0f);
	glutSolidSphere(15945000, 100, 100);
	// 黄色月亮
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(day * 12.0f - day * 1.0f, 0.0f, 0.0f, -1.0f);
	glTranslatef(38000000, 0.0f, 0.0f);
	glutSolidSphere(4345000, 100, 100);
	
	glFlush();
	glutSwapBuffers();
}

void idle()
{
	++day;
	if(day >= 360)
		day = 0;
	display();
	//sleep(1);
	//for(int i = 0; i < 50000; i++);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}


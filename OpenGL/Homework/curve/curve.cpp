// curve.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <gl/glut.h>
#include <stdlib.h>
#include <math.h>

#define imageWidth 64
#define imageHeight 64

const float pi = 3.14159;

GLubyte image[3 * imageWidth * imageHeight];

GLfloat points[4][4][3] = {
	{	{-2.0, -2.0, 4},
		{-1.0, -2.0, 2.0},
		{1.0, -2.0, -1.0},
		{2.0, -2.0, 2.0}	},
	{	{-2.0, -1.0, 1.0},
		{-1.0, -1.0, 3.0},
		{1.0, -1.0, -1.0},
		{2.0, -1.0, -1.0}	},
	{	{-2.0, 1.0, 4.0},
		{-1.0, 1.0, 0.0},
		{1.0, 1.0, 3.0},
		{2.0, 1.0, 4.0}		},
	{	{-2.0, 2.0, -2.0},
		{-1.0, 2.0, -2.0},
		{1.0, 2.0, 0.0},
		{2.0, 2.0, -1.0}	}
};

GLfloat colors[8][3] = {
	{0.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
	{1.0, 1.0, 0.0},
	{0.0, 0.0, 1.0},
	{1.0, 0.0, 0.0},
	{1.0, 0.0, 1.0},
	{0.0, 1.0, 1.0},
};

GLfloat texpts[2][2][2] = {
	{{0.0, 0.0}, {0.0, 1.0}},
	{{1.0, 0.0}, {1.0, 1.0}},
};

static GLfloat theta[3] = {0.0, 0.0, 0.0};
static GLdouble viewer[3] = {0.0, 0.0, 5.0};
static GLint axis = 2;

void initlights(void)
{
   GLfloat ambient[] = {0.2, 0.2, 0.2, 1.0};
   GLfloat position[] = {0.0, 0.0, 2.0, 1.0};
   GLfloat mat_diffuse[] = {0.6, 0.6, 0.6, 1.0};
   GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
   GLfloat mat_shininess[] = {50.0};

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);

   glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
   glLightfv(GL_LIGHT0, GL_POSITION, position);

   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void makeImage()
{
	int i, j;
	float ti, tj;

	for(i = 0; i < imageWidth; i++){
		ti = 2.0*pi*i/imageWidth;
		for(j = 0; j < imageHeight; j++){
			tj = 2.0*pi*j/imageHeight;
			image[3 * (imageHeight * i + j)] = (GLubyte)127 * (1.0 + sin(ti));
			image[3 * (imageHeight * i + j) + 1] = (GLubyte)127 * (1.0 + cos(2 * tj));
			image[3 * (imageHeight * i + j) + 2] = (GLubyte)127 * (1.0 + cos(ti + tj));
		}
	}
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
           0, 1, 12, 4, &points[0][0][0]);
	glMap2f(GL_MAP2_TEXTURE_COORD_2, 0, 1, 2, 2,
           0, 1, 4, 2, &texpts[0][0][0]);
	glEnable(GL_MAP2_TEXTURE_COORD_2);
	glEnable(GL_MAP2_VERTEX_3);
	glEnable(GL_AUTO_NORMAL);
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);

	makeImage();

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
	initlights();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glEvalMesh2(GL_FILL, 0, 20, 0, 20);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho(-4.0, 4.0, -4.0*(GLfloat)h/(GLfloat)w,
              4.0*(GLfloat)h/(GLfloat)w, -4.0, 4.0);
   else
      glOrtho(-4.0*(GLfloat)w/(GLfloat)h,
              4.0*(GLfloat)w/(GLfloat)h, -4.0, 4.0, -4.0, 4.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void spinCurveSurf()
{
	theta[axis] += 2;
	if(theta[axis] > 360.0)
		theta[axis] -= 360.0;

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}


void mouse(int btn, int state, int x, int y)
{
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		axis = 0;
	if(btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		axis = 1;
	if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		axis = 2;
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("CurveSurface");
	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(spinCurveSurf);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}


// 3DColorPyramid.cpp : 定义控制台应用程序的入口点。
// 此程序生成显示一个转动的彩色金字塔

#include "stdafx.h"

// 金字塔的顶点
GLfloat v[][3] = {
	{-1.0, -1.0, -1.0},
	{1.0, -1.0, -1.0},
	{1.0, 1.0, -1.0},
	{-1.0, 1.0, -1.0},
	{0.0, 0.0, 1.0},
};

GLfloat colors[][3] = {
	{0.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
	{1.0, 1.0, 0.0},
	{0.0, 0.0, 1.0},
	{1.0, 0.0, 0.0},
};

static GLfloat theta[3] = {0.0, 0.0, 0.0};

void polygon(int a, int b, int c);
void colorPyramid();
void display();
void myReshape(int w, int h);
void spinPyramid();

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3DColorPyramid");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(spinPyramid);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}

// 通过顶点数组绘制一个三角形的面
void polygon(int a, int b, int c)
{
	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(v[a]);
	glColor3fv(colors[b]);
	glVertex3fv(v[b]);
	glColor3fv(colors[c]);
	glVertex3fv(v[c]);
	glEnd();
}

// 把顶点和三角形的面对应起来
void colorPyramid()
{
	polygon(0, 3, 1);
	polygon(1, 3, 2);
	polygon(0, 3, 4);
	polygon(0, 1, 4);
	polygon(1, 2, 4);
	polygon(2, 3, 4);
}

// 显示回调函数
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

	colorPyramid();

	glFlush();
	glutSwapBuffers();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w, 
			2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.0 * (GLfloat)h / (GLfloat)w, 2.0 * (GLfloat)h / (GLfloat)w, 
			-2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW );
}

// 将金字塔绕轴旋转
void spinPyramid()
{
	theta[0] += 2;
	theta[1] += 2;
	theta[2] += 3;
	if(theta[2] > 360.0)
		theta[2] -= 360.0;

	glutPostRedisplay();
}
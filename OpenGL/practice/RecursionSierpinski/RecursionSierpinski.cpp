// RecursionSierpinski.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void triangle(GLfloat *a, GLfloat *b, GLfloat *c);
void divide_triangle(float *a, float *b, float *c, int k);
void display();
void myinit();

int n = 5;
GLfloat v[3][2] = {{0.0, 0.0},{25.0, 50.0},{50.0, 0.0}};

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Simple OpenGL example");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
}

void divide_triangle(float *a, float *b, float *c, int k)
{
	GLfloat ab[2], ac[2], bc[2];
	int j;
	if(k > 2)
	{
		// 设置个边的中点
		for(j = 0; j < 2; j++)
			ab[j] = (a[j] + b[j]) / 2;
		for(j = 0; j < 2; j++)
			ac[j] = (a[j] + c[j]) / 2;
		for(j = 0; j < 2; j++)
			bc[j] = (b[j] + c[j]) / 2;

		// 继续细分小三角形，除了中间的那个小三角形
		divide_triangle(a, ab, ac, k-1);
		divide_triangle(c, ac, bc, k-1);
		divide_triangle(b, bc, ab, k-1);
	}
	else
		triangle(a, b, c);	// 在递归结束时绘制三角形
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		divide_triangle(v[0], v[1], v[2], n);
	glEnd();
	glFlush();
}

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);

	// 设置观察参数
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}

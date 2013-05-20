// Sierpinski.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void myinit();
void display();

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

void myinit()
{
	// 设置属性
	glClearColor(1.0, 1.0, 1.0, 1.0);	// 白色的背景
	glColor3f(1.0, 0.0, 0.0);	// 用红色来绘制

	// 设置观察参数
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	// 三角形
	GLfloat vertices[3][2] = {{0.0, 0.0},{25.0, 50.0},{50.0, 0.0}};

	int i, j, k;
	int rand();
	GLfloat p[2] = {7.5, 5.0};	// 三角形内一点

	glClear(GL_COLOR_BUFFER_BIT);	// 清空窗口

	// 计算并输出5000个点
	glBegin(GL_POINTS);
	for(k = 0; k < 5000; k++)
	{
		j = rand() % 3;

		// 计算顶点与上一点之间连线的中点
		p[0] = (p[0] + vertices[j][0]) / 2;
		p[1] = (p[1] + vertices[j][1]) / 2;

		// 绘制点
		glVertex2fv(p);
	}
	glEnd();
	glFlush();
}
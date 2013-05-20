// cube.cpp : 定义控制台应用程序的入口点。
//


#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <GL/glut.h>

static GLfloat theta[] = {0.0, 0.0, 0.0};
static GLint axis = 2;

GLfloat vertices[][3] = {	
	{-1.0, -1.0, -1.0},
	{1.0, -1.0, -1.0},
	{1.0, 1.0, -1.0},
	{-1.0, 1.0, -1.0},
	{-1.0, -1.0, 1.0},
	{1.0, -1.0, 1.0},
	{1.0, 1.0, 1.0},
	{-1.0, 1.0, 1.0}
};

GLfloat colors[][3] = {
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 0.0},
	{1.0, 1.0, 0.0},
	{0.0, 1.0, 0.0},
	{0.0, 0.0, 1.0},
	{1.0, 0.0, 1.0},
	{1.0, 1.0, 1.0},
	{0.0, 1.0, 1.0},
};

// 通过顶点数组绘制一个多边形
void polygon(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glColor3fv(colors[a]);
	glVertex3fv(vertices[a]);
	glColor3fv(colors[b]);
	glVertex3fv(vertices[b]);
	glColor3fv(colors[c]);
	glVertex3fv(vertices[c]);
	glColor3fv(colors[d]);
	glVertex3fv(vertices[d]);
	glEnd();
}

// 把顶点与多边形的表面对应起来
void colorcube()
{
	polygon(0, 3, 2, 1);
	polygon(2, 3, 7, 6);
	polygon(0, 4, 7, 3);
	polygon(1, 2, 6, 5);
	polygon(4, 5, 6, 7);
	polygon(0, 1, 5, 4);
}

// 显示回调函数，清空帧缓存和z-buffer里的内容，旋转并绘制
// 立方体，交换前端缓存与后端缓存里的内容
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(theta[0], 1.0, 0.0, 0.0);
	glRotatef(theta[1], 0.0, 1.0, 0.0);
	glRotatef(theta[2], 0.0, 0.0, 1.0);

	colorcube();

	glFlush();
	glutSwapBuffers();
}

// 空闲回调函数，将立方体绕选择的轴旋转2°
void spinCube()
{
	theta[axis] += 2.0;
	if(theta[axis] > 360.0)
		theta[axis] -= 360.0;

	glutPostRedisplay();
}

// 鼠标回调函数，选择立方体的旋转轴
void mouse(int btn, int state, int x, int y)
{
	if(btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		axis = 0;                        
	if(btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
		axis = 1;
	if(btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		axis = 2;             
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

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	// 既需要双缓存又需要z-buffer

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("colorcube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(spinCube);
	glutMouseFunc(mouse);
	glEnable(GL_DEPTH_TEST);	// 开启隐藏面消除功能
	glutMainLoop();
	return 0;
}


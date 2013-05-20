// ParticleSystem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define MAX_NUM_PARTICLES 1000
#define INITIAL_NUM_PARTICLES 25
#define INITIAL_POINT_SIZE 5.0
#define INITIAL_SPEED 1.0

void myDisplay();
void myIdle();
void myReshape(int , int );
void main_menu(int);
void collision(int);
float forces(int, int);

void myinit();

/* 全局变量 */

//int num_particles;/*粒子数目*/

/* 粒子结构体 */
typedef struct particle{
	int color;
	float position[3];
	float velocity[3];
	float mass;
} particle;

particle particles[MAX_NUM_PARTICLES]; /* 粒子系统 */

/* 粒子系统的初始状态 */
int present_time;
int last_time;
int num_particles = INITIAL_NUM_PARTICLES;
float point_size = INITIAL_POINT_SIZE;
float speed = INITIAL_SPEED;
bool gravity = false;	/* 不考虑重力 */
bool elastic = false;	/* 不考虑弹性恢复 */
float coef = 1.0;	/* 完全弹性碰撞 */

GLfloat wh = 500, ww = 500;	/* 初始窗口大小 */
GLfloat colors[8][3] = {
	{0.0, 0.0, 0.0},
	{1.0, 0.0, 0.0},
	{0.0, 1.0, 0.0},
	{0.0, 0.0, 1.0},
	{0.0, 1.0, 1.0},
	{1.0, 0.0, 1.0},
	{1.0, 1.0, 0.0},
	{1.0, 1.0, 1.0},
};

void myReshape(int w, int h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -4.0, 4.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.5, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	if(w < h)
		glViewport(0, 0, w, w);
	else
		glViewport(0, 0, h, h);

	ww = w;
	wh = h;
}

void myinit()
{
	int i, j;

	for(i = 0; i < num_particles; i++)
	{
		particles[i].mass = 1.0;
		particles[i].color = i % 8;
		for(j = 0; j < 3; j++)
		{
			particles[i].position[j] = 2.0 * ((float)rand() / RAND_MAX) - 1.0;
			particles[i].velocity[j] = speed * 2.0 * ((float)rand() / RAND_MAX) - 1.0;
		}
	}
	glPointSize(point_size);

	/* 把清屏颜色设置为灰色 */
	glClearColor(0.5, 0.5, 0.5, 1.0);
}

void myIdle()
{
	int i, j;
	float dt;
	present_time = glutGet(GLUT_ELAPSED_TIME);
	dt = 0.001 * (present_time - last_time);

	for(i = 0; i < num_particles; i++)
	{
		for(j = 0; j < 3; j++)
		{
			particles[i].position[j] += dt * particles[i].velocity[j];
			particles[i].velocity[j] += dt * forces(i, j) / particles[i].mass;
		}
		collision(i);
	}
	last_time = present_time;
	glutPostRedisplay();
}

float forces(int i, int j)
{
	float force = 0.0;
	if(gravity && j == 1)
		force = -1.0;/* 简单的重力 */
	return force;
}

/* 检测粒子与立方体的碰撞并在必要的时候使粒子发生反弹 */
void collision(int n)
{
	int i;
	for(i = 0; i < 3; i++)
	{
		if(particles[n].position[i] >= 1.0)
		{
			particles[n].velocity[i] = -coef * particles[n].velocity[i];
			particles[n].position[i] = 1.0 -coef * (particles[n].position[i] - 1.0);
		}
		if(particles[n].position[i] <= -1.0)
		{
			particles[n].velocity[i] = -coef * particles[n].velocity[i];
			particles[n].position[i] = -1.0 -coef * (particles[n].position[i] + 1.0);
		}
	}
}

void main_menu(int index)
{
	switch(index){
		case 1:
			num_particles = 2 * num_particles;
			myinit();
			break;
		case 2:
			num_particles = num_particles / 2;
			myinit();
			break;
		case 3:
			speed = 2.0 * speed;
			myinit();
			break;
		case 4:
			speed = speed / 2.0;
			myinit();
			break;
		case 5:
			point_size = point_size * 2.0;
			myinit();
			break;
		case 6:
			point_size = point_size / 2.0;
			if(point_size < 1.0)
				point_size = 1.0;
			myinit();
			break;
		case 7:
			gravity = !gravity;
			myinit();
			break;
		case 8:
			elastic = !elastic;
			if(elastic)
				coef = 0.9;
			else
				coef = 1.0;
			myinit();
			break;
		case 9:
			exit(0);
			break;
	}
}

void myDisplay()
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	for(i = 0; i < num_particles; i++)
	{
		glColor3fv(colors[particles[i].color]);
		glVertex3fv(particles[i].position);
	}
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glutWireCube(2.2);/* 绘制一个盒子的线框 */
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("particle system");
	glutDisplayFunc(myDisplay);
	myinit();

	glutCreateMenu(main_menu);
	glutAddMenuEntry("more particles", 1);
	glutAddMenuEntry("fewer particles", 2);
	glutAddMenuEntry("faster", 3);
	glutAddMenuEntry("slower", 4);
	glutAddMenuEntry("larger particles", 5);
	glutAddMenuEntry("smaller particles", 6);
	glutAddMenuEntry("toggle gravity", 7);
	glutAddMenuEntry("toggle restitution", 8);
	glutAddMenuEntry("exit", 9);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);

	glutIdleFunc(myIdle);
	glutReshapeFunc(myReshape);
	glutMainLoop();
	return 0;
}
// NURBSsurface.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <windows.h>
#include <gl/glut.h>
GLUnurbsObj *theNurb1;
GLUnurbsObj *theNurb2;

GLfloat ctrlpoints[5][5][3];//控制点

GLfloat mat_diffuse[];
GLfloat mat_specular[];
GLfloat mat_shininess[];
GLfloat light_position[];

void myInit(void)
{
　glClearColor(1.0,1.0,1.0,0.0);//设置背景色

　/*为光照模型指定材质参数*/
　glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
　glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
　glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

　glLightfv(GL_FRONT,GL_POSITION,light_position);//设置光源参数
　glLightModeli(GL_LIGHT_MODEL_TWO_SIDE,GL_TRUE);//设置光照模型参数

　/*激活光照*/
　glEnable(GL_LIGHTING);
　glEnable(GL_LIGHT0);

　glDepthFunc(GL_LEQUAL);
　glEnable(GL_DEPTH_TEST);
　glEnable(GL_LEQUAL);
　glEnable(GL_AUTO_NORMAL);
　glEnable(GL_NORMALIZE);

　/*设置特殊效果*/
　glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
　glHint(GL_LINE_SMOOTH_HINT,GL_DONT_CARE);
　glEnable(GL_BLEND);

　glFrontFace(GL_CW);
　glShadeModel(GL_SMOOTH);
　glEnable(GL_LINE_SMOOTH);

　theNurb1 = gluNewNurbsRenderer();//创建NURBS对象theNurb1
　gluNurbsProperty(theNurb1,GLU_SAMPLING_TOLERANCE,25.0);
　gluNurbsProperty(theNurb1,GLU_DISPLAY_MODE,GLU_OUTLINE_POLYGON);

　theNurb2 = gluNewNurbsRenderer();//创建NURBS对象theNurb2
　gluNurbsProperty(theNurb2,GLU_SAMPLING_TOLERANCE,25.0);
　gluNurbsProperty(theNurb2,GLU_DISPLAY_MODE,GLU_FILL);
}

int spin = 0;

/*接收键盘指令*/
static void myKey(unsigned char key,int x,int y)
{
　switch(key)
　{
　　case'd':
　　　spin = spin + 1;
　　　glRotatef(spin,1.0,1.0,0.0);
　　　glutPostRedisplay();
　　　break;
　　case 27:
　　　exit(0);
　　default:
　　　break;
　}
}

/*绘制曲面*/
void myDisplay(void)
{
　GLfloat knots[10] = ;

　glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
　glRotatef(50.0,1.0,1.0,0.0);

　/*第一个曲面*/
　glPushMatrix();
　glTranslatef(1.0,0.0,0.0);
　gluBeginSurface(theNurb1);
　/*定义曲面形状*/
　gluNurbsSurface(theNurb1,10,knots,10,knots,5*3,3,&ctrlpoints[0][0][0],5,5,GL_MAP2_VERTEX_3);
　gluEndSurface(theNurb1);
　glPopMatrix();

　/*第二个曲面*/
　glPushMatrix();
　glTranslatef(7.0,0.0,0.0);
　gluBeginSurface(theNurb2);
　/*定义曲面形状*/
　gluNurbsSurface(theNurb2,10,knots,10,knots,5*3,3,&ctrlpoints[0][0][0],5,5,GL_MAP2_VERTEX_3);
　gluEndSurface(theNurb2);
　glPopMatrix();

　glutSwapBuffers();
}

 


int main(int argc,char ** argv)
{
　/*初始化*/
　glutInit(&argc,argv);
　glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
　glutInitWindowSize(600,400);
　glutInitWindowPosition(200,200);
　
　/*创建窗口*/
　glutCreateWindow("NURBS surface");

　/*绘制与显示*/
　myInit();
　glutKeyboardFunc(myKey);
　glutReshapeFunc(myReshape);
　glutDisplayFunc(myDisplay);

　/*进入GLUT事件处理循环*/
　glutMainLoop();
　return(0);
}


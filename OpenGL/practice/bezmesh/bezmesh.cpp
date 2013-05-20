// bezmesh.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdlib.h>
#include <GL/glut.h>

GLfloat ctrlpoints[4][4][3] = {
   { {-3, -1.5, 4.0},
     {-0.5, -1.5, 7.0},
     {0.5, -2.5, -1.0},
     {8.5, -1.5, 2.0}},
   { {-1.5, -5.5, 1.0},
     {-0.5, -0.5, 6.0},
     {0.5, -1.0, 0.0},
     {1.5, -1.5, -4.0}},
   { {-1.5, 1.5, 4.0},
     {-1.5, 0.5, 0.0},
     {0.5, 0.5, 3.0},
     {1.0, 0.5, 4.0}},
   { {-4.0, 0.5, -4.0},
     {-0.5, 1.5, -7.0},
     {0.5, 2.0, 1.0},
     {1.5, 2.0, -1.0}}
};

void initlights(void)
{
   GLfloat ambient[] = {1.2, 1.2, 1.2, 1.0};
   GLfloat position[] = {0.5, 0.5, 2.0, 1.0};
   GLfloat mat_diffuse[] = {0.6, 0.6, 0.6, 1.0};
   GLfloat mat_specular[] = {0.5, 0.2, 0.8, 1.0};
   GLfloat mat_shininess[] = {50.0};

   glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
   glLightfv(GL_LIGHT0, GL_POSITION, position);

   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   
   glDepthFunc(GL_LEQUAL);
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_LEQUAL);
   glEnable(GL_AUTO_NORMAL);
   glEnable(GL_NORMALIZE);

   // 设置特殊效果
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
   glEnable(GL_BLEND);
   
   glFrontFace(GL_CW);
   glShadeModel(GL_SMOOTH);
   glEnable(GL_LINE_SMOOTH);

   GLfloat ambient2nd[] = {0.2, 0.2, 0.2, 1.0};
   GLfloat diffuse2nd[] = {1.0, 1.0, 1.0, 1.0};
   GLfloat specular2nd[] = {1.0, 1.0, 1.0, 1.0};
   GLfloat position2nd[] = {-2.0, 2.0, 1.0, 1.0};
   GLfloat direction[] = {-1.0, -1.0, 0.0};// 聚光灯的方向

   glLightfv(GL_LIGHT1, GL_AMBIENT, ambient2nd);
   glLightfv(GL_LIGHT1, GL_POSITION, position2nd);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse2nd);
   glLightfv(GL_LIGHT1, GL_SPECULAR, specular2nd);

   glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
   glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direction); 
   glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT1);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix();
   glRotatef(85.0, 1.0, 1.0, 1.0);
   glEvalMesh2(GL_FILL, 0, 20, 0, 20);
   glPopMatrix();
   glFlush();
}

void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST);
   glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
           0, 1, 12, 4, &ctrlpoints[0][0][0]);
   glEnable(GL_MAP2_VERTEX_3);
   glEnable(GL_AUTO_NORMAL);
   glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
   initlights();       /* for lighted version only */
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

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}



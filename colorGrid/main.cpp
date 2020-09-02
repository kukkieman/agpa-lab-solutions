/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include<iostream>
#include <stdlib.h>
#include<utility>
#include<time.h>

void display(){
    for(int i=9; i>=0; i--){
        for(int j=9; j>=0; j--){
            //glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(((float)rand()/(float)(RAND_MAX))*1,((float)rand()/(float)(RAND_MAX))*1,((float)rand()/(float)(RAND_MAX))*1);

            glBegin(GL_QUADS);
                glVertex3f(i, j, 0);
                glVertex3f(i, j+1, 0);
                glVertex3f(i+1, j+1, 0);
                glVertex3f(i+1, j, 0);
            glEnd();
        }
    }
    glFlush();
}

int main(int argc, char **argv){
    //srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(200,200);
    glutCreateWindow("Grid");

    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 10, 0, 10, -1, 1);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

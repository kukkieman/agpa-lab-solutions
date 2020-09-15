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

void drawTri(){

    for(int i=0; i<3; i++){
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-1.0f, -0.5f, -1.0f);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(1.0f, -0.5f, -1.0f);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex3f(0.0f, 0.5f, -1.0f);
        glEnd();
    }
    glutSwapBuffers();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    drawTri();
    glFlush();
}

int main(int argc, char **argv){
    //srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(200,200);
    glutInitWindowSize(640,480);
    glutCreateWindow("RGB Triangle");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

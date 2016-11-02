//
//  main.c
//  TeoriaDosConjuntos
//
//  Created by Rodrigo Soldi Lopes on 02/11/16.
//  Copyright © 2016 Rodrigo Soldi Lopes. All rights reserved.
//

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#else
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#endif

GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0}; // "cor"
GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
GLint especMaterial = 60;

int correct = 0;
int refreshMills = 1;
GLfloat angle = 0.0f;

void drawX() {
    glLineWidth(5);
    glColor3f(1.0f, 0, 0);
    
    // X1
    
    glBegin(GL_LINES);
    glVertex3f(-.7, -.16, 0.0);
    glVertex3f(-.6,-.36, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-.6, -.16, 0.0);
    glVertex3f(-.7,-.36, 0.0);
    glEnd();
    
    // X2
    
    glBegin(GL_LINES);
    glVertex3f(.7, -.16, 0.0);
    glVertex3f(.6,-.36, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(.6, -.16, 0.0);
    glVertex3f(.7,-.36, 0.0);
    glEnd();
    
}

void drawV() {
    glLineWidth(5);
    glColor3f(0, 1, 0);
    
    // V1
    
    glBegin(GL_LINES);
    glVertex3f(-.68, -.26, 0.0);
    glVertex3f(-.65,-.36, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-.55, -.16, 0.0);
    glVertex3f(-.65,-.36, 0.0);
    glEnd();
    
    // V2
    
    glBegin(GL_LINES);
    glVertex3f(.52, -.26, 0.0);
    glVertex3f(.55,-.36, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(.65, -.16, 0.0);
    glVertex3f(.55,-.36, 0.0);
    glEnd();
}

void drawInt() {
    glLineWidth(2.5);
    glColor3f(1.0f, 1.0f, 1.0f);
    
    float ya = -.9;
    float yb = -.75;
    
    // A
    
    glBegin(GL_LINES);
    glVertex3f(-.9, ya, 0.0);
    glVertex3f(-.85, yb, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-.8, ya, 0.0);
    glVertex3f(-.85, yb, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-.9, ya, 0.0);
    glVertex3f(-.85, yb, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-.88, -.85, 0.0);
    glVertex3f(-.82, -.85, 0.0);
    glEnd();
    
    // -
    
    glBegin(GL_LINES);
    glVertex3f(-.73, -.85, 0.0);
    glVertex3f(-.7, -.85, 0.0);
    glEnd();
    
    // - I
    
    glBegin(GL_LINES);
    glVertex3f(-.6, ya, 0.0);
    glVertex3f(-.6, yb, 0.0);
    glEnd();
    
    // - N
    
    glBegin(GL_LINES);
    glVertex3f(-.55, ya, 0.0);
    glVertex3f(-.55, yb, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-.55, yb, 0.0);
    glVertex3f(-.5, ya, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-.5, ya, 0.0);
    glVertex3f(-.5, yb, 0.0);
    glEnd();
    
    // - T
    
    glBegin(GL_LINES);
    glVertex3f(-.46, yb, 0.0);
    glVertex3f(-.37, yb, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-.415, ya, 0.0);
    glVertex3f(-.415, yb, 0.0);
    glEnd();
}

void drawUni() {
    glLineWidth(2.5);
    glColor3f(1.0f, 1.0f, 1.0f);
    
    float ya = -.9;
    float yb = -.75;
    
    // B
    
    glBegin(GL_LINES);
    glVertex3f(.1, ya, 0.0);
    glVertex3f(.1, yb, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(.1, yb, 0.0);
    glVertex3f(.16, yb, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(.16, yb, 0.0);
    glVertex3f(.13, -.825, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(.13, -.825, 0.0);
    glVertex3f(.16, ya, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(.16, ya, 0.0);
    glVertex3f(.1, ya, 0.0);
    glEnd();
    
    // -
    
    glBegin(GL_LINES);
    glVertex3f(.2, -.83, 0.0);
    glVertex3f(.23, -.83, 0.0);
    glEnd();
    
    // U
    
    glBegin(GL_LINES);
    glVertex3f(.3, ya, 0.0);
    glVertex3f(.3, yb, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(.3, ya, 0.0);
    glVertex3f(.37, ya, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(.37, ya, 0.0);
    glVertex3f(.37, yb, 0.0);
    glEnd();
    
    // - N
    
    glBegin(GL_LINES);
    glVertex3f(.46, ya, 0.0);
    glVertex3f(.46, yb, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(.46, ya, 0.0);
    glVertex3f(.41, yb, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(.41, ya, 0.0);
    glVertex3f(.41, yb, 0.0);
    glEnd();
    
    // - I
    
    glBegin(GL_LINES);
    glVertex3f(.5, ya, 0.0);
    glVertex3f(.5, yb, 0.0);
    glEnd();
    
}

void drawRetangle1() {
    
    glLineWidth(2.5);
    glColor3f(1.0f, 1.0f, 1.0f);
    
    glBegin(GL_LINES);
    glVertex3f(-.9, .7, 0.0);
    glVertex3f(.9, .7, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-.9, .1, 0.0);
    glVertex3f(.9, .1, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-.9, .7, 0.0);
    glVertex3f(-.9, .1, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(.9, .7, 0.0);
    glVertex3f(.9, .1, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(0, .7, 0.0);
    glVertex3f(0, .1, 0.0);
    glEnd();
    
}

void drawRetangle2() {
    
    glLineWidth(2.5);
    glColor3f(1.0f, 1.0f, 1.0f);
    
    glBegin(GL_LINES);
    glVertex3f(-.4, -.06, 0.0);
    glVertex3f(.4, -.06, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-.4, -.45, 0.0);
    glVertex3f(.4, -.45, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(-.4, -.06, 0.0);
    glVertex3f(-.4, -.45, 0.0);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex3f(.4, -.06, 0.0);
    glVertex3f(.4, -.45, 0.0);
    glEnd();
}

void displayTorus2() {
    GLfloat x = -.2;
    GLfloat y = -.25;
    GLfloat z = 0;
    
    glPushMatrix();
    glColor3f(0, 1, 1);
    
    glTranslatef(-x, y, z);
    glScalef(.2, .2, 1);
    glRotatef(angle, 1, 1, 1);
    glutSolidTorus(.1, .5, 20, 20);
    
    glPopMatrix();
}

void displayCone2() {
    glPushMatrix();
    
    GLfloat x = .2;
    GLfloat y = -.25;
    GLfloat z = 0;
    
    glColor3f(1, 1, 0);
    
    glTranslatef(-x, y, z);
    glRotatef(angle, 1, 1, 1);
    glutSolidCone(.15, .15, 20, 20);
    glPopMatrix();
}

void displaySphere2() {
    glPushMatrix();
    GLfloat x = -.25;
    GLfloat y = .5;
    GLfloat z = 0;
    
    glColor3f(0, 1, 0);
    glTranslatef(-x, y, z);
    glRotatef(angle, 1.0f, 1.0f, 1.0f);
    glutWireSphere(.1, 20, 20);
    glPopMatrix();
}

void displayTeapot2() {
    glPushMatrix();
    
    GLfloat x = -.5;
    GLfloat y = .25;
    GLfloat z = 0;
    
    glColor3f(1, 0, 0);
    glTranslatef(-x, y, z);
    glRotatef(angle, 1.0f, 1.0f, 1.0f);
    glutSolidTeapot(.1);
    glPopMatrix();
}

void displayTorus1() {
    GLfloat x = -.7;
    GLfloat y = .5;
    GLfloat z = 0;
    
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(-x, y, z);    
    glScalef(.2, .2, 1);
    glRotatef(angle, 1.0f, 1.0f, 1.0f);
    glutSolidTorus(.1, .5, 20, 20);
    glPopMatrix();
}

void displayCone1() {
    glPushMatrix();
    
    GLfloat x = .53;
    GLfloat y = .28;
    GLfloat z = 0;
    
    glColor3f(0, 0, 1);
    glTranslatef(-x, y, z);
    glRotatef(angle, 1.0f, 1.0f, 1.0f);
    glutSolidCone(.15, .15, 20, 20);
    glPopMatrix();
}

void displaySphere1() {
    glPushMatrix();
    GLfloat x = .25;
    GLfloat y = .5;
    GLfloat z = 0;
    
    glColor3f(0, 1, 0);
    glTranslatef(-x, y, z);
    glRotatef(angle, 1.0f, 1.0f, 1.0f);
    glutWireSphere(.1, 20, 20);
    glPopMatrix();
}

void displayTeapot1() {
    glPushMatrix();
    
    GLfloat x = .7;
    GLfloat y = .52;
    GLfloat z = 0;
    
    glColor3f(1, 0, 0);
    glTranslatef(-x, y, z);
    glRotatef(angle, 1.0f, 1.0f, 1.0f);
    glutSolidTeapot(.1);
    glPopMatrix();
}

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel(GL_SMOOTH);
    
    // Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
    
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void reshape(GLsizei width, GLsizei height) {
    
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(200.0f, aspect, 10.0f, 10.0f);
}

void display() {
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    
    displayTorus1();
    displayTeapot1();
    displaySphere1();
    displayCone1();
    displayTeapot2();
    displaySphere2();
    
    drawRetangle1();
    
    drawRetangle2();
    
    displayCone2();
    displayTorus2();
    
    drawInt();
    drawUni();
    
    if (correct == 1) {
        drawV();
    } else if (correct == 2) {
        drawX();
    }
    
    glFlush();
    glutSwapBuffers();
    
    angle -= 3.f;
}

void keyboard(unsigned char key, int x, int y) {
    
    switch (key) {
        case 'A':
        case 'a': {
            correct = 1;
            break;
        }
        case 'B':
        case 'b': {
            correct = 2;
            break;
        }
            
        default:
            break;
    }
    
    glutPostRedisplay();
}

void timer(int value) {
    
    glutPostRedisplay();
    glutTimerFunc(refreshMills, timer, 0);
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(50, 50);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Teoria dos conjuntos");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    initGL();
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}

#ifdef __APPLE__
#pragma clang diagnostic pop
#endif

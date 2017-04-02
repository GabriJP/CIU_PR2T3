/*
Prototipo de programa principal
ULPGC, EII, Creando Interfaces de Usuario
*/

#include <stdio.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
int win1, win2;
#pragma clang diagnostic pop

void InitGlew(){
    GLenum glew_init = glewInit();
    if (glew_init != GLEW_OK){
        fprintf(stderr, "Error %s\n", glewGetErrorString(glew_init));
    }
    else {
        printf("Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    }
}

void Init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, 0.0f);
}

void Display1(){
    glClear(GL_COLOR_BUFFER_BIT);

    glutWireTeapot(0.5);
    glFlush();
}

void Display2(){
    glClear(GL_COLOR_BUFFER_BIT);

    glutWireTeapot(0.5);
    glFlush();
}

void Dimensiones(int ancho, int alto){
    float dx = 2.0;
    float dy = 2.0;

    if (ancho > alto){
        dx = (float) (2.0 * (float)ancho / (float)alto);
    }
    if (alto > ancho){
        dy = (float) (2.0 * (float)alto / (float)ancho);
    }

    glViewport(0, 0, ancho, alto);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, 1.0f, 0.0f);
    glutPostRedisplay();
}


int main(int argc, char *argv[]){
    glutInit(&argc, argv);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(300, 300);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

    win1 = glutCreateWindow("OpenGL Práctica 2_3. Ventana 1");
    InitGlew();
    Init();
    glutDisplayFunc(Display1);

    win2 = glutCreateWindow("OpenGL Práctica 2_3. Ventana 2");
    Init();
    glutDisplayFunc(Display2);
    glutReshapeFunc(Dimensiones);

    glutMainLoop();

    return 0;
}
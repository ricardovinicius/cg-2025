#include <stdio.h>
#include <tgmath.h>

#include <GL/gl.h>
#include <GL/glut.h>

#define MY_CIRCLE_LIST 1
#define PI M_PI

void Init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);

  glMatrixMode(GL_PROJECTION);
}

void buildCircle() {
  GLint i;
  GLfloat cosine, sine;

  glNewList(MY_CIRCLE_LIST, GL_COMPILE);
  glBegin(GL_POLYGON);
  glClear(GL_COLOR_BUFFER_BIT); // Limpa o Buffer de Cor

  glColor3f(0.0, 0.0, 1.0); // Seta a cor da linha
  for (i = 0; i < 100; i++) {
    cosine = cos(i * 2 * PI / 100.0);
    sine = sin(i * 2 * PI / 100.0);
    glVertex2f(cosine, sine);
  }
  glEnd();
  glEndList();
}

void drawCircle() {
  buildCircle();
  glCallList(MY_CIRCLE_LIST);

  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutCreateWindow("OpenGL é Massa");

  glutInitWindowSize(500, 500);

  Init();

  glutDisplayFunc(drawCircle);

  glutMainLoop();
}

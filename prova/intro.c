#include <GL/gl.h>
#include <GL/glut.h>

void Init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);

  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void LineSegment() {
  glClear(GL_COLOR_BUFFER_BIT); // Limpa o Buffer de Cor

  glColor3f(1.0, 0.0, 0.0); // Seta a cor da linha
  glBegin(GL_LINES);
  glVertex2d(0, 0);
  glVertex2d(200, 150);
  glEnd();

  glFlush(); // Processa as rotinas do OpenGL
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutCreateWindow("OpenGL é Massa");

  glutInitWindowSize(500, 500);

  Init();

  glutDisplayFunc(LineSegment);

  glutMainLoop();
}

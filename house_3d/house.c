#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

/*
Definição do cabeçalho das funções
 */
void init();
void display();
void keyboard(unsigned char key, int x, int y);
void reshape(int w, int h);

/*
Definição das Cores
 */

#define  VERMELHO  1.0, 0.0, 0.0
#define  GREEN     0.0, 1.0, 0.0
#define  AZUL      0.0, 0.0, 1.0
#define  AMARELO   1.0, 1.0, 0.0
#define  CYAN      0.0, 1.0, 1.0
#define  ROXO      1.0, 0.0, 1.0

/*
Definição dos Vértices da figura

Formato:
X, Y, Z, // N
 */

static GLfloat vertices[] = {
    00.0, 00.0, 00.0,    // 0
    30.0, 00.0, 00.0,    // 1
    30.0, 20.0, 00.0,    // 2
    00.0, 20.0, 00.0,    // 3
    00.0, 00.0, 20.0,    // 4
    00.0, 20.0, 20.0,    // 5
    30.0, 00.0, 20.0,    // 6
    30.0, 20.0, 20.0,    // 7
};

/*
Definição dos Polígonos
 */

static GLubyte fundoIndices[] = {0, 3, 2, 1};
static GLubyte frenteIndices[] = {4, 6, 7, 5};
static GLubyte direitaIndices[] = {0, 3, 5, 4};
static GLubyte esquerdaIndices[] = {1, 2, 7, 6};
static GLubyte topoIndices[] = {3, 5, 7, 2};
static GLubyte baseIndices[] = {0, 1, 6, 4};

/*
Definição das variáveis de posição
 */

static int eixo_y, eixo_x;
int largura, altura;

/*
Definição da main
 */

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitWindowSize(500, 500);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutCreateWindow("House 3D");

  init();

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}

/*
Definição do corpo das funções
 */

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glOrtho(-50, 50, -50, 50, -50, 50);
  glEnable(GL_DEPTH_TEST);
  // glEnable(GL_CULL_FACE);
}

void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  largura = w;
  altura = h;
}

void display() {
  glPushMatrix();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glRotatef((GLfloat) eixo_y, 1.0, 0.0, 0.0);
  glRotatef((GLfloat) eixo_x, 0.0, 1.0, 0.0);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);

  glColor3f(AZUL);
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, frenteIndices);

  glColor3f(GREEN);
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, esquerdaIndices);

  glColor3f(CYAN);
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, fundoIndices);

  glColor3f(ROXO);
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, direitaIndices);

  glColor3f(VERMELHO);
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, topoIndices);

  glColor3f(AMARELO);
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, baseIndices);


  glDisableClientState(GL_VERTEX_ARRAY);

  glPopMatrix();

  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
    case 27:
      exit(0);
    break;
    case 'a':
      printf("%d, %d\n",x,y);
    break;
    case 'y':
      eixo_y = (eixo_y + 5) % 360;
    glutPostRedisplay();
    break;
    case 'Y':
      eixo_y = (eixo_y - 5) % 360;
    glutPostRedisplay();
    break;
    case 'x':
      eixo_x = (eixo_x + 5) % 360;
    glutPostRedisplay();
    break;
    case 'X':
      eixo_x = (eixo_x - 5) % 360;
    glutPostRedisplay();
    break;
    case 'p':
      glLoadIdentity();
    gluPerspective(65.0, (GLfloat) largura/(GLfloat) altura, 20.0, 120.0);
    gluLookAt(0, 0, -90, 0, 0, 0, 0, 1, 0);
    glutPostRedisplay();
    break;
    case 'o':
      glLoadIdentity();
    glOrtho (-50, 50, -50, 50, -50 , 50);
    glutPostRedisplay();
    break;
  }
}





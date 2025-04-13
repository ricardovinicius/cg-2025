#include <GL/glut.h>
#include "app.h"

#include "render.h"
#include "config.h"

void display() {
  render_scene();
  glutSwapBuffers();
}

void app_init(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(APP_NAME);

  render_init();

  // TODO: modularize this callback register
  glutDisplayFunc(display);

  glutMainLoop();
}
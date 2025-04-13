#include <GL/glut.h>
#include "app.h"

#include <scene.h>

#include "render.h"
#include "config.h"
#include "scenes/game_scene.h"

void display() {
  render_display();
  glutSwapBuffers();
}

void app_init(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
  glutInitWindowPosition(100, 100);
  glutCreateWindow(APP_NAME);

  render_init(800, 600);

  game_scene_init();
  scene_set(&game_scene);

  // TODO: modularize this callback register
  glutDisplayFunc(display);

  glutMainLoop();
}
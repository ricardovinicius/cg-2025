//
// Created by vinia on 4/12/2025.
//

#include "render.h"

#include <scene.h>

#include "entities/field.h"

#include <GL/freeglut_std.h>
#include <GL/gl.h>

// void render_init() {
//   glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
//   glMatrixMode(GL_PROJECTION);
//   glLoadIdentity();
//   gluOrtho2D(0, 800, 0, 600);
//   glMatrixMode(GL_MODELVIEW);
// }

static double last_time = 0;

void render_init(int width, int height) {
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
  render_reshape(width, height);
}

void render_reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60.0, (float) w / (float) h, 1.0, 1000.0);
  glMatrixMode(GL_MODELVIEW);
}

void render_update(void) {
  double now = glutGet(GLUT_ELAPSED_TIME);
  double delta_time = now - last_time;
  last_time = now;

  scene_update(delta_time);
}

void render_display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(400, 200, 500,
    400, 300, 0,
    0, 1, 0);

  scene_render();

  glutSwapBuffers();
}
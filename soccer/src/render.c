//
// Created by vinia on 4/12/2025.
//

#include "render.h"

#include <bresenham.h>
#include <math.h>
#include <GL/freeglut_std.h>
#include <GL/gl.h>

void render_init() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 800, 0, 600);
  glMatrixMode(GL_MODELVIEW);
}

void render_scene() {
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();

  glColor3f(COLOR_WHITE.red, COLOR_WHITE.green, COLOR_WHITE.blue);
  glPointSize(5);

  glBegin(GL_POINTS);
  bresenham_line(10, 10, 20, 200);
  bresenham_arc(100, 100, 50, 0, 90);
  glEnd();


  glutSwapBuffers();
}
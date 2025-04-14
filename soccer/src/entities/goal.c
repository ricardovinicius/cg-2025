//
// Created by vinia on 4/13/2025.
//

#include "goal.h"

#include <color.h>
#include <GL/gl.h>

void goal_init(Goal *goal) {
  goal->x = 0.0f;
  goal->y = 0.0f;
  goal->z = 0.0f;

  goal->width = 106.0f;
  goal->height = 50.0f;
  goal->depth = 50.0f;
}

void goal_draw(Goal *goal) {
  float x = goal->x;
  float y = goal->y;
  float z = goal->z;
  float w = goal->width;
  float h = goal->height;
  float d = goal->depth;

  float x0 = x;
  float x1 = x + d;
  float y0 = y;
  float y1 = y + w;
  float z0 = z;
  float z1 = z + h;

  glColor3f(COLOR_WHITE.red, COLOR_WHITE.green, COLOR_WHITE.blue);

  glBegin(GL_LINES);

  // base
  glVertex3f(x0, y0, z0); glVertex3f(x1, y0, z0);
  glVertex3f(x1, y0, z0); glVertex3f(x1, y0, z1);
  glVertex3f(x1, y0, z1); glVertex3f(x0, y0, z1);
  glVertex3f(x0, y0, z1); glVertex3f(x0, y0, z0);

  // topo
  glVertex3f(x0, y1, z0); glVertex3f(x1, y1, z0);
  glVertex3f(x1, y1, z0); glVertex3f(x1, y1, z1);
  glVertex3f(x1, y1, z1); glVertex3f(x0, y1, z1);
  glVertex3f(x0, y1, z1); glVertex3f(x0, y1, z0);

  // colunas verticais
  glVertex3f(x0, y0, z0); glVertex3f(x0, y1, z0);
  glVertex3f(x1, y0, z0); glVertex3f(x1, y1, z0);
  glVertex3f(x1, y0, z1); glVertex3f(x1, y1, z1);
  glVertex3f(x0, y0, z1); glVertex3f(x0, y1, z1);

  glEnd();
}

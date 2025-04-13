//
// Created by vinia on 4/13/2025.
//

#include <GL/glut.h>

#include "ball.h"


void ball_init(Ball *b) {
  b->x = 400.0f;
  b->y = 300.0f;
  b->z = 0.0f;
  b->radius = 10.0f;
  b->color = COLOR_BLUE;
}

void ball_draw(const Ball *b) {
  glPushMatrix();
  glTranslatef(b->x, b->y, b->z);
  glColor3f(b->color.red, b->color.green, b->color.blue);
  glutWireSphere(b->radius, 10, 10);
  glPopMatrix();
}

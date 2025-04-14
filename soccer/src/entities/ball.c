//
// Created by vinia on 4/13/2025.
//

#include <GL/glut.h>

#include "ball.h"

#include <input.h>
#include <math.h>
#include <stdio.h>


void ball_init(Ball *b) {
  b->x = 400.0f;
  b->y = 300.0f;
  b->z = 0.0f;
  b->vx = 0.0f;
  b->vy = 0.0f;
  b->vz = 0.0f;
  b->radius = 10.0f;
  b->color = COLOR_BLACK;
}

void ball_reset(Ball *b) {
  b->x = 400.0f;
  b->y = 300.0f;
  b->z = 0.0f;
  b->vx = 0.0f;
  b->vy = 0.0f;
  b->vz = 0.0f;
}

void ball_update(Ball *b, float dt) {
  b->x += b->vx * dt;
  b->y += b->vy * dt;
  b->z += b->vz * dt;
}


void ball_handle_input(Ball *b) {
  float speed = 0.1f;
  float dx = 0;
  float dy = 0;

  if (input_is_key_pressed('w')) dy += 1;
  if (input_is_key_pressed('s')) dy -= 1;
  if (input_is_key_pressed('a')) dx -= 1;
  if (input_is_key_pressed('d')) dx += 1;

  // Normaliza se estiver se movendo
  float length = sqrtf(dx * dx + dy * dy);
  if (length > 0) {
    dx /= length;
    dy /= length;
  }

  b->vx = dx * speed;
  b->vy = dy * speed;
}

void ball_draw(const Ball *b) {
  glPushMatrix();
  glTranslatef(b->x, b->y, b->z);

  glColor3f(b->color.red, b->color.green, b->color.blue);
  glutWireSphere(b->radius, 20, 20);

  glPopMatrix();
}

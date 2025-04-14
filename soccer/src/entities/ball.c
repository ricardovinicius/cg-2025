//
// Created by vinia on 4/13/2025.
//

#include <GL/glut.h>

#include "ball.h"

#include <input.h>
#include <math.h>
#include <stdio.h>

char* BALL_TEXTURE_PATH = "./assets/textures/ball.jpg";

void ball_init(Ball *b) {
  b->x = 400.0f;
  b->y = 300.0f;
  b->z = 0.0f;
  b->vx = 0.0f;
  b->vy = 0.0f;
  b->vz = 0.0f;
  b->rotation_angle = 0.0f;
  b->radius = 10.0f;
  b->color = COLOR_BLACK;
  b->texture = load_texture(BALL_TEXTURE_PATH);
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

  float speed = sqrtf(b->vx * b->vx + b->vy * b->vy);
  b->rotation_angle += speed * dt * 45;

  if (b->rotation_angle > 360) b->rotation_angle -= 360;
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
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, b->texture.id);

  GLUquadric* quad = gluNewQuadric();
  gluQuadricTexture(quad, GL_TRUE);

  glPushMatrix();
  glTranslatef(b->x, b->y, b->z);

  glRotatef(b->rotation_angle, 0, 1, 0);

  gluSphere(quad, b->radius, 20, 20);

  glPopMatrix();

  gluDeleteQuadric(quad);
  glDisable(GL_TEXTURE_2D);
}

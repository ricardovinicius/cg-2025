//
// Created by vinia on 4/13/2025.
//

#ifndef BALL_H
#define BALL_H

#include <texture.h>

#include "../color.h"

typedef struct {
  float x, y, z;
  float vx, vy, vz;
  int radius;
  float rotation_angle;
  Color color;
  Texture texture;
} Ball;

void ball_init(Ball *b);
void ball_update(Ball *b, float dt);
void ball_draw(const Ball *b);
void ball_handle_input(Ball *b);
void ball_reset(Ball *b);

#endif //BALL_H

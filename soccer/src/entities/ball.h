//
// Created by vinia on 4/13/2025.
//

#ifndef BALL_H
#define BALL_H

#include "../color.h"

typedef struct {
  int x, y, z;
  int radius;
  Color color;
} Ball;

void ball_init(Ball *b);
void ball_draw(const Ball *b);

#endif //BALL_H

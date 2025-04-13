//
// Created by vinia on 4/13/2025.
//

#include <stdio.h>
#include <GL/glut.h>
#include "bresenham.h"

void bresenham_line(int x0, int y0, int x1, int y1) {
  const int dx = x1 - x0;
  const int dy = y1 - y0;

  const int d_start = 2 * dy - dx;

  const int delta_e = 2 * dy;
  const int delta_ne = 2 * (dx - dy);

  int x = x0;
  int y = y0;

  int d = d_start;

  glColor3f(1.0, 0.0, 0.0);

  glBegin(GL_POINTS);

  while (x <= x1) {
    glVertex2i(x, y);
    printf("%i, %i\n", x, y);

    if (d > 0) {
      x += 1;
      y += 1;

      d += delta_ne;
    } else {
      x += 1;

      d += delta_e;
    }
  }

  glEnd();
}



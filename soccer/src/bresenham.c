//
// Created by vinia on 4/13/2025.
//

#include <stdio.h>
#include <GL/glut.h>
#include "bresenham.h"

#include <math.h>

void bresenham_line(int x0, int y0, int x1, int y1) {
  const int steep = abs(y1 - y0) > abs(x1 - x0);

  if (steep) {
    int temp;
    temp = x0;
    x0 = y0;
    y0 = temp;
    temp = x1;
    x1 = y1;
    y1 = temp;
  }

  if (x0 > x1) {
    int temp;
    temp = x0;
    x0 = x1;
    x1 = temp;
    temp = y0;
    y0 = y1;
    y1 = temp;
  }

  const int dx = x1 - x0;
  const int dy = abs(y1 - y0);
  const int sy = y0 < y1 ? 1 : -1;

  const int d_start = 2 * dy - dx;

  const int delta_e = 2 * dy;
  const int delta_ne = 2 * (dy - dx);

  int x = x0;
  int y = y0;

  int d = d_start;

  while (x <= x1) {
    if (steep) {
      glVertex2i(y, x);
    } else {
      glVertex2i(x, y);
    }

    if (d > 0) {
      y += sy;
      d += delta_ne;
    } else {
      d += delta_e;
    }

    x++;
  }
}

void plot_if_in_arc(int px, int py, float angle, float start_rad,
                    float end_rad) {
  if (angle < 0)
    angle += 2.0f * M_PI;

  if (start_rad < end_rad) {
    if (angle >= start_rad && angle <= end_rad)
      glVertex2i(px, py);
  } else {
    if (angle >= start_rad || angle <= end_rad)
      glVertex2i(px, py);
  }
}

void bresenham_arc(int xc, int yc, int r, int start_angle, int end_angle) {
  int x = 0, y = r;
  int d = 3 - 2 * r;

  float start_rad = start_angle * M_PI / 180.0f;
  float end_rad = end_angle * M_PI / 180.0f;

  while (x <= y) {
    // Ângulo base do ponto (x, y)
    float angle = atan2((float)y, (float)x);

    // Oitantes por simetria (0 a 7), com adição de múltiplos de π/2
    plot_if_in_arc(xc + x, yc + y, angle, start_rad, end_rad); // 1º octante
    plot_if_in_arc(xc - x, yc + y, M_PI - angle, start_rad, end_rad);
    // 2º octante
    plot_if_in_arc(xc - x, yc - y, M_PI + angle, start_rad, end_rad);
    // 3º octante
    plot_if_in_arc(xc + x, yc - y, 2 * M_PI - angle, start_rad, end_rad);
    // 4º octante

    plot_if_in_arc(xc + y, yc + x, M_PI_2 - angle, start_rad, end_rad);
    // 5º octante
    plot_if_in_arc(xc - y, yc + x, M_PI_2 + angle, start_rad, end_rad);
    // 6º octante
    plot_if_in_arc(xc - y, yc - x, 3 * M_PI_2 - angle, start_rad, end_rad);
    // 7º octante
    plot_if_in_arc(xc + y, yc - x, 3 * M_PI_2 + angle, start_rad, end_rad);
    // 8º octante

    if (d < 0) {
      d += 4 * x + 6;
    } else {
      d += 4 * (x - y) + 10;
      y--;
    }
    x++;
  }
}
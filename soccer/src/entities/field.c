//
// Created by vinia on 4/13/2025.
//

#include <GL/gl.h>

#include "field.h"
#include "../color.h"
#include "../bresenham.h"

void field_init(Field* field) {
  field->x = 0.0f;
  field->y = 0.0f;
  field->width = 1.0f;
  field->height = 1.0f;
}

void field_background_draw(Field* field) {
  float field_left = 0.0f;
  float field_right = 800.0f;
  float field_top = 600.0f;
  float field_bottom = 0.0f;

  float stripe_width = (field_right - field_left) / 8.0f;

  for (int i = 0; i < 8; i++) {
    // Alterna as cores entre verde escuro e claro
    if (i % 2 == 0)
      glColor3f(0.0f, 0.5f, 0.0f);  // Verde escuro
    else
      glColor3f(0.0f, 0.7f, 0.0f);  // Verde claro

    float x0 = field_left + i * stripe_width;
    float x1 = x0 + stripe_width;

    glBegin(GL_POLYGON);
    glVertex2f(x0, field_top);
    glVertex2f(x1, field_top);
    glVertex2f(x1, field_bottom);
    glVertex2f(x0, field_bottom);
    glEnd();
  }
}


void field_draw(Field* field) {
  glColor3f(0.0f, 1.0f, 0.0f);

  // Background
  glBegin(GL_POLYGON);

  glEnd();

  glColor3f(COLOR_WHITE.red, COLOR_WHITE.green, COLOR_WHITE.blue);
  glPointSize(3.0);

  glBegin(GL_POINTS);

  // Field boundaries (rectangle)
  bresenham_line(field->x, field->y, field->x + field->width,
                 field->y); // Top side
  bresenham_line(field->x + field->width, field->y, field->x + field->width,
                 field->y + field->height); // Right side
  bresenham_line(field->x + field->width, field->y + field->height, field->x,
                 field->y + field->height); // Bottom side
  bresenham_line(field->x, field->y + field->height, field->x, field->y);
  // Left side

  // Center line
  bresenham_line(400, 67, 400, 533);

  // Center circle
  bresenham_arc(400, 300, 53, 0, 360);

  // Center point
  bresenham_line(400, 300, 400, 300);

  // Left penalty box
  bresenham_line(67, 180, 173, 180);
  bresenham_line(173, 180, 173, 420);
  bresenham_line(173, 420, 67, 420);

  // Right penalty box
  bresenham_line(733, 180, 627, 180);
  bresenham_line(627, 180, 627, 420);
  bresenham_line(627, 420, 733, 420);

  // Left goal area
  bresenham_line(67, 247, 120, 247);
  bresenham_line(120, 247, 120, 353);
  bresenham_line(120, 353, 67, 353);

  // Right goal area
  bresenham_line(733, 247, 680, 247);
  bresenham_line(680, 247, 680, 353);
  bresenham_line(680, 353, 733, 353);

  // Left penalty spot
  bresenham_line(147, 300, 147, 300);

  // Right penalty spot
  bresenham_line(653, 300, 653, 300);

  // Left penalty arc
  bresenham_arc(147, 300, 47, 308, 54);

  // Right penalty arc
  bresenham_arc(653, 300, 47, 128, 234);

  // Corner kick arcs
  bresenham_arc(67, 533, 20, 270, 360); // Bottom-left
  bresenham_arc(67, 67, 20, 0, 90); // Top-left
  bresenham_arc(733, 67, 20, 90, 180); // Top-right
  bresenham_arc(733, 533, 20, 180, 270); // Bottom-right

  glEnd();
}
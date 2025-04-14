//
// Created by vinia on 4/14/2025.
//

#include <GL/glut.h>

#include "text.h"


void render_bitmap_string_shadow(float x, float y, void *font, const char *string) {
  // Sombra (preta)
  glColor3f(0.0f, 0.0f, 0.0f);
  glRasterPos2f(x + 1.5f, y - 1.5f);
  for (const char *c = string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }

  // Texto (branco)
  glColor3f(1.0f, 1.0f, 1.0f);
  glRasterPos2f(x, y);
  for (const char *c = string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}
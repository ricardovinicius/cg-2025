//
// Created by vinia on 4/12/2025.
//

#include "input.h"

#include <stdio.h>
#include <GL/freeglut_std.h>

static unsigned char keys[256];

void input_key_down(unsigned char key, int x, int y) {
  keys[key] = 1;
}

void input_key_up(unsigned char key, int x, int y) {
  keys[key] = 0;
}

int input_is_key_pressed(unsigned char key) {
  return keys[key];
}

void input_init(void) {
  for (int i = 0; i < 256; i++) {
    keys[i] = 0;
  }

  glutKeyboardFunc(input_key_down);
  glutKeyboardUpFunc(input_key_up);
}
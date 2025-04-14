//
// Created by vinia on 4/13/2025.
//

#include <stdio.h>

#include "scoreboard.h"

void scoreboard_init(Scoreboard* s) {
  s->left_score = 0;
  s->right_score = 0;
}

void scoreboard_reset(Scoreboard* s) {
  s->left_score = 0;
  s->right_score = 0;
}

void scoreboard_print(Scoreboard* s) {
  printf("Placar: %d x %d\n", s->left_score, s->right_score);
}
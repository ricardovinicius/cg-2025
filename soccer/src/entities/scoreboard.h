//
// Created by vinia on 4/13/2025.
//

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

typedef struct {
  int left_score;
  int right_score;
} Scoreboard;

void scoreboard_init(Scoreboard *s);
void scoreboard_reset(Scoreboard *s);
void scoreboard_print(Scoreboard *s);

#endif //SCOREBOARD_H

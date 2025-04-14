//
// Created by vinia on 4/14/2025.
//

#ifndef HUD_H
#define HUD_H

#include "scoreboard.h"

typedef struct {
  Scoreboard *scoreboard;
  float *time_remaining;
} HUD;

void hud_init(HUD *hud, Scoreboard *scoreboard, float *time_remaining);
void hud_draw(HUD *hud);

#endif //HUD_H

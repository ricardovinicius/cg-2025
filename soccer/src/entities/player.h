//
// Created by vinia on 4/14/2025.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "../texture.h"

typedef struct {
  float x, y;
  float width, height;
  Texture texture;
} Player;

void player_init(Player *p, const char* texture_path, float x, float y, float w, float h);
void player_draw(Player *p);

#endif //PLAYER_H

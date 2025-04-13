//
// Created by vinia on 4/13/2025.
//

#include "game_scene.h"
#include "../entities/field.h"
#include "../entities/ball.h"
#include "../scene.h"

static Ball ball;

static void game_render(void) {
  field_draw();
  ball_draw(&ball);
}

Scene game_scene = {
  .update = &game_render,
  .render = &game_render,
};

void game_scene_init(void) {
  ball_init(&ball);
}

//
// Created by vinia on 4/14/2025.
//

#include "menu_scene.h"
#include "game_scene.h"
#include "../scene.h"
#include "../entities/menu.h"
#include "../input.h"


void menu_render() {
  menu_draw();
}

void menu_update() {
  if (input_is_key_pressed('x') || input_is_key_pressed('X')) {
    game_scene_init();
    scene_set(&game_scene);
  }
}

Scene menu_scene = {
  .update = &menu_update,
  .render = &menu_render,
};
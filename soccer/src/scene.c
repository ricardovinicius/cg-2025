//
// Created by vinia on 4/12/2025.
//

#include "scene.h"

#include <stddef.h>

static Scene* current_scene = NULL;

void scene_set(Scene *scene) {
  current_scene = scene;
  if (current_scene && current_scene->init)
    current_scene->init();
}

void scene_update(void) {
  if (current_scene && current_scene->update)
    current_scene->update();
}

void scene_render(void) {
  if (current_scene && current_scene->render)
    current_scene->render();
}
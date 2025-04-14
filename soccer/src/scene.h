//
// Created by vinia on 4/12/2025.
//

#ifndef SCENE_H
#define SCENE_H

typedef struct {
    void (*init)(void);
    void (*update)(double delta_time);
    void (*render)(void);
} Scene;

void scene_set(Scene *scene);
void scene_update(double delta_time);
void scene_render(void);

#endif //SCENE_H

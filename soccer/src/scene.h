//
// Created by vinia on 4/12/2025.
//

#ifndef SCENE_H
#define SCENE_H

typedef struct {
    void (*init)(void);
    void (*update)(void);
    void (*render)(void);
} Scene;

void scene_set(Scene *scene);
void scene_update(void);
void scene_render(void);

#endif //SCENE_H

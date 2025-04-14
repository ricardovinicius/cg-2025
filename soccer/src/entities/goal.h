//
// Created by vinia on 4/13/2025.
//

#ifndef GOAL_H
#define GOAL_H

typedef struct {
    float x, y, z;
    float width, height, depth;
} Goal;

void goal_init(Goal *goal);
void goal_draw(Goal *goal);

#endif //GOAL_H

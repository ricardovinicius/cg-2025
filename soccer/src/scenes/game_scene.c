//
// Created by vinia on 4/13/2025.
//

#include <stdio.h>

#include "game_scene.h"

#include <stdlib.h>
#include <entities/goal.h>
#include <entities/scoreboard.h>

#include "../entities/field.h"
#include "../entities/ball.h"
#include "../scene.h"

static Ball ball;
static Goal left_goal;
static Goal right_goal;
static Scoreboard scoreboard;

int ball_inside_goal(Ball* ball, Goal* goal) {
  float distance_x = abs(ball->x - goal->x);

  return (distance_x < ball->radius && ball->y > goal->y && ball->y < goal->
          width + goal->y);
}

void check_goal(Ball* ball, Goal* left_goal, Goal* right_goal,
                Scoreboard* scoreboard) {
  if (ball_inside_goal(ball, left_goal)) {
    scoreboard->right_score++;
    ball_reset(ball);
    scoreboard_print(scoreboard);
  } else if (ball_inside_goal(ball, right_goal)) {
    scoreboard->left_score++;
    ball_reset(ball);
    scoreboard_print(scoreboard);
  }
}

static void game_render(void) {
  field_draw();
  ball_draw(&ball);
  goal_draw(&left_goal);
  goal_draw(&right_goal);
}

void game_update(double delta_time) {
  ball_update(&ball, delta_time);
  ball_handle_input(&ball);
  check_goal(&ball, &left_goal, &right_goal, &scoreboard);
}

void game_scene_init(void) {
  ball_init(&ball);
  goal_init(&left_goal);
  left_goal.x = 67;
  left_goal.y = 247;
  left_goal.depth *= -1;
  goal_init(&right_goal);
  right_goal.x = 733;
  right_goal.y = 247;
  scoreboard_init(&scoreboard);
}

Scene game_scene = {
    .update = &game_update,
    .render = &game_render,
};
//
// Created by vinia on 4/13/2025.
//

#include "game_scene.h"

#include <math.h>
#include <stdlib.h>
#include <entities/goal.h>
#include <entities/player.h>
#include <entities/scoreboard.h>

#include "menu_scene.h"
#include "../entities/field.h"
#include "../entities/ball.h"
#include "../entities/hud.h"
#include "../scene.h"

#define NUM_PLAYERS_PER_TEAM 5
#define MATCH_TIME 90

static Player team_left[NUM_PLAYERS_PER_TEAM];
static Player team_right[NUM_PLAYERS_PER_TEAM];
static Ball ball;
static Goal left_goal;
static Goal right_goal;
static Scoreboard scoreboard;
static Field field;
static HUD hud;
static float time_remaining;

static float left_team_positions[NUM_PLAYERS_PER_TEAM][2] = {
  {77, 300},   // Goleiro
  {150, 220},  // Defensor 1
  {150, 380},  // Defensor 2
  {250, 300},  // Meio
  {350, 300}   // Atacante
};

static float right_team_positions[NUM_PLAYERS_PER_TEAM][2] = {
  {723, 300},  // Goleiro
  {650, 220},  // Defensor 1
  {650, 380},  // Defensor 2
  {550, 300},  // Meio
  {450, 300}   // Atacante
};


int ball_inside_goal(Ball* ball, Goal* goal) {
  float distance_x = abs(ball->x - goal->x);

  return (distance_x < ball->radius && ball->y > goal->y && ball->y < goal->
          width + goal->y);
}

int check_goal() {
  if (ball_inside_goal(&ball, &left_goal)) {
    scoreboard.right_score++;
    ball_reset(&ball);
    scoreboard_print(&scoreboard);
    return 0;
  }

  if (ball_inside_goal(&ball, &right_goal)) {
    scoreboard.left_score++;
    ball_reset(&ball);
    scoreboard_print(&scoreboard);
    return 0;
  }

  return -1;
}

void limit_ball_on_field() {
  if (ball.x <= field.x) {
    ball.x = field.x;
  }

  if (ball.y <= field.y) {
    ball.y = field.y;
  }

  if (ball.x >= field.x + field.width) {
    ball.x = field.x + field.width;
  }

  if (ball.y >= field.y + field.height) {
    ball.y = field.y + field.height;
  }
}

void limit_ball_on_players() {
  for (int i = 0; i < NUM_PLAYERS_PER_TEAM; i++) {
    Player *p1 = &team_left[i];
    Player *p2 = &team_right[i];

    // verifica colisão com jogador do time esquerdo
    float dx1 = ball.x - p1->x;
    float dy1 = ball.y - p1->y;
    float dist1 = sqrtf(dx1 * dx1 + dy1 * dy1);
    float min_dist1 = ball.radius + (p1->width / 2.0f); // assumindo jogador como círculo

    if (dist1 < min_dist1) {
      float overlap = min_dist1 - dist1;
      ball.x += (dx1 / dist1) * overlap;
      ball.y += (dy1 / dist1) * overlap;
    }

    // verifica colisão com jogador do time direito
    float dx2 = ball.x - p2->x;
    float dy2 = ball.y - p2->y;
    float dist2 = sqrt(dx2 * dx2 + dy2 * dy2);
    float min_dist2 = ball.radius + (p2->width / 2.0f);

    if (dist2 < min_dist2) {
      float overlap = min_dist2 - dist2;
      ball.x += (dx2 / dist2) * overlap;
      ball.y += (dy2 / dist2) * overlap;
    }
  }
}

void check_sides() {
  if (check_goal() == -1) {
    limit_ball_on_field();
    limit_ball_on_players();
  }
}


static void game_render(void) {
  field_background_draw(&field);
  field_draw(&field);
  ball_draw(&ball);
  goal_draw(&left_goal);
  goal_draw(&right_goal);
  hud_draw(&hud);

  for (int i = 0; i < NUM_PLAYERS_PER_TEAM; i++) {
    player_draw(&team_left[i]);
    player_draw(&team_right[i]);
  }
}

void game_update(double delta_time) {
  check_sides();
  ball_update(&ball, delta_time);
  ball_handle_input(&ball);

  if (time_remaining > 0) {
    time_remaining -= delta_time / 1000.0f;

    if (time_remaining < 0.0) {
      time_remaining = 0.0;
    }
  } else {
    scene_destroy();
    scene_set(&menu_scene);
  }
}

void game_scene_init(void) {
  time_remaining = MATCH_TIME;

  field_init(&field);
  field.x = 67.0f;
  field.y = 67.0f;
  field.width = 666.0f;
  field.height = 466.0f;

  ball_init(&ball);

  goal_init(&left_goal);
  left_goal.x = 67;
  left_goal.y = 247;
  left_goal.depth *= -1;

  goal_init(&right_goal);
  right_goal.x = 733;
  right_goal.y = 247;

  scoreboard_init(&scoreboard);

  hud_init(&hud, &scoreboard, &time_remaining);

  for (int i = 0; i < NUM_PLAYERS_PER_TEAM; i++) {
    player_init(&team_left[i], "./assets/textures/blue_player.png",
                left_team_positions[i][0], left_team_positions[i][1],
                30, 30);

    player_init(&team_right[i], "./assets/textures/red_player.png",
                right_team_positions[i][0], right_team_positions[i][1],
                30, 30);
  }

}

void scene_destroy(void) {
  for (int i = 0; i < NUM_PLAYERS_PER_TEAM; i++) {
    team_left[i] = (Player){0};
    team_right[i] = (Player){0};
  }

  ball = (Ball){0};
  left_goal = (Goal){0};
  right_goal = (Goal){0};
  scoreboard = (Scoreboard){0};
  field = (Field){0};
  hud = (HUD){0};
  time_remaining = 0.0f;
}


Scene game_scene = {
  .update = &game_update,
  .render = &game_render,
  .destroy = &scene_destroy,
};
//
// Created by vinia on 4/14/2025.
//

#include <GL/glut.h>
#include <stdio.h>

#include "hud.h"
#include "../text.h"

void hud_init(HUD *hud, Scoreboard *scoreboard, float *time_remaining) {
  hud->scoreboard = scoreboard;
  hud->time_remaining = time_remaining;
}

void render_translucent_rectangle(float x, float y, float width, float height) {
  glColor4f(0.0f, 0.0f, 0.0f, 0.2f); // Preto com 50% de opacidade

  glBegin(GL_QUADS);
  glVertex2f(x, y);
  glVertex2f(x + width, y);
  glVertex2f(x + width, y + height);
  glVertex2f(x, y + height);
  glEnd();
}

void hud_draw(HUD *hud) {
  char score_text[64];
  char time_text[64];

  sprintf(score_text, "Placar: %d x %d",
          hud->scoreboard->left_score,
          hud->scoreboard->right_score);

  sprintf(time_text, "Tempo: %.0fs", *(hud->time_remaining));

  glDisable(GL_DEPTH_TEST); // HUD deve sempre estar visível

  // Desenhando o fundo translúcido para o placar (topo esquerdo)
  float rect_width = 250.0f;
  float rect_height = 30.0f;

  // Ajusta o fundo para o placar no canto superior esquerdo
  render_translucent_rectangle(10.0f, 550.0f, rect_width, rect_height);

  // Ajusta o fundo para o tempo no canto superior direito
  render_translucent_rectangle(800.0f - rect_width - 10.0f, 550.0f, rect_width, rect_height);

  // Desenha o texto do placar no canto superior esquerdo
  void *font = GLUT_BITMAP_HELVETICA_18;
  render_bitmap_string_shadow(15.0f, 560.0f, font, score_text);

  // Desenha o texto do tempo no canto superior direito
  render_bitmap_string_shadow(800.0f - rect_width + 15.0f, 560.0f, font, time_text);

  glEnable(GL_DEPTH_TEST); // Habilita novamente o teste de profundidade
}



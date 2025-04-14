//
// Created by vinia on 4/14/2025.
//

#include <GL/glut.h>
#include <string.h>

#include "menu.h"
#include "../text.h"

#include <GL/glut.h>
#include <stdio.h>

void menu_draw() {
  char* game_title = "CG FUTEBOL";
  char* game_text = "Pressione X para continuar";

  glDisable(GL_DEPTH_TEST); // HUD deve sempre estar visível

  void* font = GLUT_BITMAP_HELVETICA_18;

  float title_x = 800.0f / 2.0f - (strlen(game_title) * 6);
  float title_y = 360.0f;  // Posição Y para o título
  render_bitmap_string_shadow(title_x, title_y, font, game_title);

  // Desenha o texto centralizado
  float text_x = 800.0f / 2.0f - (strlen(game_text) * 4);
  float text_y = 300.0f;  // Posição Y para o texto
  render_bitmap_string_shadow(text_x, text_y, font, game_text);

  glEnable(GL_DEPTH_TEST); // Habilita novamente o teste de profundidade
}


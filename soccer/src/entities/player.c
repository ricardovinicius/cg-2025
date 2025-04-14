//
// Created by vinia on 4/14/2025.
//

#include "player.h"

void player_init(Player *p, const char* texture_path, float x, float y, float w, float h) {
  p->x = x;
  p->y = y;
  p->width = w;
  p->height = h;
  p->texture = load_texture(texture_path);
}

void player_draw(Player* p) {
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, p->texture.id);
  glColor3f(1, 1, 1);

  glPushMatrix();
  glTranslatef(p->x, p->y, 0);  // Posição no mundo 3D

  glBegin(GL_QUADS);
  glTexCoord2f(0, 1); glVertex3f(-p->width / 2, -p->height / 2, 0);
  glTexCoord2f(1, 1); glVertex3f(p->width / 2, -p->height / 2, 0);
  glTexCoord2f(1, 0); glVertex3f(p->width / 2, p->height / 2, 0);
  glTexCoord2f(0, 0); glVertex3f(-p->width / 2, p->height / 2, 0);
  glEnd();

  glPopMatrix();
  glDisable(GL_TEXTURE_2D);
}
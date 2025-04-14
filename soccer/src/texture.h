//
// Created by vinia on 4/14/2025.
//

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glut.h>

typedef struct {
  GLuint id;
  int width, height;
} Texture;

Texture load_texture(const char *filename);
void free_texture(Texture* texture);

#endif //TEXTURE_H

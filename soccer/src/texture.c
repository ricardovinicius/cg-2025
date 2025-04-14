//
// Created by vinia on 4/14/2025.
//

#define STB_IMAGE_IMPLEMENTATION
#include "../lib/stb_image.h"
#include "texture.h"
#include <stdio.h>
#include <GLES3/gl3.h>

Texture load_texture(const char* filename) {
  Texture texture = {0, 0, 0};

  int width, height, channels;
  unsigned char* data = stbi_load(filename, &width, &height, &channels, 0);

  if (!data) {
    fprintf(stderr, "Failed to load texture %s\n", filename);
    return texture;
  }

  glGenTextures(1, &texture.id);
  glBindTexture(GL_TEXTURE_2D, texture.id);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  if (channels == 3) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, data);
  } else if (channels == 4) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
                 GL_UNSIGNED_BYTE, data);
  }

  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(data);

  texture.width = width;
  texture.height = height;

  return texture;
}
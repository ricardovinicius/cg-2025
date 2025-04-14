//
// Created by vinia on 4/13/2025.
//

#ifndef FIELD_H
#define FIELD_H

typedef struct {
    float x, y;
    float width, height;
} Field;

void field_init(Field *field);
void field_draw(Field *field);
void field_background_draw(Field *field);

#endif //FIELD_H

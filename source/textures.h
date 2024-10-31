#ifndef TEXT_
#define TEXT_

#include "raylib/src/raylib.h"
#include <stdlib.h>

Texture* InitTex();

Texture2D* InitiTex2D();

Texture2D* InitiTex2DI();

void freeTexturasD(Texture** TexturasD);

void freeTexturas2D(Texture2D** Texturas2D);

void freeTexturas2DI(Texture2D** Texturas2D);




#endif
#ifndef ANIMACAO
#define ANIMACAO

#include "raylib/src/raylib.h"

void AnimPlayer(Texture2D Player, float FrameWidth, int *frame, float *mov, float *x, float *y);

void AnimPato(Texture2D Pato, float FrameWidth2, int *frame2, float *mov2, float *px, float *py, float *x, float *y, float *Mov, int comida);

void AnimEspelho(Texture2D Espelho, int frame3, float x, float y);

Rectangle AnimFogo(Texture2D Fire);

void AnimItem(Texture2D *item, bool *itens, int qtdItens, float x, float y);

#endif

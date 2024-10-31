#ifndef PHASES
#define PHASES

#include "raylib/src/raylib.h"
#include "player.h"
#include "colisoes.h"
#include "animacao.h"

void phaseOne(Jogador *players, int *cenaAtual, Cenas *cena, Sound sound);

void phaseTwo(Jogador *player, int *cenaAtual, Cenas *cena, Sound sound, int* pato);

void phaseThree(Jogador *player, int *cenaAtual, Cenas *cena, Sound sound, int *frame1, int *frame2);

#endif

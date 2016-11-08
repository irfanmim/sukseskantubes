#ifndef PLAYER_H
#define PLAYER_H

#include "point.h"
#include "boolean.h"

typedef struct {
	point posisi;
	int HP;
	long EXP;
	long ATK;
	long DEF;
}

#define X(P) (P).posisi.X
#define Y(P) (P).posisi.Y
#define HP(P) (P).HP
#define EXP(P) (P).EXP
#define ATK(P) (P).ATK
#define DEF(P) (P).DEF

#endif

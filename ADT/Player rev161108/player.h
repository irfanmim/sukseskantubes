#ifndef PLAYER_H
#define PLAYER_H

#include "point.h"
#include "boolean.h"

typedef struct {
	POINT posisi;
	int HP;
	int LVL;
	long EXP;
	long ATK;
	long DEF;
} character;

#define X(P) (P).posisi.X
#define Y(P) (P).posisi.Y
#define HP(P) (P).HP
#define EXP(P) (P).EXP
#define ATK(P) (P).ATK
#define DEF(P) (P).DEF
#define LVL(P) (P).LVL

void HPUP (character *P1, int N);

void HPDOWN (character *P1, character P2);

boolean isLvlUp (character *P1, int Exp[]);

void LVLUP (character *P1, int Exp[]);


#endif

#include "point.h"
#include "boolean.h"
#include "player.h"

void HPUP (character *P1, int N)
{
	HP(*P1) += N;
}

void HPDOWN (character *P1, character P2)
{
	HP(*P1) -= ATK(P2) - DEF(*P1);
}

boolean isLvlUp (character *P1, int Exp[])
{
	return (EXP(*P1) >= Exp[LVL(*P1)]);
}

void LVLUP (character *P1, int Exp[])
{
	EXP(*P1) -= Exp[LVL(*P1)];
	++LVL(*P1);
}

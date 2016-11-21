#include "point.h"
#include "boolean.h"
#include "player.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */

void HPUP (player *P1, int N)
/*	Mengembalikan HP Pemain sejumlah N */
{
	HP(*P1) += N;
}

void HPDOWN (player *P1, player P2)
/*	Mengurangi HP Pemain akibat serangan Pemain lain */
{
	HP(*P1) -= ATK(P2) - DEF(*P1);
}

boolean isLvlUp (player *P1, int Exp[])
/*  Menentukan apakah Pemain dapat naik ke Level berikutnya
	dengan EXP sekarang */
{
	return (EXP(*P1) >= Exp[LVL(*P1)]);
}

void LVLUP (player *P1, int Exp[])
/*	Menaikkan Level Pemain sebanyak 1 */
{
	EXP(*P1) -= Exp[LVL(*P1)];
	++LVL(*P1);
}

void RestoredHP (player *P1)
/*	Mengembalikan HP Pemain menjadi Maksimum */
{
	HP(*P1) = HPMAX(*P1);
}

boolean isDeath (player *P1)
/*	Mengecek apakah pemain sudah mati atau belum */
{
	return (HP(*P1) <= 0);
}

/* File : player.h */
/* *** Definisi ABSTRACT DATA TYPE PLAYER *** */

#ifndef PLAYER_H
#define PLAYER_H

#include "point.h"
#include "boolean.h"
#include "soqlist.h"

typedef struct {
	POINT posisi;
	char name[200];
	long int HP;
	long int HPMAX;
	int LVL;
	long int EXP;
	long int STR;
	long int DEF;
} player;

/* *** Notasi Akses: Selektor player *** */

#define Posisi(P)	(P).posisi
#define X(P) 		(P).posisi.X
#define Y(P) 		(P).posisi.Y
#define HP(P) 		(P).HP
#define EXP(P) 		(P).EXP
#define STR(P) 		(P).STR
#define DEF(P)		(P).DEF
#define LVL(P) 		(P).LVL
#define NAME(P)		(P).name
#define HPMAX(P)	(P).HPMAX

/* *** DEFINISI PROTOTIPE PRIMITIF PADA PLAYER *** */
void HPUP (player *P1, int N);
/*	Mengembalikan HP Pemain sejumlah N */
void HPDOWN (player *P1, player P2);
/*	Mengurangi HP Pemain akibat serangan Pemain lain */
boolean isLvlUp (player *P1, int Exp[]);
/*  Menentukan apakah Pemain dapat naik ke Level berikutnya
	dengan EXP sekarang */
void LVLUP (player *P1, int Exp[]);
/*	Menaikkan Level Pemain sebanyak 1 */
void RestoredHP (player *P1);
/*	Mengembalikan HP Pemain menjadi Maksimum */
boolean isDeath (player *P1);
/*	Mengecek apakah pemain sudah mati atau belum */


/* *** DEFINISI PROTOTIPE PRIMITIF PADA SAAT MODE BERTARUNG *** */
void bertarungreal(char lawan, char cplayer,player *me, player *enemy);

void bertarungstatus(char lawan, char cplayer, player me, player enemy);

void PrintHeader(player me, player enemy, int round, Queue qenemy, int i,int  r);

void PrintHeaderInBattle(player me, player enemy, int round, Queue qenemy, int i,int  r,int x);

void PrintAndInput(Queue *Q, int *i);

void PrintCommandInBattle(Queue Q, int i);

void RandomAngka(int *i, int *r);

void BattleOn(player *me, player enemy, Stack enemySTR, boolean *win);


#endif

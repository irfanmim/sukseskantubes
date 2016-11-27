/* File : player.h */
/* *** Definisi ABSTRACT DATA TYPE PLAYER *** */

#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "custring.h"
#include "point.h"
#include "soqlist.h"
#include "skilltree.h"

typedef struct {
	POINT posisi;
	char name[200];
	long int HP;
	long int HPMAX;
	int LVL;
	long int EXP;
	long int STR;
	long int DEF;
	SkillTree skilltree;
	int skillpoint;
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
#define STREE(P)	(P).skilltree
#define SPt(P)		(P).skillpoint

void gotoxy(int x, int y);

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
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
boolean isDeath (player P1);
/*	Mengecek apakah pemain sudah mati atau belum */

void ShowStatus(player P1);
// I.S : P1 terdefinisi
// F.S : Menampilkan current status P1 (HP, ATK, DEF)

/* *** PROSES SKILL TREE *** */
void ActivateSkill(player * P1, SkillTree *S);
// I.S : Lvl terdefinisi, skill tree telah diinisialisasi
// F.S : Menambah status karakter sesuai skill yang telah diperoleh
	
void Learn(player *P1, char * name);
// I.S : Skill point >= nol
// F.S : Mempelajari skill baru dalam skill tree

/* *** DAFTAR SKILL *** */

// ATTACK 
void ATKUP(player *P1);

void Slayer(player *P1);

void Berserk(player *P1);

void Terror(player *P1);

// DEFEND
void DEFUP(player *P1);

void TortoiseShell(player *P1); 

void DemonPact(player *P1);

void Guardian(player *P1);

//BATTLE
void bertarungreal(char lawan, char cplayer,player *me, player *enemy);

void bertarungstatus(char lawan, char cplayer, player me, player enemy);

void PrintHeader(player me, player enemy, int round, Queue qenemy, int i,int  r,int lebar, int tinggi);

void PrintHeaderInBattle(player me, player enemy, int round, Queue qenemy, int i,int  r,int x ,int lebar, int tinggi);

void PrintAndInput(Queue *Q, int *i ,int lebar, int tinggi, int *menang);

//tambahan
void PrintWithoutInput(Queue *Q, int *i, int lebar, int tinggi);

void PrintCommandInBattle(Queue Q, int i,int lebar, int tinggi);

void RandomAngka(int *i, int *r);

void BattleOn(player *me, player enemy, Stack enemySTR ,boolean *win, int lebar, int tinggi);

#endif
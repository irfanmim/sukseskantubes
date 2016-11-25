/* File : player.h */
/* *** Definisi ABSTRACT DATA TYPE PLAYER *** */

#ifndef BATTLEANDPLAYER_H
#define BATTLEANDPLAYER_H

#include "point.h"
#include "boolean.h"
#include <time.h>
#include "soqlist.h"
#include <stdio.h>
#include "skilltreef.h"


typedef struct {
	POINT posisi;
	char name[200];
	long int HP;
	long int HPMAX;
	int LVL;
	long int EXP;
	long int ATK;
	long int DEF;
	SkillTree skilltree;
	int skillpoint;
} player;

/******************** STATUS AWAL ********************/
#define InitHPMAX	50
#define InitATK		15
#define InitDEF		10
#define InitLVL		10

/* *** Notasi Akses: Selektor player *** */

#define Posisi(P)	(P).posisi
#define X(P) 		(P).posisi.X
#define Y(P) 		(P).posisi.Y
#define HP(P) 		(P).HP
#define EXP(P) 		(P).EXP
#define ATK(P) 		(P).ATK
#define DEF(P)		(P).DEF
#define LVL(P) 		(P).LVL
#define NAME(P)		(P).name
#define HPMAX(P)	(P).HPMAX
#define STREE(P)	(P).skilltree
#define SPt(P)			(P).skillpoint

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
void InitPlayer(player * P1);
// I.S : Hendak memulai permainan baru
// F.S : Mengisi status dan nama player P1

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
void ATKUP(player *P1);
// I.S : 
// F.S : 
void DEFUP(player *P1);
// I.S :
// F.S : 


/***************************** *** BATTLE *** ******************************/
void bertarungreal(char lawan, char cplayer,player *me, player *enemy);

void bertarungstatus(char lawan, char cplayer, player me, player enemy);

void PrintHeader(player me, player enemy, int round, Queue qenemy, int i,int  r);

void PrintHeaderInBattle(player me, player enemy, int round, Queue qenemy, int i,int  r,int x);

void PrintAndInput(Queue *Q, int *i);

void PrintCommandInBattle(Queue Q, int i);

void RandomAngka(int *i, int *r);

void BattleOn(player *me, player enemy, Stack enemyatk );

#endif

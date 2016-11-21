/* ADT SKILL TREE */
/* Implementasi dengan menggunakan pointer */

#ifndef _SKILLTREE_H
#define _SKILLTREE_H_

/* Modul lain yang digunakan : */
// #include "listrek.h"
#include "boolean.h"
#include <stdio.h>
#include <string.h>
#include "bintree.h"

/* #define Nil NULL */ /* konstanta Nil sesuai pada modul listrek */

/* *** Definisi Type Pohon Biner *** */
/* typedef int infotype; */ /* type infotype sesuai pada modul listrek */
typedef BinTree PohonSkill;
typedef struct {
	char name[50]; // Nama skill
	PohonSkill tree;
	boolean learnt;
} SkillTree;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */ 
/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Name(P) (P).name
#define Learnt(P) (P).learnt
#define Tree(P) (P).tree

/* *** Konstruktor *** */



#endif
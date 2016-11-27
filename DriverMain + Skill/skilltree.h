/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type Infotype, type Addrnode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

#ifndef _SKILLTREE_H
#define _SKILLTREE_H

/* Modul lain yang digunakan : */
#include "boolean.h"

#define Nil NULL

/* *** Definisi Type Pohon Biner *** */
/* typedef int Infotype; */ /* type Infotype sesuai pada modul listrek */
typedef int Infotype;	
typedef struct tnode *Addrnode;
typedef struct tnode { 
	Infotype info;
	Addrnode left;
	Addrnode right;
	boolean learnt;		// Skill sudah dipelajari / belum
	char nama[20];		// Nama skill
} node;

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef Addrnode SkillTree;
 
/* *** PROTOTYPE *** */

/* *** Selektor *** */
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right
#define Learnt(P) (P)->learnt
#define Name(P)	(P)->nama

/* *** Konstruktor *** */
SkillTree Tree (Infotype Akar, SkillTree L, SkillTree R); 
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
void MakeTree (Infotype Akar, SkillTree L, SkillTree R, SkillTree *P);
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
		jika alokasi berhasil. P = Nil jika alokasi gagal. */
		
/* Manajemen Memory */
Addrnode alokNode (Infotype X);
/* Mengirimkan Addrnode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Addrnode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void dealokNode (Addrnode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Addrnode P */

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty (SkillTree P);
/* Mengirimkan true jika P adalah pohon biner kosong */
boolean IsTreeOneElmt (SkillTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
boolean IsUnerLeft (SkillTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
boolean IsUnerRight (SkillTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
boolean IsBiner (SkillTree P);
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/

boolean IsSkewLeft (SkillTree P);
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
boolean IsSkewRight (SkillTree P);
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */

void AddDaunTerkiri (SkillTree *P, Infotype X, char nama[]);
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
void AddDaunTerkanan (SkillTree *P, Infotype X, char nama[]);
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkanan */

void ShowAvailable(SkillTree S) ;
// I.S : S telah diinisiasi
// F.S : Mengirimkan daftar skill yang dapat dipelajari (parentnya telah dipelajari)

void InitSkillTree(SkillTree *S);
// I.S : file daftarskill.txt ada di folder yang sama dengan skilltree.c// F.S : Daftar skill player diinisialisasi, learned = false

void ShowSkill(SkillTree S);
// I.S : Skill Tree P1 terdefinisi
// F.S : Menampilkan seluruh daftar skill yang sudah dan belum dipelajari. Skill yang sudah dipelajari diberi keterangan (learned).

boolean Search(SkillTree S, char nama[]);
// Mengembalikan true jika terdapat skill dengan nama 'nama' di S

void SearchAndLearn(SkillTree *S, char nama[]);
// I.S : S telah diinisialisasi, skill dengan nama 'nama' ada dalam S
// F.S : Learnt skill 'nama' = true

boolean IsLearnt(SkillTree S, char nama[]);
// Mengirimkan true jika skill dengan nama 'nama' telah dipelajari (Learnt = True)
SkillTree SearchTree(SkillTree * S, char nama[]);
// Mengembalikan SkillTree nama 'nama' di S


#endif
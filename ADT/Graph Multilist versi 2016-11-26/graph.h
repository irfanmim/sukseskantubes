#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "graph.h"
#include "peta.h"
#include "point.h"

#define Nil NULL
typedef int infotype;
typedef struct tNode *adrNode;
typedef struct tSuccNode *adrSuccNode;

typedef struct tNode
{
	infotype Id; /* identitas simpul */
	POINT Loc;
	int NPred; /* jumlah busur yang masuk ke simpul = jumlah simpul pred */
	adrSuccNode Trail; /* pointer ke list trailer (simpul successor) */
	adrNode Next;
} Node;

typedef struct tSuccNode
{
	adrNode Succ; /* address simpul successor */
	adrSuccNode Next;
} SuccNode;

typedef struct tGraph
{
	adrNode First;
} Graph;

/* *** Selektor *** */
/* Jika G : Graph, Pn : adrNode, Pt : adrSuccNode, maka:
First(G) = G.First;
Id(Pn) = Pn->Id; NPred(Pn) = Pn->NPred; Trail(Pn) = Pn->Trail; Nxt(Pn) = Pn->Next;
Succ(Pt) = Pt->Succ; Nxt(Pt) = Pt->Next */
#define First(G) (G).First
#define Id(Pn) (Pn)->Id
#define Loc(Pn) (Pn)->Loc
#define NPred(Pn) (Pn)->NPred
#define Trail(Pn) (Pn)->Trail
#define Nxt(Pn) (Pn)->Next
#define Succ(Pt) (Pt)->Succ

/* *** Konstruktor *** */
void CreateGraph (infotype X, POINT T, Graph *L);
/* I.S. Sembarang */
/* F.S. Terbentuk Graph dengan satu simpul dengan Id=X */

/* *** Manajemen Memory List Simpul (Leader) *** */
adrNode AlokNode (infotype X, POINT T);
/* Mengembalikan address hasil alokasi Simpul X. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya menghasilkan P, maka Id(P)=X, */
/* Loc(P)=T, Npred(P)=0, Trail(P)=Nil, dan Nxt(P)=Nil. Jika alokasi gagal, mengembalikan Nil. */

void DealokNode (adrNode P);
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */
/* *** Manajemen Memory List Successor (Trailer) *** */

adrSuccNode AlokSuccNode (adrNode Pn);
/* Mengembalikan address hasil alokasi. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya menghasilkan Pt, maka
   Succ(Pt)=Pn dan Nxt(Pt)=Nil. Jika alokasi gagal, mengembalikan Nil. */

void DealokSuccNode (adrSuccNode P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */

/* *** Fungsi/Prosedur Lain *** */
adrNode SearchNode (Graph G, infotype X, POINT T);
/* mengembalikan address simpul dengan Id=X jika sudah ada pada graph G, Nil jika belum */

adrSuccNode SearchEdge (Graph G, infotype prec, POINT Tprec, infotype succ, POINT Tsucc);
/* mengembalikan address trailer yang menyimpan info busur (prec,succ) jika sudah ada pada
   graph G, Nil jika belum */

void InsertNode (Graph *G, infotype X, POINT T, adrNode *Pn);
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil. */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G. */
/* F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi address simpul X.
   Jika alokasi gagal, G tetap, Pn berisi Nil */

void InsertEdge (Graph *G, infotype prec, POINT Tprec, infotype succ, POINT Tsucc);
/* Menambahkan busur dari prec menuju succ ke dalam G */
/* I.S. G, prec, succ terdefinisi. */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur (prec,succ) ke G.
   Jika simpul prec/succ belum ada pada G, tambahkan simpul tersebut dahulu.
   Jika sudah ada busur (prec,succ) di G, maka G tetap. */

void DeleteNode (Graph *G, infotype X, POINT T);
/* Menghapus simpul X dari G */
/* I.S. G terdefinisi, X terdefinisi dan ada pada G, jumlah simpul pada G lebih dari 1. */
/* F.S. simpul X dan semua busur yang terhubung dengan X dihapus dari G. */

#endif

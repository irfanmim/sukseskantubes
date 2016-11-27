#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "graph.h"
#include "peta.h"
#include "point.h"

/* *** Konstruktor *** */
void CreateGraph (infotype X, POINT T, Graph *L)
/* I.S. Sembarang */ 
/* F.S. Terbentuk Graph dengan satu simpul dengan Id=X */
{
	adrNode P = AlokNode(X,T);
	if (P != Nil)
	{
		First(*L) = P;
	}
}

/* *** Manajemen Memory List Simpul (Leader) *** */
adrNode AlokNode (infotype X, POINT T)
/* Mengembalikan address hasil alokasi Simpul X. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya menghasilkan P, maka Id(P)=X, */
/* NPred(P)=0, Trail(P)=Nil, dan Nxt(P)=Nil. Jika alokasi gagal, mengembalikan Nil. */
{
	adrNode P = (adrNode) malloc (sizeof(Node));
	if (P != Nil)
	{
		Id(P) = X;
		NPred(P) = 0;
		Trail(P) = Nil;
		Nxt(P) = Nil;
		Loc(P) = T;
	}
	return P;
}

void DealokNode (adrNode P)
/* I.S. P terdefinisi; F.S. P dikembalikan ke sistem */
/* *** Manajemen Memory List Successor (Trailer) *** */
{
	free(P);
}

adrSuccNode AlokSuccNode (adrNode Pn)
/* Mengembalikan address hasil alokasi. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya menghasilkan Pt, maka
   Succ(Pt)=Pn dan Nxt(Pt)=Nil. Jika alokasi gagal, mengembalikan Nil. */
{
	adrSuccNode P = (adrSuccNode) malloc (sizeof(SuccNode));
	if (P != Nil)
	{
		Succ(P) = Pn;
		Nxt(P) = Nil;
	}
	return P;
}

void DealokSuccNode (adrSuccNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
{
	free(P);
}

/* *** Fungsi/Prosedur Lain *** */
adrNode SearchNode (Graph G, infotype X, POINT T)
/* mengembalikan address simpul dengan Id=X jika sudah ada pada graph G, Nil jika belum */
{
	adrNode P;
	boolean found = false;
	P = First(G);
	while (!found && P != Nil)
	{
		if (Id(P) == X && EQ(Loc(P),T))
		{
			found = true;
		}
		else
		{
			P = Nxt(P);
		}
	}

	return P;
}

adrSuccNode SearchEdge (Graph G, infotype prec, POINT Tprec, infotype succ, POINT Tsucc)
/* mengembalikan address trailer yang menyimpan info busur (prec,succ) jika sudah ada pada
   graph G, Nil jika belum */
{
	adrNode P = SearchNode(G, prec, Tprec);
	boolean found;
	if (P != Nil)
	{
		found = false;
		adrSuccNode Psucc = Trail(P);
		while (!found && Psucc != Nil)
		{
			if (Id(Succ(Psucc)) == succ && EQ(Loc(Succ(Psucc)),Tsucc))
			{
				found = true;
			}
			else
			{
				Psucc = Nxt(Psucc);
			}
		}
		return Psucc;
	}
	else
	{
		return Nil;
	}
}

void InsertNode (Graph *G, infotype X, POINT T, adrNode *Pn)
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil. */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G. */
/* F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi address simpul X.
   Jika alokasi gagal, G tetap, Pn berisi Nil */
{
	*Pn = AlokNode(X,T);
	if (*Pn != Nil)
	{
		adrNode P = First(*G);
		while (Nxt(P) != Nil)
		{
			P = Nxt(P);
		}
		Nxt(P) = *Pn;
	}
}

void InsertEdge (Graph *G, infotype prec, POINT Tprec, infotype succ, POINT Tsucc)
/* Menambahkan busur dari prec menuju succ ke dalam G */
/* I.S. G, prec, succ terdefinisi. */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur (prec,succ) ke G.
   Jika simpul prec/succ belum ada pada G, tambahkan simpul tersebut dahulu.
   Jika sudah ada busur (prec,succ) di G, maka G tetap. */
{
	adrNode Pr = SearchNode(*G, prec, Tprec), Ps = SearchNode(*G, succ, Tsucc);
	if (Pr == Nil)
	{
		InsertNode(G, prec, Tprec, &Pr);
	}

	if (Ps == Nil)
	{
		InsertNode(G, succ, Tsucc, &Ps);
	}

	if (!SearchEdge(*G, prec, Tprec, succ, Tsucc))
	{
		if (Trail(Pr) != Nil)
		{
			adrSuccNode Pre = Trail(Pr);
			while (Nxt(Pre) != Nil)
			{
				Pre = Nxt(Pre);
			}
			Nxt(Pre) = AlokSuccNode(Ps);
		}
		else
		{
			Trail(Pr) = AlokSuccNode(Ps);
		}
		++NPred(Ps);
	}
}


void DeleteNode (Graph *G, infotype X, POINT T)
/* Menghapus simpul X dari G */
/* I.S. G terdefinisi, X terdefinisi dan ada pada G, jumlah simpul pada G lebih dari 1. */
/* F.S. simpul X dan semua busur yang terhubung dengan X dihapus dari G. */
{
	adrNode P = First(*G), prec = Nil;
	adrSuccNode Ps, Psrec;

	/* KASUS KHUSUS KETIKA First(*G) == X */
	if (Id(P) == X && EQ(Loc(P),T))
	{
		P = Nxt(P);
	}
	Ps = SearchEdge(*G, Id(P), Loc(P), X, T);

	/* PEMROSESAN KASUS AWAL */
	if (Ps != Nil)
	{
		boolean found = false;
		Psrec = Nil;
		Ps = Trail(P);
		while (!found && Ps != Nil)
		{
			if (Id(Succ(Ps)) == X && EQ(Loc(Succ(Ps)),T))
			{
				found = true;
			}
			else
			{
				Psrec = Ps;
				Ps = Nxt(Ps);
			}
		}

		if (found)
		{	
			if (Ps == Trail(P))
			{
				Trail(P) = Nxt(Ps);
			}
			else
			{
				Nxt(Psrec) = Nxt(Ps);
			}
			Nxt(Ps) = Nil;
			DealokSuccNode(Ps);
			--NPred(P);
		}
	}

	/* PEMROSESAN KASUS KASUS BERIKUTNYA */
	P = Nxt(P);
	while (P != Nil)
	{
		if (Id(P) != X)
		{
			Ps = SearchEdge(*G, Id(P), Loc(P), X, T);
			if (Ps != Nil)
			{
				boolean found = false;
				Psrec = Nil;
				Ps = Trail(P);
				while (!found && Ps != Nil)
				{
					if (Id(Succ(Ps)) == X && EQ(Loc(Succ(Ps)),T))
					{
						found = true;
					}
					else
					{
						Psrec = Ps;
						Ps = Nxt(Ps);
					}
				}

				if (found)
				{	
					if (Ps == Trail(P))
					{
						Trail(P) = Nxt(Ps);
					}
					else
					{
						Nxt(Psrec) = Nxt(Ps);
					}
					Nxt(Ps) = Nil;
					DealokSuccNode(Ps);
					--NPred(P);
				}
			}
		}
		P = Nxt(P);
	}

	prec = Nil;
	P = First(*G);

	if (Id(P) == X && EQ(Loc(P),T))
	{
		prec = P;
		First(*G) = Nxt(P);
		DealokNode(P);
	}
	else
	{
		boolean found = false;
		while (P != Nil && !found)
		{
			if (Id(P) != X)
			{
				prec = P;
				P = Nxt(P);
			}
			else
			{
				Nxt(prec) = Nxt(P);
				DealokNode(P);
				found = true;
			}
		}
	}
}

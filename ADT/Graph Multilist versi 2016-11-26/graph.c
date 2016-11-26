#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "graph.h"

/* *** Konstruktor *** */
void CreateGraph (infotype X, Graph *L)
/* I.S. Sembarang */ 
/* F.S. Terbentuk Graph dengan satu simpul dengan Id=X */
{
	adrNode P = AlokNode(X);
	if (P != Nil)
	{
		First(*L) = P;
	}
}

/* *** Manajemen Memory List Simpul (Leader) *** */
adrNode AlokNode (infotype X)
/* Mengembalikan address hasil alokasi Simpul X. */
/* Jika alokasi berhasil, maka address tidak Nil, misalnya menghasilkan P, maka Id(P)=X, */
/* NPred(P)=0, Trail(P)=Nil, dan Next(P)=Nil. Jika alokasi gagal, mengembalikan Nil. */
{
	adrNode P = (adrNode) malloc (sizeof(Node));
	if (P != Nil)
	{
		Id(P) = X;
		NPred(P) = 0;
		Trail(P) = Nil;
		Next(P) = Nil;
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
   Succ(Pt)=Pn dan Next(Pt)=Nil. Jika alokasi gagal, mengembalikan Nil. */
{
	adrSuccNode P = (adrSuccNode) malloc (sizeof(SuccNode));
	if (P != Nil)
	{
		Succ(P) = Pn;
		Next(P) = Nil;
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
adrNode SearchNode (Graph G, infotype X)
/* mengembalikan address simpul dengan Id=X jika sudah ada pada graph G, Nil jika belum */
{
	adrNode P;
	boolean found = false;
	P = First(G);
	while (!found && P != Nil)
	{
		if (Id(P) == X)
		{
			found = true;
		}
		else
		{
			P = Next(P);
		}
	}

	return P;
}

adrSuccNode SearchEdge (Graph G, infotype prec, infotype succ)
/* mengembalikan address trailer yang menyimpan info busur (prec,succ) jika sudah ada pada
   graph G, Nil jika belum */
{
	adrNode P = SearchNode(G, prec);
	boolean found;
	if (P != Nil)
	{
		found = false;
		adrSuccNode Psucc = Trail(P);
		while (!found && Psucc != Nil)
		{
			if (Id(Succ(Psucc)) == succ)
			{
				found = true;
			}
			else
			{
				Psucc = Next(Psucc);
			}
		}
		return Psucc;
	}
	else
	{
		return Nil;
	}
}

void InsertNode (Graph *G, infotype X, adrNode *Pn)
/* Menambahkan simpul X ke dalam graph, jika alokasi X berhasil. */
/* I.S. G terdefinisi, X terdefinisi dan belum ada pada G. */
/* F.S. Jika alokasi berhasil, X menjadi elemen terakhir G, Pn berisi address simpul X.
   Jika alokasi gagal, G tetap, Pn berisi Nil */
{
	*Pn = AlokNode(X);
	if (*Pn != Nil)
	{
		adrNode P = First(*G);
		while (Next(P) != Nil)
		{
			P = Next(P);
		}
		Next(P) = *Pn;
	}
}

void InsertEdge (Graph *G, infotype prec, infotype succ)
/* Menambahkan busur dari prec menuju succ ke dalam G */
/* I.S. G, prec, succ terdefinisi. */
/* F.S. Jika belum ada busur (prec,succ) di G, maka tambahkan busur (prec,succ) ke G.
   Jika simpul prec/succ belum ada pada G, tambahkan simpul tersebut dahulu.
   Jika sudah ada busur (prec,succ) di G, maka G tetap. */
{
	adrNode Pr = SearchNode(*G, prec), Ps = SearchNode(*G, succ);
	if (Pr == Nil)
	{
		InsertNode(G, prec, &Pr);
	}

	if (Ps == Nil)
	{
		InsertNode(G, succ, &Ps);
	}

	if (!SearchEdge(*G, prec, succ))
	{
		if (Trail(Pr) != Nil)
		{
			adrSuccNode Pre = Trail(Pr);
			while (Next(Pre) != Nil)
			{
				Pre = Next(Pre);
			}
			Next(Pre) = AlokSuccNode(Ps);
		}
		else
		{
			Trail(Pr) = AlokSuccNode(Ps);
		}
		++NPred(Ps);
	}
}

void DeleteNode (Graph *G, infotype X)
/* Menghapus simpul X dari G */
/* I.S. G terdefinisi, X terdefinisi dan ada pada G, jumlah simpul pada G lebih dari 1. */
/* F.S. simpul X dan semua busur yang terhubung dengan X dihapus dari G. */
{
	adrNode P = First(*G), prec = Nil;
	adrSuccNode Ps, Psrec;

	/* KASUS KHUSUS KETIKA First(*G) == X */
	if (Id(P) == X)
	{
		P = Next(P);
	}
	Ps = SearchEdge(*G, Id(P), X);

	/* PEMROSESAN KASUS AWAL */
	if (Ps != Nil)
	{
		boolean found = false;
		Psrec = Nil;
		Ps = Trail(P);
		while (!found && Ps != Nil)
		{
			if (Id(Succ(Ps)) == X)
			{
				found = true;
			}
			else
			{
				Psrec = Ps;
				Ps = Next(Ps);
			}
		}

		if (found)
		{	
			if (Ps == Trail(P))
			{
				Trail(P) = Next(Ps);
			}
			else
			{
				Next(Psrec) = Next(Ps);
			}
			Next(Ps) = Nil;
			DealokSuccNode(Ps);
			--NPred(P);
		}
	}

	/* PEMROSESAN KASUS KASUS BERIKUTNYA */
	P = Next(P);
	while (P != Nil)
	{
		if (Id(P) != X)
		{
			Ps = SearchEdge(*G, Id(P), X);
			if (Ps != Nil)
			{
				boolean found = false;
				Psrec = Nil;
				Ps = Trail(P);
				while (!found && Ps != Nil)
				{
					if (Id(Succ(Ps)) == X)
					{
						found = true;
					}
					else
					{
						Psrec = Ps;
						Ps = Next(Ps);
					}
				}

				if (found)
				{	
					if (Ps == Trail(P))
					{
						Trail(P) = Next(Ps);
					}
					else
					{
						Next(Psrec) = Next(Ps);
					}
					Next(Ps) = Nil;
					DealokSuccNode(Ps);
					--NPred(P);
				}
			}
		}
		P = Next(P);
	}

	prec = Nil;
	P = First(*G);

	if (Id(P) == X)
	{
		prec = P;
		First(*G) = Next(P);
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
				P = Next(P);
			}
			else
			{
				Next(prec) = Next(P);
				DealokNode(P);
				found = true;
			}
		}
	}
}

boolean IsPathExist (Graph G, infotype from, infotype to)
/* mengembalikan true jika terdapat jalur (dengan memperhatikan arah dari busur) yang
   menghubungkan “from” ke simpul “to” */
/* Asumsi: from dan to ada pada G dan merupakan simpul yang berbeda */
{
	adrNode F = SearchNode(G, from);
	if (F != Nil)
	{
		if (SearchEdge(G, from, to) == Nil)
		{
			boolean found = false;
			adrSuccNode Fs = Trail(F);
			while (Fs != Nil && !found)
			{
				if (IsPathExist(G, Id(Succ(Fs)), to))
				{
					Fs = Next(Fs);
				}
				else
				{
					found = true;
				}
			}
			return found;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

/* File: garis.h */
/* Tanggal: 28 Agustus 2016 */
/* Definisi ADT GARIS, menggunakan ADT point */

#include "point.h"
#include "garis.h"
#include <stdio.h>
#include <math.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L)
/* I.S. P1 dan P2 terdefinisi */
/* F.S. L terdefinisi dengan L.PAw = P1 dan L.PAkh = P2 */
/* Membentuk sebuah L dari komponen-komponennya */
{
	/* Kamus */
	/* Algoritma */
	PAwal(*L) = P1;
	PAkhir(*L) = P2;
}

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L)
/* I.S. sembarang */
/* F.S. L terdefinisi sebagai GARIS yang valid */
/* Proses : mengulangi membaca dua buah nilai P1 dan P2 sehingga dapat 
   membentuk GARIS yang valid 
   GARIS disebut valid jika titik awal tidak sama dengan titik akhirnya. */
/* Jika pembacaan garis tidak valid, diberikan pesan kesalahan: 
   "Garis tidak valid" */
/* Contoh:
   2 3
   2 3
   Garis tidak valid
   2 3
   3 3 
   --> terbentuk garis L dengan L.PAw = <2,3> dan L.PAkh = <3,3> */
{
	/* Kamus */
	POINT P1, P2;
	/* Algoritma */
	do {
		BacaPOINT(&P1);
		BacaPOINT(&P2);
		if (EQ(P1, P2)) {
			printf("Garis tidak valid\n");
		}
	} while(EQ(P1, P2));
	MakeGARIS(P1, P2, L);
}

void TulisGARIS (GARIS L)
/* I.S. L terdefinisi */
/* F.S. L tertulis di layar dengan format "((x1,y1),(x2,y2))" 
   tanpa tambahan karakter apa pun di depan, di tengah, atau di belakang,
   termasuk spasi dan enter */
{
	/* Kamus */
	/* Algoritma */
	printf("("); TulisPOINT(PAwal(L)); printf(","); TulisPOINT(PAkhir(L));
	printf(")");
}

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L)
/* Menghitung panjang garis L : */
/* Panjang = sqrt((P2.X - P1.X)^2 + (P2.Y - P1.Y)^2) */
{
	/* Kamus */
	/* Algoritma */
	return(sqrt((pow(((Absis(PAkhir(L))) - (Absis(PAwal(L)))), 2)) + (pow(((Ordinat(PAkhir(L))) - (Ordinat(PAwal(L)))), 2))));
}


float Gradien (GARIS L) 
/* Mengembalikan Gradien (m) dari L */
/* Gradien garis yang melalui (x1,y1) dan (x2,y2) adalah: (y2-y1)/(x2-x1) */
/* Prekondisi : x1 != x2 */
{
	/* Kamus */
	/* Algoritma */
	return((Ordinat(PAkhir(L)) - Ordinat(PAwal(L))) / (Absis(PAkhir(L)) - Absis(PAwal(L))));
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY)
/* I.S. L terdefinisi */
/* F.S. L digeser sebesar deltaX ke arah sumbu X dan sebesar deltaY ke arah sumbu Y */
/* Proses : PAw dan PAkh digeser. */
{
	/* Kamus */
	
	/* Algoritma */

	Geser(&(PAwal(*L)), deltaX, deltaY);
	Geser(&(PAkhir(*L)), deltaX, deltaY);
}


/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2)
/* Menghasilkan true jika L1 tegak lurus terhadap L2 */
/* Dua garis saling tegak lurus jika hasil perkalian kedua gradiennya = -1 */
{
	/* Kamus */
	/* Algoritma */
	return((Gradien(L1) * Gradien(L2)) == -1);
}

boolean IsSejajar (GARIS L1, GARIS L2)
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */
{
	/* Kamus */
	/* Algoritma */
	return(Gradien(L1) == Gradien(L2));
}
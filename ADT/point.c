// NIM 				: 13515121
// Nama				: Martin Lutta Putra
// Tanggal			: 31 Agustus 2016
// Topik Praktikum 	: Modularisasi Program
// Deskripsi 		: Body point

/* File: point.h */
/* Tanggal: 28 Agustus 2016 */
/* *** REALISASI ABSTRACT DATA TYPE POINT *** */

#include <math.h>
#include <stdio.h>
#include "custring.h"
#include "point.h"

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (int X, int Y)
/* Membentuk sebuah POINT dari komponen-komponennya */
{
	/* Kamus */
	POINT P;
	
	/* Algoritma */
	Absis(P) = X;
	Ordinat(P) = Y;
	return P; 
}

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT * P)
/* Membaca nilai absis dan ordinat dari keyboard dan membentuk 
   POINT P berdasarkan dari nilai absis dan ordinat tersebut */
/* Komponen X dan Y dibaca dalam 1 baris, dipisahkan 1 buah spasi */
/* Contoh: 1 2 
   akan membentuk POINT <1,2> */
/* I.S. Sembarang */
/* F.S. P terdefinisi */
{
	/* Kamus */
	int x, y;
	
	/* Algoritma */
	scanf("%d %d", &x, &y);
	*P = MakePOINT(x, y);
	
}

void TulisPOINT (POINT P)
/* Nilai P ditulis ke layar dengan format "(X,Y)" 
   tanpa spasi, enter, atau karakter lain di depan, belakang, 
   atau di antaranya */
/* I.S. P terdefinisi */
/* F.S. P tertulis di layar dengan format "(X,Y)" */                
{
	/* Algoritma */
	printf("(%d,%d)", Absis(P), Ordinat(P));
	
}

/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
{
	/* Algoritma */
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2)
/* Mengirimkan true jika P1 tidak sama dengan P2 */
{
	/* Algoritma */
	return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}

/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
/* Menghasilkan true jika P adalah titik origin */
{
	/* Algoritma */
	return ((Absis(P) == 0) && (Ordinat(P) ==0));
}

boolean IsOnSbX (POINT P)
/* Menghasilkan true jika P terletak Pada sumbu X */
{
	/* Algoritma */
	return (Ordinat(P) == 0);
}
	
boolean IsOnSbY (POINT P)
/* Menghasilkan true jika P terletak pada sumbu Y */
{
	/* Algoritma */
	return (Absis(P) == 0);
}

int Kuadran (POINT P)
/* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
/* Prekondisi : P bukan titik origin, */
/*              dan P tidak terletak di salah satu sumbu */
{
	/* Algoritma */
	if (Absis(P) > 0)
		if (Ordinat(P) > 0)
			return (1);
		else
			return (4);
	else
		if (Ordinat(P) > 0)
			return (2);
		else
			return (3);
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P)
/* Mengirim salinan P dengan absis ditambah satu */
{
	return (MakePOINT((Absis(P)+1), Ordinat(P)));
}

POINT NextY (POINT P)
/* Mengirim salinan P dengan ordinat ditambah satu */
{
	return (MakePOINT(Absis(P), (Ordinat(P)+1)));
}

POINT PlusDelta (POINT P, int deltaX, int deltaY)
/* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
{
	/* Algoritma */
	return (MakePOINT((Absis(P) + deltaX), (Ordinat(P) + deltaY)));
}

POINT MirrorOf (POINT P, boolean SbX)
/* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
/* Jika SbX bernilai true, maka dicerminkan terhadap sumbu X */
/* Jika SbX bernilai false, maka dicerminkan terhadap sumbu Y */
{
	/* Algoritma */
	if (SbX == true)
		return (MakePOINT(Absis(P), (Ordinat(P) * (-1))));
	else
		return (MakePOINT((Absis(P) * (-1)), Ordinat(P)));
}

void GerakKiri(POINT *P)
/* 	I.S : P terdefinisi
	F.S : Mengurangi nilai X dari titik P sebesar 1 */
{
	--Absis(*P);
}

void GerakKanan(POINT *P)
/* 	I.S : P terdefinisi
	F.S : Menambah nilai X dari titik P sebesar 1 */
{
	++Absis(*P);
}

void GerakAtas(POINT *P)
/* 	I.S : P terdefinisi
	F.S : Menambah nilai Y dari titik P sebesar 1 */
{
	--Ordinat(*P);
}

void GerakBawah(POINT *P)
/* 	I.S : P terdefinisi
	F.S : Mengurangi nilai X dari titik P sebesar 1 */
{
	++Ordinat(*P);
}

int Jarak0 (POINT P)
/* Menghitung jarak P ke (0,0) */
{
	/* Algoritma */
	return (sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2)));
}

int Panjang (POINT P1, POINT P2)
/* Menghitung panjang garis yang dibentuk P1 dan P2 */
/* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
/* Tuliskan spec fungsi yang lebih tepat. */
{
	/* Algoritma */
	return(sqrt(pow((Absis(P2) - Absis(P1)), 2) + pow((Ordinat(P2) - Ordinat(P1)), 2)));
}

void Geser (POINT *P, int deltaX, int deltaY)
/* I.S. P terdefinisi */
/* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
{
	/* Algoritma */
	Absis(*P) = Absis(*P) + deltaX;
	Ordinat(*P) = Ordinat(*P) + deltaY;
	
}

void GeserKeSbX (POINT *P)
/* I.S. P terdefinisi */
/* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */
/* Proses : P digeser ke sumbu X. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (9,0) */
{
	/* Algoritma */
	Ordinat(*P) = 0;
	
}

void GeserKeSbY (POINT *P)
/* I.S. P terdefinisi*/
/* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
/* Proses : P digeser ke sumbu Y. */
/* Contoh : Jika koordinat semula (9,9), maka menjadi (0,9) */
{
	/* Algoritma */
	Absis(*P) = 0;
	
}

void Mirror (POINT *P, boolean SbX)
/* I.S. P terdefinisi */
/* F.S. P dicerminkan tergantung nilai SbX atau SbY */
/* Jika SbX true maka dicerminkan terhadap sumbu X */
/* Jika SbX false maka dicerminkan terhadap sumbu Y */
{
	/* Algoritma */
	if (SbX == true)
		Ordinat(*P) = Ordinat(*P) * (-1);
	else
		Absis(*P) = Absis(*P) * (-1);
}

void Putar (POINT *P, int Sudut)
/* I.S. P terdefinisi */
/* F.S. P digeser sebesar Sudut derajat dengan sumbu titik (0,0) */
{
	/* Kamus */
	 
	#define PI 3.14159265
	#define degtorad (PI/180)
	
	int x, y;
	
	
	/* Algoritma */
	
	x = Absis(*P);
	y = Ordinat(*P);
		
	Absis(*P) = (x * (cos(Sudut*degtorad))) - (y * (sin(Sudut*degtorad)));
	Ordinat(*P) = (x * (sin(Sudut*degtorad))) + (y * (cos(Sudut*degtorad)));
}

#ifndef PETA_H
#define PETA_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "custring.h"
#include "boolean.h"
#include "point.h"

#define CharMax 1000
#define LBMin 0
#define LBMax 100
#define PNJMin 0
#define PNJMax 100

typedef int indeks;
typedef char ElType;
typedef struct
{
    ElType peta[LBMax+1][PNJMax+1];
    int LebarPeta; /* lebar peta yang terdefinisi */
	int PanjangPeta; /* panjang peta yg terdefinisi */
} PETA;
typedef char str[100];

#define LebarPeta(P) (P).LebarPeta
#define PanjangPeta(P) (P).PanjangPeta
#define Letak(P,i,j) (P).peta[(i)][(j)]

void MakePeta(int LB, int PNJ, PETA *P);

void ReadPeta(PETA *P, str filetxt);

void PrintPeta(PETA P);

void PutarPeta(PETA *P);

void CopyPETA (PETA P, PETA *P1);

void GeneratePeta(PETA *P, int LB, int PNJ);

void BreakdownPeta(PETA P, indeks Y, indeks X);

boolean IsUkuranSama (PETA P1, PETA P2);

boolean IsPetaSama (PETA P1, PETA P2);

boolean isDinding (PETA P, POINT T);

boolean isEnemy (PETA P, POINT T);

boolean isMedicine (PETA P, POINT T);

boolean isPath (PETA P, POINT T);

boolean SearchKolom (PETA P, int i, char CC);

boolean SearchBaris (PETA P, int j, char CC);

POINT FindKolom (PETA P, int i, char CC);
POINT FindBaris (PETA P, int j, char CC);
#endif

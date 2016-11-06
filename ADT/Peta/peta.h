#ifndef PETA_H
#define PETA_H

#include <stdio.h>
#include "string.h"

#define CharMax 1000
#define LBMin 0
#define LBMax 100
#define PNJMin 0
#define PNJMax 100

typedef char ElType;

typedef struct{
    ElType peta[LBMax+1][PNJMax+1];
    int LebarPeta; /* lebar peta yang terdefinisi */
	int PanjangPeta; /* panjang peta yg terdefinisi */
}PETA;

typedef char str[100];
#define LebarPeta(P) (P).LebarPeta
#define PanjangPeta(P) (P).PanjangPeta
#define Posisi(P,i,j) (P).peta[(i)][(j)]

void MakePeta(int LB, int PNJ, PETA *P);

void ReadPeta(FILE *source,PETA *P,str filetxt);

void PrintPeta(PETA P);

void PutarPeta(PETA *P);

#endif // PETA_H

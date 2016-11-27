// NIM 				: 13515121
// Nama				: Martin Lutta Putra
// Tanggal			: 31 Agustus 2016
// Topik Praktikum 	: Modularisasi Program
// Deskripsi 		: Driver point

/* File : mpoint.c */
/* Program MainPoint */
/* Driver ADT Point */

#include <stdio.h>
#include "point.h"
#include <math.h>

int main() {
	/* Kamus */
	POINT P1, P2;
	
	/* Algoritma */
	printf("Input P1 : ");
	BacaPOINT(&P1); printf("\n");
	printf("Nilai P1 : ");
	TulisPOINT(P1); printf("\n");
	
	printf("Input P2 : ");
	BacaPOINT(&P2); printf("\n");
	printf("Nilai P2 : ");
	TulisPOINT(P2); printf("\n");
	
	printf("Nilai EQ, NEQ(P1, P2) : %d %d", EQ(P1, P2), NEQ(P1, P2));  printf("\n");
	printf("IsOrigin(P1) : %d", IsOrigin(P1)); printf("\n");
	printf("IsOnSbX(P1) : %d", IsOnSbX(P1)); printf("\n");
	printf("IsOnSbY(P1) : %d", IsOnSbY(P1)); printf("\n");
	printf("Kuadran(P2) : %d", Kuadran(P2)); printf("\n");
	
	printf("NextX(P1), NexyY(P1) : ");
	TulisPOINT(NextX(P1)); printf(" "); TulisPOINT(NextY(P1)); printf("\n"); 
	printf("PlusDelta(P1, 2, 2) : ");
	TulisPOINT(PlusDelta(P1, 2, 2)); printf("\n");
	printf("Saat ini nilai P1 : "); TulisPOINT(P1); printf("\n");
	printf("Pencerminan P1 terhadap sbX : ");
	TulisPOINT(MirrorOf(P1, true)); printf("\n");
	printf("Jarak P1 ke origin : %.2f", Jarak0(P1)); printf("\n");
	printf("Panjang garis yang dibentuk P1 dan P2 : %.2f", Panjang(P1, P2)); printf("\n");
	
	printf("Saat ini nilai P1 : "); TulisPOINT(P1); printf("\n");
	printf("Setelah digeser sejauh (3, 4) : "); Geser(&P1, 3, 4); TulisPOINT(P1); printf("\n");
	printf("Nilai X P1 diisi 0 : "); GeserKeSbX(&P1); TulisPOINT(P1); printf("\n");
	printf("Nilai Y P1 diisi 0 : "); GeserKeSbY(&P1); TulisPOINT(P1); printf("\n");
	printf("P1 diisi (2, 2) : "); Geser(&P1, 2, 2); TulisPOINT(P1); printf("\n");
	printf("Pencerminan P1 terhadap sbY : "); Mirror(&P1, false); TulisPOINT(P1); printf("\n");
	printf("P1 diputar berlawanan jarum jam 180deg : "); printf("\n");
	Putar(&P1, 180.0); TulisPOINT(P1); printf("\n");
	Putar(&P1, 90.0); TulisPOINT(P1); printf("\n");
	Putar(&P1, 45.0); TulisPOINT(P1); printf("\n");
	
	
	return 0;
}
			   
			   
	
	
	
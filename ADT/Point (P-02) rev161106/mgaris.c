// NIM 				: 13515121
// Nama				: Martin Lutta Putra
// Tanggal			: 31 Agustus 2016
// Topik Praktikum 	: Modularisasi Program
// Deskripsi 		: Driver point

/* File : mpoint.c */
/* Program MainPoint */
/* Driver ADT Point */

#include "point.h"
#include "garis.h"
#include <stdio.h>
#include <math.h>

int main()
{
	/* Kamus */
	GARIS L1, L2;
	
	/* Algoritma */
	printf("Input L1 : ");
	BacaGARIS(&L1); printf("\n");
	printf("Nilai L1 : ");
	TulisGARIS(L1); printf("\n");
	
	printf("Input L2 : ");
	BacaGARIS(&L2); printf("\n");
	printf("Nilai L2 : ");
	TulisGARIS(L2); printf("\n");
	
	printf("Panjang L1 : ");
	printf("%.2f\n", PanjangGARIS(L1));
	printf("Panjang L2 : ");
	printf("%.2f\n", PanjangGARIS(L2));
	
	printf("Gradien L1 : ");
	printf("%2f\n", Gradien(L1));
	printf("Gradien L2 : ");
	printf("%2f\n", Gradien(L2));
	
	printf("L1 digeser sebesar (3, 3). ");
	GeserGARIS(&L1, 3, 3); 
	printf("Nilai L1 sekarang : ");
	TulisGARIS(L1); printf("\n");
	
	printf("Nilai IsTegakLurus, IsSejajar (L1, L2) : %d %d", IsTegakLurus(L1, L2), IsSejajar(L1, L2));
	
	return 0;
}
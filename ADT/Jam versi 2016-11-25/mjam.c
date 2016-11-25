// NIM 				: 13515121
// Nama				: Martin Lutta Putra
// Tanggal			: 31 Agustus 2016
// Topik Praktikum 	: Modularisasi Program
// Deskripsi 		: Driver jam

/* File : mjam.c */
/* Program MainJam */
/* Driver ADT Jam */

#include <stdio.h>
#include "jam.h"

int main() 
{
	/* Kamus */
	JAM J;
	
	/* Algoritma */
	CurrentJam(&J);
	TulisJAM(J); printf("\n");	
	return 0;
}			
	
		
		
	
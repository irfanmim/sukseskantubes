// Nama 		: Martin Lutta Putra
// NIM 			: 13515121
// Tanggal 		: 21 September 2016
// Topik 		: Mesin kata
// Deskripsi	: Body mesinkata.h

#include "mesinkata.h"
#include "mesinkar.h"
#include "boolean.h"
#include <stdio.h>

/* Kamus */ 

/* State Mesin Kata */
boolean EndKata;
Kata CKata;
void IgnoreBlank()
/* Mengabaikan satu atau beberapa BLANK
I.S. : CC sembarang 
F.S. : CC ≠ BLANK atau CC = MARK */
{  /* Kamus Lokal */
	/* Algoritma */
	while ((CC == BLANK) && (CC != MARK)) {
		ADV();
	} /* CC != BLANK or CC = MARK */
}

void STARTKATA()
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
{  /* Kamus Lokal */
	/* Algoritma*/
	START();
	IgnoreBlank();
	if (CC == MARK) {
		EndKata = true;
	} else /* CC != MARK */ {
		EndKata = false;
		SalinKata();
	}
}
	
void ADVKATA()
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
{  /* Kamus Lokal */
	/* Algoritma*/
	IgnoreBlank();
	if (CC == MARK) {
		EndKata = true;
	} else /* CC != MARK */ {
		SalinKata();
		IgnoreBlank();
	}
}
void SalinKata()
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{  /* Kamus Lokal */
	int i = 1; /* inisialisasi */
	/* Algoritma*/
	for (;;) {
		CKata.TabKata[i] = CC;
		ADV();
		if ((CC == MARK) || (CC == BLANK)) {
			break;
		} else {
			i++;
		}
	} /* CC = MARK or CC = BLANK */
	if (i > NMax) {
		CKata.Length = NMax;
	}
	else {
		CKata.Length = i;
	}
	
}